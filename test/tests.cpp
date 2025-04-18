// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"
#include <iostream>
#include <string>

std::string captureOutput(std::function<void()> func) {
    std::ostringstream oss;
    std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());
    func();
    std::cout.rdbuf(oldCout);
    return oss.str();
}

TEST(AutomataTest, InitialStateIsOff) {
    Automata a;
    std::string output = captureOutput([&]() { a.getState(); });
    EXPECT_NE(output.find("OFF"), std::string::npos);
}

TEST(AutomataTest, TurnOnAutomata) {
    Automata a;
    a.on();
    std::string output = captureOutput([&]() { a.getState(); });
    EXPECT_NE(output.find("WAIT"), std::string::npos);
}

TEST(AutomataTest, TurnOffAutomataFromWait) {
    Automata a;
    a.on();
    a.off();
    std::string output = captureOutput([&]() { a.getState(); });
    EXPECT_NE(output.find("OFF"), std::string::npos);
}

TEST(AutomataTest, InsertCoinChangesStateToAccept) {
    Automata a;
    a.on();
    a.coin(100);
    std::string output = captureOutput([&]() { a.getState(); });
    EXPECT_NE(output.find("ACCEPT"), std::string::npos);
}

TEST(AutomataTest, CorrectChoiceGoesToCheckState) {
    Automata a;
    a.on();
    a.coin(300);
    a.choice(2); // Coffee
    std::string output = captureOutput([&]() { a.getState(); });
    EXPECT_NE(output.find("CHECK"), std::string::npos);
}

TEST(AutomataTest, CheckSucceedsWithEnoughMoney) {
    Automata a;
    a.on();
    a.coin(300);
    a.choice(2); // Coffee
    std::string output = captureOutput([&]() { a.check(); });
    EXPECT_NE(output.find("Success"), std::string::npos);
}

TEST(AutomataTest, CheckFailsWithInsufficientMoney) {
    Automata a;
    a.on();
    a.coin(100);
    a.choice(2); // Coffee
    std::string output = captureOutput([&]() { a.check(); });
    EXPECT_NE(output.find("Not enough money"), std::string::npos);
}

TEST(AutomataTest, CancelResetsToWait) {
    Automata a;
    a.on();
    a.coin(200);
    a.cancel();
    std::string output = captureOutput([&]() { a.getState(); });
    EXPECT_NE(output.find("WAIT"), std::string::npos);
}

TEST(AutomataTest, CookSetsStateToCook) {
    Automata a;
    a.on();
    a.coin(300);
    a.choice(2); // Coffee
    a.check();
    a.cook();
    std::string output = captureOutput([&]() { a.getState(); });
    EXPECT_NE(output.find("COOK"), std::string::npos);
}

TEST(AutomataTest, FinishResetsStateAndGivesChange) {
    Automata a;
    a.on();
    a.coin(400);
    a.choice(2); // Coffee
    a.check();
    a.cook();
    std::string output = captureOutput([&]() { a.finish(); });
    EXPECT_NE(output.find("Your drink is ready"), std::string::npos);
    EXPECT_NE(output.find("Change: 100"), std::string::npos);
}
