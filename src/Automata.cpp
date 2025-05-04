//"Copyright 2025 Owner"

#include "Automata.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout;

Automata::Automata() {
    cash = 0;
    state = STATES::OFF;
    currChoice = -1;
    menu = { "Черный чай", "Зеленый чай", "Кофе", "Латте"};
    prices = { 100, 200, 300, 250 };
}

void Automata::on() {
    if (state == STATES::OFF) {
        state = STATES::WAIT;
        cout << "Автомат в  режиме ожидания.\n";
    } else {
        cout << "Ошибка.\n";
    }
}

void Automata::off() {
    if (state == STATES::WAIT) {
        state = STATES::OFF;
        cout << "Автомат выключен.\n";
    } else {
        cout << "Ошибка.\n";
    }
}

void Automata::coin(int sum) {
    if (state == STATES::WAIT || state == STATES::ACCEPT) {
        state = STATES::ACCEPT;
        cash += sum;
        cout << "Текущая сумма: " << cash << ".\n";
    } else {
        cout << "Ошибка.\n";
    }
}

void Automata::getMenu() const {
    cout << "Меню:\n";
    for (int i = 0; i < menu.size(); i++) {
        cout << menu[i] << ": " << prices[i] << "\n";
    }
}

STATES Automata::getState() const {
    return state;
}

void Automata::choice(int itemIndex) {
    if (state == STATES::ACCEPT) {
        state = STATES::CHECK;
        currChoice = itemIndex;
        cout << "Твой выбор: " << menu[currChoice] <<
            " - " << prices[currChoice] << " руб.\n";
    } else {
        cout << "Ошибка.\n";
    }
}

void Automata::check() {
    if (state == STATES::CHECK) {
        if (cash >= prices[currChoice]) {
            cout << "Успешно, начинаем готовить.\n"<<
            "Ваша сдача: " << cash - prices[currChoice] << "руб.\n";
        } else {
            cout << "Недостаточно средств.\n";
        }
    } else {
        cout << "Ошибка.\n";
    }
}

void Automata::cancel() {
    if (state == STATES::CHECK || state == STATES::ACCEPT) {
        cout << "Заказ отменен. Возврат денег - " << cash << "руб.\n";
        cash = 0;
        state = STATES::WAIT;
        currChoice =-1;
    } else {
        cout << "Ошибка.\n";
    }
}

void Automata::cook() {
    if (state == STATES::CHECK) {
        state = STATES::COOK;
        cout << "В процессе готовки.\n";
    } else {
        cout << "Ошибка.\n";
    }
}

void Automata::finish() {
    if (state == STATES::COOK) {
        state = STATES::WAIT;
        cout << "Заказ готов.\n";

        cash = 0;
        currChoice = -1;
    } else {
        cout << "Ошибка.\n";
    }
}
