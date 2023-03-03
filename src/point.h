//
// Created by Иван Назаров on 03.03.2023.
//
#pragma once

struct Point {
    explicit Point(int x = 0, int y = 0, int t = 0) : x(x), y(y), t(t) {}
    int x;
    int y;
    int t;
};
