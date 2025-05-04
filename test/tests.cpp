// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"
#include <iostream>
#include <string>

TEST(AutomataTest, PowerOn) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

TEST(AutomataTest, DoublePowerOn) {
    Automata a;
    a.on();
    testing::internal::CaptureStdout();
    a.on();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Ошибка"), std::string::npos);
}

TEST(AutomataTest, PowerOff) {
    Automata a;
    a.on();
    a.off();
    EXPECT_EQ(a.getState(), STATES::OFF);
}

TEST(AutomataTest, InsertCoinCorrectState) {
    Automata a;
    a.on();
    a.coin(100);
    EXPECT_EQ(a.getState(), STATES::ACCEPT);
}

TEST(AutomataTest, InsertCoinWrongState) {
    Automata a;
    testing::internal::CaptureStdout();
    a.coin(100);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Ошибка"), std::string::npos);
}

TEST(AutomataTest, MenuOutput) {
    Automata a;
    testing::internal::CaptureStdout();
    a.getMenu();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Кофе"), std::string::npos);
    EXPECT_NE(output.find("Черный чай"), std::string::npos);
}

TEST(AutomataTest, ChooseItem) {
    Automata a;
    a.on();
    a.coin(300);
    a.choice(2); // Кофе
    EXPECT_EQ(a.getState(), STATES::CHECK);
}

TEST(AutomataTest, CheckAndCook) {
    Automata a;
    a.on();
    a.coin(300);
    a.choice(2);
    testing::internal::CaptureStdout();
    a.check();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Успешно"), std::string::npos);
    a.cook();
    EXPECT_EQ(a.getState(), STATES::COOK);
}

TEST(AutomataTest, FinishCooking) {
    Automata a;
    a.on();
    a.coin(300);
    a.choice(2);
    a.check();
    a.cook();
    a.finish();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}

TEST(AutomataTest, CancelOrder) {
    Automata a;
    a.on();
    a.coin(150);
    a.cancel();
    EXPECT_EQ(a.getState(), STATES::WAIT);
}
