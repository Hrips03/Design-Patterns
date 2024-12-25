#include "MenuController.hpp"

std::vector<int> MenuController::setMenu()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "Minesweeper Menu");

    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    // Get window dimensions
    sf::Vector2u windowSize = window.getSize();

    // Calculate centered position
    int posX = (desktopMode.width - windowSize.x) / 2;
    int posY = (desktopMode.height - windowSize.y) / 2;

    // Set the window position
    window.setPosition(sf::Vector2i(posX, posY));
    if (windowSize.x == 0 || windowSize.y == 0)
    {
        std::cerr << "Invalid window size: " << windowSize.x << "x" << windowSize.y << std::endl;
        window.close();
        return {}; // Or handle this case more gracefully
    }

    // Create menus
    Menu mainMenu({"Play", "Rules", "Exit"}, 600, 400);
    Menu loginMenu({"Sign in", "Sign Up", "Continue as Guest", "Back"}, 600, 400);
    Menu playMenu({"Easy", "Medium", "Hard", "Back"}, 600, 400);
    Menu rulesMenu({"\n\nBack"}, 600, 400);
    sf::Text rulesText;
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cerr << "Failed to load font!" << std::endl;
        exit(1);
    }

    rulesText.setFont(font);
    rulesText.setCharacterSize(20);
    rulesText.setFillColor(sf::Color::White);
    rulesText.setString("                                       Rules\n\nAll non-mine cells must be opened without opening a mine.");
    rulesText.setPosition(50, 50);
    // Create input boxes for sign-in
    InputBox usernameBox(200, 100, 200, 30, "Username");
    InputBox passwordBox(200, 150, 200, 30, "Password", true);

    // Input boxes for sign-up
    InputBox signUpUsernameBox(200, 100, 200, 30, "Username");
    InputBox signUpPasswordBox(200, 150, 200, 30, "Password", true);
    InputBox confirmPasswordBox(200, 200, 200, 30, "Repeat Password", true);

    // Buttons for sign-in and sign-up
    Menu signInButtons({"Sign In", "Back"}, 600, 400); // Sign In
    Menu signUpButtons({"Sign Up", "Back"}, 600, 400); // Sign Up

    // Adjust button positions
    signInButtons.menuOptions[0].setPosition(200, 200); // "Sign In" button
    signInButtons.menuOptions[1].setPosition(200, 250); // "Back" button
    signUpButtons.menuOptions[0].setPosition(200, 250); // "Sign Up" button
    signUpButtons.menuOptions[1].setPosition(200, 300); // Back button

    // Menu state
    enum class MenuState
    {
        MAIN,
        RULES,
        LOGIN,
        SIGNIN,
        SIGNUP,
        DIFFICULTY
    } currentState = MenuState::MAIN;

    InputBox *focusedBox = nullptr;  // Track which input box is focused
    bool isValidCredentials = false; // Mock check for valid credentials
    std::vector<int> dimensions = {0, 0, 0};
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                switch (currentState)
                {
                case MenuState::LOGIN:
                    loginMenu.highlightOption(mousePos);
                    break;
                case MenuState::SIGNIN:
                    signInButtons.highlightOption(mousePos);
                    break;
                case MenuState::SIGNUP:
                    signUpButtons.highlightOption(mousePos);
                    break;
                case MenuState::MAIN:
                    mainMenu.highlightOption(mousePos);
                    break;
                case MenuState::RULES:
                    rulesMenu.highlightOption(mousePos);
                    // window.draw(rulesText);
                    break;
                case MenuState::DIFFICULTY:
                    playMenu.highlightOption(mousePos);
                    break;
                default:
                    break;
                }
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                switch (currentState)
                {
                case MenuState::MAIN:
                    switch (mainMenu.getOptionClicked(mousePos))
                    {
                    case 0: // Play
                        currentState = MenuState::LOGIN;
                        break;
                    case 1: // Rules
                        currentState = MenuState::RULES;
                        break;
                    case 2: // Exit
                        window.close();
                        break;
                    }
                    break;

                case MenuState::LOGIN:
                    switch (loginMenu.getOptionClicked(mousePos))
                    {
                    case 0: // Play
                        currentState = MenuState::SIGNIN;
                        break;
                    case 1: // Rules
                        currentState = MenuState::SIGNUP;
                        break;
                    case 2: // Exit
                        currentState = MenuState::DIFFICULTY;
                        break;
                    case 3: // Exit
                        currentState = MenuState::MAIN;
                        break;
                    }
                    break;
                case MenuState::SIGNUP:
                    if (signUpButtons.getOptionClicked(mousePos) == 0)
                    { // Sign Up
                      // Validate credentials (mock validation)
                        SQLiteDB *db = SQLiteDB::getInstance();
                        if (db->addUser(signUpUsernameBox.getInputText(), signUpPasswordBox.getInputText()))
                        {
                            m_user = new User(signUpUsernameBox.getInputText(), signUpPasswordBox.getInputText());
                            std::cout << "Account created successfully! Welcome, " << m_user->getUsername() << ".\n";

                            // confirmPasswordBox.getInputText()
                            isValidCredentials = true;
                            currentState = MenuState::DIFFICULTY;
                        }
                        else
                        {
                            std::cout << "Invalid credentials.\n";
                        }
                    }
                    else if (signUpButtons.getOptionClicked(mousePos) == 1)
                    { // Back
                        currentState = MenuState::LOGIN;
                    }
                    break;

                case MenuState::SIGNIN:
                    if (signInButtons.getOptionClicked(mousePos) == 0)
                    { // Sign In
                        // Validate credentials (mock validation)
                        SQLiteDB *db = SQLiteDB::getInstance();
                        if (db->checkCredentials(usernameBox.getInputText(), passwordBox.getInputText()))
                        {
                            m_user = new User(usernameBox.getInputText(), passwordBox.getInputText());
                            std::cout << "Login successful! Welcome, " << m_user->getUsername() << ".\n";
                            isValidCredentials = true;
                            currentState = MenuState::DIFFICULTY;
                        }
                        else
                        {
                            std::cout << "Invalid credentials.\n";
                        }
                    }
                    else if (signInButtons.getOptionClicked(mousePos) == 1)
                    { // Back
                        currentState = MenuState::LOGIN;
                    }
                    break;
                case MenuState::RULES:
                    switch (rulesMenu.getOptionClicked(mousePos))
                    {
                    case 0: // Play
                        currentState = MenuState::MAIN;
                        break;
                    }
                    break;
                case MenuState::DIFFICULTY:
                    switch (playMenu.getOptionClicked(mousePos))
                    {
                    case 0: // Easy
                        dimensions = {9, 9, 10};
                        m_difficulty = "Easy";
                        std::cout << "Easy difficulty selected.\n";
                        break;
                    case 1: // Medium
                        dimensions = {16, 16, 40};
                        m_difficulty = "Medium";
                        std::cout << "Medium difficulty selected.\n";
                        break;
                    case 2: // Hard
                        dimensions = {16, 30, 99};
                        m_difficulty = "Hard";
                        std::cout << "Hard difficulty selected.\n";
                        break;
                    case 3: // Back
                        currentState = MenuState::LOGIN;
                        break;
                    }
                    break;
                }
            }

            // Handle text input for focused input box
            if (event.type == sf::Event::TextEntered)
            {
                if (focusedBox)
                {
                    focusedBox->handleInput(event);
                }
            }

            // Handle mouse clicks to set focus on input boxes
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && currentState == MenuState::SIGNIN)
            {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                // Ensure only one input box is focused at a time
                if (usernameBox.getGlobalBounds().contains(mousePos))
                {
                    usernameBox.setFocus(true);
                    passwordBox.setFocus(false);
                    focusedBox = &usernameBox;
                }
                else if (passwordBox.getGlobalBounds().contains(mousePos))
                {
                    passwordBox.setFocus(true);
                    usernameBox.setFocus(false);
                    focusedBox = &passwordBox;
                }
            }

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && currentState == MenuState::SIGNUP)
            {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                // Ensure only one input box is focused at a time
                if (signUpUsernameBox.getGlobalBounds().contains(mousePos))
                {
                    signUpUsernameBox.setFocus(true);
                    signUpPasswordBox.setFocus(false);
                    confirmPasswordBox.setFocus(false);
                    focusedBox = &signUpUsernameBox;
                }
                else if (signUpPasswordBox.getGlobalBounds().contains(mousePos))
                {
                    signUpPasswordBox.setFocus(true);
                    signUpUsernameBox.setFocus(false);
                    confirmPasswordBox.setFocus(false);
                    focusedBox = &signUpPasswordBox;
                }
                else if (confirmPasswordBox.getGlobalBounds().contains(mousePos))
                {
                    confirmPasswordBox.setFocus(true);
                    signUpUsernameBox.setFocus(false);
                    signUpPasswordBox.setFocus(false);
                    focusedBox = &confirmPasswordBox;
                }
            }
        }
        // Draw current menu
        window.clear(sf::Color(50, 50, 150));
        switch (currentState)
        {
        case MenuState::MAIN:
            mainMenu.draw(window);
            break;
        case MenuState::LOGIN:
            loginMenu.draw(window);
            break;
        case MenuState::SIGNIN:
            usernameBox.draw(window);
            passwordBox.draw(window);
            signInButtons.draw(window);
            break;
        case MenuState::SIGNUP:
            signUpUsernameBox.draw(window);
            signUpPasswordBox.draw(window);
            confirmPasswordBox.draw(window);
            signUpButtons.draw(window);
            break;
        case MenuState::DIFFICULTY:
            playMenu.draw(window);
            break;
        case MenuState::RULES:
            rulesMenu.draw(window);
            window.draw(rulesText);
            break;
        default:
            break;
        }
        window.display();

        if (dimensions[0] != 0)
        {
            window.close();
        }
    }
    getUserInfo();
    return dimensions;
}

std::vector<std::string> MenuController::getUserInfo()
{
    std::vector<std::string> userInfo;
    if (!m_user)
    {
        userInfo = {""};
        std::cerr << "Error: User is not initialized.\n";
    }
    else
    {
        userInfo = {m_user->getUsername(),m_difficulty, m_user->getBestScore(m_difficulty)};
    }
    return userInfo;
}
