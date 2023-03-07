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

double XYT(const Point& p1, const Point& p2) {
    double alpha = 100.0;
    double deltaXSquare = pow(p1.x - p2.x, 2);
    double deltaYSquare =  pow(p1.y - p2.y, 2);
    double deltaTSquare =  pow(alpha * (p1.t - p2.t), 2);
    return sqrt(deltaXSquare + deltaYSquare + deltaTSquare);
}
