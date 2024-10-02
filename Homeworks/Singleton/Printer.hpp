#pragma once
#include <iostream>
#include <memory>

class Printer
{
    Printer();

    Printer(const Printer &) = delete;
    Printer &operator=(const Printer &) = delete;

    Printer(const Printer &&) = delete;
    Printer &&operator=(const Printer &&) = delete;

    static std::shared_ptr<Printer> instance;

public:
    static std::shared_ptr<Printer> getInstance();
};

