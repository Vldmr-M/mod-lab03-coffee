//"Copyright 2025 Owner"
#pragma once
#include <string>
#include <vector>

enum class STATES {
    OFF = 'OFF',
    WAIT='WAIT',
    ACCEPT='ACPT',
    CHECK='CHCK',
    COOK = 'COOK'
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
    STATES getState() const;
    void check();
    void cancel();
    void cook();
    void finish();
};
