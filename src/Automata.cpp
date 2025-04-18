//"Copyright 2025 Owner"

#include "Automata.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;

Automata::Automata() {
    cash = 0;
    state = STATES::OFF;
    currChoice = -1;
    menu = { "Black Tea", "Green Tea", "Coffee", "Latte"};
    prices = { 100, 200, 300, 250 };
}

void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
        cout << "Automata on wait.\n";
    } else if (state == STATES::WAIT) {
        cout << "Automata already on wait.\n";
    }
}

void Automata::off() {
    if (state == STATES::WAIT) {
        state = STATES::OFF;
        cout << "Automata off.\n";
    }
}

void Automata::getMenu() const {
    for (int i = 0; i < menu.size(); i++) {
        cout << menu[i] << ": " << prices[i] << "\n";
    }
}

void Automata::getState() const {
    switch (state) {
    case STATES::OFF:
        cout << "OFF\n";
        break;
    case STATES::WAIT:
        cout << "WAIT\n";
        break;
    case STATES::ACCEPT:
        cout << "ACCEPT\n";
        break;
    case STATES::CHECK:
        cout << "CHECK\n";
        break;
    case STATES::COOK:
        cout << "COOK\n";
        break;
    }
}

void Automata::coin(int amount) {
    if (state == STATES::WAIT || state == STATES::ACCEPT) {
        state = STATES::ACCEPT;
        cash += amount;
    }
}

void Automata::choice(int itemIndex) {
    if (state == STATES::ACCEPT) {
        state = STATES::CHECK;
        currChoice = itemIndex;
        cout << "Your choise: " << menu[currChoice] <<
            " - " << prices[currChoice]<< " rub\n";
    }
}

void Automata::check() {
    if (state == STATES::CHECK) {
        if (cash >= prices[currChoice]) {
            cout << "Success, start of cooking.\n";
        } else {
            cout << "Not enough money.\n";
        }
    }
}

void Automata::cook() {
    if (state == STATES::CHECK) {
        state = STATES::COOK;
        cout << "Cooking the drink\n";
    }
}

void Automata::cancel() {
    if (state == STATES::CHECK || state == STATES::ACCEPT) {
        state = STATES::WAIT;
        cout << "Order cancelled\n";
        currChoice = -1;
    }
}

void Automata::finish() {
    if (state == STATES::COOK) {
        state = STATES::WAIT;
        cout << "Your drink is ready.\n";
        if (cash > prices[currChoice]) {
            cout << "Change: " << cash - prices[currChoice] << "\n";
        }
        cash = 0;
        currChoice = -1;
    }
}
