#include "user.hpp"
#include <iostream>

// Constructor
User::User(const std::string& username, const std::string& password)
    : username(username), password(password) {
    // Initialize scores with default value "00:00"
    bestScores["Easy"] = "00:00";
    bestScores["Medium"] = "00:00";
    bestScores["Hard"] = "00:00";
}

// Getters
const std::string& User::getUsername() const {
    return username;
}


std::string User::getBestScore(const std::string& difficulty) const {
    auto it = bestScores.find(difficulty);
    if (it != bestScores.end()) {
        return it->second;
    }
    return "00:00"; // Default score
}

// Setters
void User::setBestScore(const std::string& difficulty, const std::string& score) {
    if (bestScores.find(difficulty) != bestScores.end()) {
        bestScores[difficulty] = score;
    } else {
        std::cerr << "Invalid difficulty: " << difficulty << std::endl;
    }
}


