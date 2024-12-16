#include "../controller/menu.hpp"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Initialize the database
    SQLiteDB* db = SQLiteDB::getInstance("G:/Hripsime/Education/UNI/4rd_kurs/Design-Patterns/Course_Project/minsweeper.db");  // Path to your SQLite DB

    // Ensure the database is properly initialized
    if (!db) {
        std::cerr << "Failed to initialize database." << std::endl;
        return -1;  // Exit if the database fails to initialize
    }

    // Create and display the menu
    Menu menu;
    menu.show();

    return app.exec();
}
