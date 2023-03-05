//
// Created by Иван Назаров on 05.03.2023.
//
#include "metrics.h"

double euclidean(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// this function can be further extended
double dst(const Point& p1, const Point& p2, const std::string& metric) {
    if (metric == "euclidean") {
        return euclidean(p1, p2);
    }
    return euclidean(p1, p2);
}

bool isEqual(const Point& p1, const Point& p2, const std::string& metric) {
    double eps = 0.0001;
    return dst(p1, p2, metric) < eps;
}
