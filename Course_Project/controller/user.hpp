#pragma once
#include <string>
#include <map>

class User {
private:
    std::string username;
    std::string password;
    std::map<std::string, std::string> bestScores; // Maps difficulty levels to scores

public:
    // Constructor
    User(const std::string& username, const std::string& password);

    // Getters
    const std::string& getUsername() const;
    std::string getBestScore(const std::string& difficulty) const;

    // Setters
    void setBestScore(const std::string& difficulty, const std::string& score);

    // Utility functions
   
};
