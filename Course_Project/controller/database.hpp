#pragma once
#include <sqlite3.h>
#include <string>

class SQLiteDB {
private:
    sqlite3* db;
    static SQLiteDB* instance;

    // Private constructor to implement singleton pattern
    SQLiteDB(const std::string& db_name);

    // Initialize the database schema
    bool initialize();

public:
    ~SQLiteDB();

    // Get the singleton instance of the database
    static SQLiteDB* getInstance(const std::string& db_name = "G:/Hripsime/Education/UNI/4rd_kurs/Design-Patterns/Course_Project/minsweeper.db");

    // Add a new user
    bool addUser(const std::string& username, const std::string& password);

    // Check user credentials
    bool checkCredentials(const std::string& username, const std::string& password);

    // Update the best score for a user
    bool updateBestScore(const std::string& username, const std::string& difficulty, const std::string& best_score);
};


