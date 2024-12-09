#pragma once
#include <sqlite3.h>
#include <string>
#include <iostream>
#include <memory>

class SQLiteDB {
    sqlite3* db;
    static SQLiteDB* instance; 
    SQLiteDB(const std::string& db_name);

public:
    SQLiteDB(const SQLiteDB&) = delete;
    SQLiteDB& operator=(const SQLiteDB&) = delete;
    ~SQLiteDB();
    static SQLiteDB* getInstance(const std::string& db_name = "minesweeper.db");

    bool initialize();
    bool addUser(const std::string& username, const std::string& password);
    bool checkCredentials(const std::string& username, const std::string& password);
    bool updateBestScore(const std::string& username, const std::string& difficulty, const std::string& best_score);
    void getScores(const std::string& username);
};
