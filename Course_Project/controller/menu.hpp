#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QApplication>
#include "database.hpp"
#include "user.hpp"

class Menu : public QMainWindow {
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);

private slots:
    void displayMainMenu();
    void displayAuthMenu();         // Menu with Sign In, Sign Up, Continue as Guest
    void displayPlayMenu();         // Menu to choose difficulty
    void displayRulesMenu();
    void displaySignInMenu();
    void displaySignUpMenu();

private:
    QWidget *centralWidget;
    QVBoxLayout *layout;

    void clearLayout();
};


