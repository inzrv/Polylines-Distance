//
// Created by Иван Назаров on 04.03.2023.
//

#include "track_generator.h"
#include <random>
#include <cmath>

double generateRandomDouble(double min, double max) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<> dist(min, max);
    return dist(generator);
}

Point generateRandomPoint(const Point& center, double rMin, double rMax, int t) {
    double radius = generateRandomDouble(rMin, rMax);
    double angle = generateRandomDouble(0, 2 * M_PI);
    int x = static_cast<int>(radius * cos(angle));
    int y = static_cast<int>(radius * sin(angle));
    return Point(center.x + x, center.y + y, t);
}

bool isCorrectPoint(const Point& p, int xMax, int yMax) {
    if (p.x < 0 || p.x > xMax) {
        return false;
    }
    if (p.y < 0 || p.y > yMax) {
        return false;
    }
    return true;
}

void generateRandomTrack(Track& track, size_t size, int xMax, int yMax) {
    assert(track.empty());
    track.reserve(size);
    double rMin = 2.0;
    double rMax = static_cast<double>(std::min(xMax, yMax)) / 3.0;
    int t = 0;
    Point lastPoint = Point(xMax / 2, yMax / 2, t);
    Point curPoint = generateRandomPoint(lastPoint, rMin, rMax, t);
    for (size_t i = 0; i < size; ++i) {
        while (!isCorrectPoint(curPoint, xMax, yMax)) {
            curPoint = generateRandomPoint(lastPoint, rMin, rMax, t);
        }
        track.emplace_back(curPoint);
        t++;
        lastPoint = curPoint;
        curPoint = generateRandomPoint(track.back(), rMin, rMax, t);
    }
}