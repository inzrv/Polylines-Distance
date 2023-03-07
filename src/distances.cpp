//
// Created by Иван Назаров on 07.03.2023.
//
#include "distances.h"

#include <cmath>
#include <vector>
#include "metrics.h"

// Functions for calculating distances between points
// Use metrics from metrics.h
double dst(const Point& p1, const Point& p2, Metric metric) {
    switch (metric) {
        case Metric::euclidean:
            return euclidean(p1, p2);
        case Metric::manhattan:
            return manhattan(p1, p2);
        case Metric::XYT:
            return XYT(p1, p2);
    }
    //error?
    return manhattan(p1, p2);
}

bool isEqual(const Point& p1, const Point& p2, Metric metric) {
    double eps = 0.0001;
    return dst(p1, p2, metric) < eps;
}


// Functions for calculating Frechet Distance

// Type for dynamic programming table
using Table = std::vector<std::vector<double>>;

void fillTable(Table& table, const Track& track1, const Track& track2, Metric metric) {
    auto rows = track1.size();
    auto cols = track2.size();

    assert(table.size() == rows);
    assert(table[0].size() == cols);

    table[0][0] = dst(track1[0], track2[0], metric);

    for (size_t i = 1; i < rows; ++i) {
        table[i][0] = std::max(table[i - 1][0], dst(track1[i], track2[0], metric));
    }

    for (size_t j = 1; j < cols; ++j) {
        table[0][j] = std::max(table[0][j - 1], dst(track1[0], track2[j], metric));
    }

    for (size_t i = 1; i < rows; ++i) {
        for (size_t j = 1; j < cols; ++j) {
            auto minVal = std::min({table[i - 1][j], table[i - 1][j - 1], table[i][j - 1]});
            table[i][j] = std::max(minVal, dst(track1[i], track2[j], metric));
        }
    }

}

double frechet(const Track& track1, const Track& track2, Metric metric) {
    auto rows = track1.size();
    auto cols = track2.size();
    Table table(rows, std::vector<double>(cols));
    fillTable(table, track1, track2, metric);
    return table.back().back();
}


// Functions for calculating Hausdorff distance

double findDistToNearestPoint(const Point& point, const Track& track,  Metric metric) {
    double minDst = dst(point, track[0], metric);
    for (size_t i = 1; i < track.size(); ++i) {
        minDst = std::min(minDst, dst(point, track[i], metric));
    }
    return minDst;
}

double findMaxDst(const Track& track1, const Track& track2,  Metric metric) {
    double maxDst = 0.0;
    for (const auto& point : track1) {
        double minDst = findDistToNearestPoint(point, track2, metric);
        maxDst = std::max(maxDst, minDst);
    }
    return maxDst;
}

double hausdorff(const Track& track1, const Track& track2, Metric metric) {
    assert(!track1.empty());
    assert(!track2.empty());
    return std::max(findMaxDst(track1, track2, metric), findMaxDst(track2, track1, metric));
}