//
// Created by Иван Назаров on 05.03.2023.
//
#include "metrics.h"

double euclidean(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double manhattan(const Point& p1, const Point& p2) {
    return std::max(std::abs(p1.x - p2.x), std::abs(p1.y - p2.y));
}

// this function can be further extended
double dst(const Point& p1, const Point& p2, Metric metric) {
    if (metric == Metric::euclidean) {
        return euclidean(p1, p2);
    }
    return manhattan(p1, p2);
}

bool isEqual(const Point& p1, const Point& p2, Metric metric) {
    double eps = 0.0001;
    return dst(p1, p2, metric) < eps;
}
