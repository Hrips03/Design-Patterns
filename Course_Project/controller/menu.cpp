#include "menu.hpp"

Menu::Menu(QWidget *parent) : QMainWindow(parent), centralWidget(new QWidget(this)), layout(new QVBoxLayout()) {
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    displayMainMenu();
}

void Menu::clearLayout() {
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (item->widget()) {
            item->widget()->deleteLater();
        }
        delete item;
    }
}

void Menu::displayMainMenu() {
    clearLayout();

    QLabel *welcomeLabel = new QLabel("Welcome to the Main Menu! Please make a choice.", this);
    welcomeLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(welcomeLabel);

    QPushButton *playButton = new QPushButton("Play", this);
    QPushButton *rulesButton = new QPushButton("Rules", this);
    QPushButton *exitButton = new QPushButton("Exit", this);

    layout->addWidget(playButton);
    layout->addWidget(rulesButton);
    layout->addWidget(exitButton);

    connect(playButton, &QPushButton::clicked, this, &Menu::displayAuthMenu);
    connect(rulesButton, &QPushButton::clicked, this, &Menu::displayRulesMenu);
    connect(exitButton, &QPushButton::clicked, qApp, &QApplication::quit);
}

void Menu::displayAuthMenu() {
    clearLayout();

    QLabel *authLabel = new QLabel("Login Menu:", this);
    authLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(authLabel);

    QPushButton *signInButton = new QPushButton("Sign In", this);
    QPushButton *signUpButton = new QPushButton("Sign Up", this);
    QPushButton *guestButton = new QPushButton("Continue as Guest", this);
    QPushButton *backButton = new QPushButton("Back", this);

    layout->addWidget(signInButton);
    layout->addWidget(signUpButton);
    layout->addWidget(guestButton);
    layout->addWidget(backButton);

    connect(signInButton, &QPushButton::clicked, this, &Menu::displaySignInMenu);
    connect(signUpButton, &QPushButton::clicked, this, &Menu::displaySignUpMenu);
    connect(guestButton, &QPushButton::clicked, this, &Menu::displayPlayMenu);
    connect(backButton, &QPushButton::clicked, this, &Menu::displayMainMenu);
}

void Menu::displayPlayMenu() {
    clearLayout();

    QLabel *playLabel = new QLabel("Choose Difficulty:", this);
    playLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(playLabel);

    QPushButton *easyButton = new QPushButton("Easy", this);
    QPushButton *mediumButton = new QPushButton("Medium", this);
    QPushButton *hardButton = new QPushButton("Hard", this);
    QPushButton *backButton = new QPushButton("Back", this);

    layout->addWidget(easyButton);
    layout->addWidget(mediumButton);
    layout->addWidget(hardButton);
    layout->addWidget(backButton);

    connect(backButton, &QPushButton::clicked, this, &Menu::displayAuthMenu);

    // Connect difficulty buttons to actions (here we just display a message)
    connect(easyButton, &QPushButton::clicked, [=]() {
        QMessageBox::information(this, "Difficulty", "You chose Easy!");
    });
    connect(mediumButton, &QPushButton::clicked, [=]() {
        QMessageBox::information(this, "Difficulty", "You chose Medium!");
    });
    connect(hardButton, &QPushButton::clicked, [=]() {
        QMessageBox::information(this, "Difficulty", "You chose Hard!");
    });
}

void Menu::displayRulesMenu() {
    clearLayout();

    QLabel *rulesLabel = new QLabel("Rules:\n\nAll non-mine cells must be opened without opening a mine.", this);
    rulesLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(rulesLabel);

    QPushButton *backButton = new QPushButton("Back", this);
    layout->addWidget(backButton);

    connect(backButton, &QPushButton::clicked, this, &Menu::displayMainMenu);
}

void Menu::displaySignInMenu() {
    clearLayout();

    QLabel *signInLabel = new QLabel("Sign In", this);
    signInLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(signInLabel);

    QLineEdit *usernameInput = new QLineEdit(this);
    usernameInput->setPlaceholderText("Enter your username");
    QLineEdit *passwordInput = new QLineEdit(this);
    passwordInput->setPlaceholderText("Enter your password");
    passwordInput->setEchoMode(QLineEdit::Password);

    layout->addWidget(usernameInput);
    layout->addWidget(passwordInput);

    QPushButton *loginButton = new QPushButton("Login", this);
    QPushButton *backButton = new QPushButton("Back", this);

    layout->addWidget(loginButton);
    layout->addWidget(backButton);

    connect(loginButton, &QPushButton::clicked, [=]() {
        QString username = usernameInput->text().trimmed();
        QString password = passwordInput->text();

        if (username.isEmpty() || password.isEmpty()) {
            QMessageBox::warning(this, "Login", "Username and password cannot be empty.");
            return;
        }

        SQLiteDB* db = SQLiteDB::getInstance("G:/Hripsime/Education/UNI/4rd_kurs/Design-Patterns/Course_Project/minsweeper.db");
        if (db->checkCredentials(username.toStdString(), password.toStdString())) {
            QMessageBox::information(this, "Login", "Login successful! Welcome, " + username + ".");
            displayPlayMenu();
        } else {
            QMessageBox::warning(this, "Login", "Invalid username or password.");
        }
    });

    connect(backButton, &QPushButton::clicked, this, &Menu::displayAuthMenu);
}

void Menu::displaySignUpMenu() {
    clearLayout();

    QLabel *signUpLabel = new QLabel("Sign Up", this);
    signUpLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(signUpLabel);

    QLineEdit *usernameInput = new QLineEdit(this);
    usernameInput->setPlaceholderText("Choose a username");
    QLineEdit *passwordInput = new QLineEdit(this);
    passwordInput->setPlaceholderText("Choose a password");
    passwordInput->setEchoMode(QLineEdit::Password);
    QLineEdit *confirmPasswordInput = new QLineEdit(this);
    confirmPasswordInput->setPlaceholderText("Confirm your password");
    confirmPasswordInput->setEchoMode(QLineEdit::Password);

    layout->addWidget(usernameInput);
    layout->addWidget(passwordInput);
    layout->addWidget(confirmPasswordInput);

    QPushButton *registerButton = new QPushButton("Register", this);
    QPushButton *backButton = new QPushButton("Back", this);

    layout->addWidget(registerButton);
    layout->addWidget(backButton);

    connect(registerButton, &QPushButton::clicked, [=]() {
        QString username = usernameInput->text().trimmed();
        QString password = passwordInput->text();
        QString confirmPassword = confirmPasswordInput->text();

        if (username.isEmpty() || password.isEmpty()) {
            QMessageBox::warning(this, "Sign Up", "Username and password cannot be empty.");
            return;
        }

        if (password != confirmPassword) {
            QMessageBox::warning(this, "Sign Up", "Passwords do not match.");
            return;
        }

        SQLiteDB* db = SQLiteDB::getInstance("G:/Hripsime/Education/UNI/4rd_kurs/Design-Patterns/Course_Project/minsweeper.db");
        if (db->addUser(username.toStdString(), password.toStdString())) {
            QMessageBox::information(this, "Sign Up", "Account created successfully! Welcome, " + username + ".");
            displayPlayMenu();
        } else {
            QMessageBox::warning(this, "Sign Up", "Username already exists. Please choose a different username.");
        }
    });

    connect(backButton, &QPushButton::clicked, this, &Menu::displayAuthMenu);
}

