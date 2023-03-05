//
// Created by Иван Назаров on 03.03.2023.
//
#pragma once
#include <vector>
#include <opencv2/core.hpp>

struct Point {
    explicit Point(double x = 0, double y = 0, double t = 0) : x(x), y(y), t(t) {}
    double x;
    double y;
    double t;
    explicit operator cv::Point() const {return {static_cast<int>(x), static_cast<int>(y)};}
};

using Track = std::vector<Point>;
