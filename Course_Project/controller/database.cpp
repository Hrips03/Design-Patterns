#include "database.hpp"
#include <iostream>

SQLiteDB* SQLiteDB::instance = nullptr;

SQLiteDB::SQLiteDB(const std::string& db_name) {
    if (sqlite3_open(db_name.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
        db = nullptr;
        // Attempt to open a new one, or exit if you must
    } else {
        std::cout << "Database opened successfully." << std::endl;  // Add a success message
    }
    initialize();
}


SQLiteDB::~SQLiteDB() {
    if (db) sqlite3_close(db);
}

SQLiteDB* SQLiteDB::getInstance(const std::string& db_name) {
    if (instance == nullptr) {
        instance = new SQLiteDB(db_name);
    }
    return instance;
}

bool SQLiteDB::initialize() {
    const char* users_table = R"(
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            username TEXT UNIQUE NOT NULL,
            password TEXT NOT NULL
        );
    )";

    const char* scores_table = R"(
        CREATE TABLE IF NOT EXISTS scores (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            user_id INTEGER NOT NULL,
            difficulty TEXT CHECK(difficulty IN ('Easy', 'Medium', 'Hard')),
            best_score TEXT DEFAULT '00:00',
            FOREIGN KEY (user_id) REFERENCES users (id)
        );
    )";

    char* error_message = nullptr;
    if (sqlite3_exec(db, users_table, nullptr, nullptr, &error_message) != SQLITE_OK) {
        std::cerr << "Error creating users table: " << error_message << std::endl;
        sqlite3_free(error_message);
        return false;
    }

    if (sqlite3_exec(db, scores_table, nullptr, nullptr, &error_message) != SQLITE_OK) {
        std::cerr << "Error creating scores table: " << error_message << std::endl;
        sqlite3_free(error_message);
        return false;
    }

    return true;
}

bool SQLiteDB::addUser(const std::string& username, const std::string& password) {
    const char* insert_user = "INSERT INTO users (username, password) VALUES (?, ?);";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, insert_user, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error preparing insert statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Error adding user: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);

    // Insert default scores for the user (Easy, Medium, Hard)
    int user_id = sqlite3_last_insert_rowid(db);
    const char* insert_scores = R"(
        INSERT INTO scores (user_id, difficulty) VALUES
        (?, 'Easy'), (?, 'Medium'), (?, 'Hard');
    )";

    if (sqlite3_prepare_v2(db, insert_scores, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error preparing score statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    for (int i = 1; i <= 3; ++i) {
        sqlite3_bind_int(stmt, i, user_id);
    }

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Error adding default scores: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

bool SQLiteDB::checkCredentials(const std::string& username, const std::string& password) {
    const char* check_credentials = R"(
        SELECT COUNT(*) FROM users WHERE username = ? AND password = ?;
    )";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, check_credentials, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error preparing check credentials statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);

    int count = 0;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        count = sqlite3_column_int(stmt, 0);
    }

    sqlite3_finalize(stmt);
    return count > 0;
}

bool SQLiteDB::updateBestScore(const std::string& username, const std::string& difficulty, const std::string& best_score) {
    const char* update_score = R"(
        UPDATE scores
        SET best_score = ?
        WHERE user_id = (SELECT id FROM users WHERE username = ?) AND difficulty = ?;
    )";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, update_score, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Error preparing update statement: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, best_score.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, difficulty.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Error updating score: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}
