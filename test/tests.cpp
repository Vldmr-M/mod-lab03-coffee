// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(task, test1) {
    Automata automata;
    ASSERT_EQ(automata.getState(), STATES::OFF);
}

TEST(task, test2) {
    Automata automata;
    automata.on();
    ASSERT_EQ(automata.getState(), STATES::WAIT);
}

TEST(task, test3) {
    Automata automata;
    automata.on();
    automata.coin(50);
    ASSERT_EQ(automata.getState(), STATES::ACCEPT);
}

TEST(task, test4) {
    Automata automata;
    automata.on();
    automata.coin(10);
    automata.choice(1);
    ASSERT_EQ(automata.getState(), STATES::CHECK);
}

TEST(task, test5) {
    Automata automata;
    automata.on();
    automata.coin(50);
    automata.choice(2);
    automata.check();
    ASSERT_EQ(automata.getState(), CHECK);
}

TEST(task, test6) {
    Automata automata;
    automata.on();
    automata.coin(5);
    automata.choice(1);
    automata.check();
    ASSERT_EQ(automata.getState(), CHECK);
}

TEST(task, test7) {
    Automata automata;
    automata.on();
    automata.coin(50);
    automata.choice(2);
    automata.check();
    automata.cook();
    ASSERT_EQ(automata.getState(), COOK);
}

TEST(task, test8) {
    Automata automata;
    automata.on();
    automata.coin(50);
    automata.choice(1);
    automata.check();
    automata.cook();
    automata.finish();
    ASSERT_EQ(automata.getState(), WAIT);
}

TEST(task, test9) {
    Automata automata;
    automata.on();
    automata.coin(100);
    automata.choice(2);
    automata.check();
    automata.cook();
    automata.finish();
    ASSERT_EQ(automata.getState(), WAIT);
}

TEST(task, test10) {
    Automata automata;
    automata.on();
    automata.coin(20);
    automata.cancel();
    ASSERT_EQ(automata.getState(), WAIT);
    automata.coin(30);
    automata.choice(2);
    automata.cancel();
    ASSERT_EQ(automata.getState(), WAIT);
}
