#pragma once
#include <string>
#include <map>

class User
{
    std::string username;
    std::string password;
    std::map<std::string, std::string> bestScores;

public:
    User(const std::string &username, const std::string &password);
    const std::string &getUsername() const;
    std::string getBestScore(const std::string &difficulty) const;
    void setBestScore(const std::string &difficulty, const std::string &score);
};
