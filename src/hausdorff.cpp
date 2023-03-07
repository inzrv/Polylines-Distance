//
// Created by Иван Назаров on 06.03.2023.
//

#include "hausdorff.h"

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


