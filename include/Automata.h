//"Copyright 2025 Owner"
#pragma once
#include <string>
#include <vector>

enum class STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
 private:
    int cash;
    int currChoice;
    STATES state;
    std::vector<std::string> menu;
    std::vector<int> prices;

 public:
    Automata();
    void on();
    void off();
    void coin(int amount);
    void choice(int itemIndex);
    void getMenu() const;
    void getState() const;
    void check();
    void cancel();
    void cook();
    void finish();
};
