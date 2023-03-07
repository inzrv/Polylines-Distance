//
// Created by Иван Назаров on 05.03.2023.
//

#include "split.h"
#include "distances.h"

#include <vector>

struct Segment {
    Segment (const Point& start, const Point& end) : start(start), end(end) {}
    Segment(const Segment&) = default;
    Point start;
    Point end;
};

Point getNextPoint(const Segment& segment, double delta, Metric metric) {
    double len = dst(segment.start, segment.end, metric);
    if (len <= delta) {
        return segment.end;
    }
    double alpha = delta / len;
    double x = (1 - alpha) * segment.start.x + alpha * segment.end.x;
    double y = (1 - alpha) * segment.start.y + alpha * segment.end.y;
    double t = (1 - alpha) * segment.start.t + alpha * segment.end.t;
    return Point(x, y, t);
}

void splitSegment(const Segment& segment, std::vector<Point>& newPoints, double delta, Metric metric) {
    assert(newPoints.empty());
    newPoints.push_back(segment.start);
    auto curPoint = getNextPoint(segment, delta, metric);
    while (!isEqual(curPoint, segment.end, metric)) {
        newPoints.push_back(curPoint);
        curPoint = getNextPoint({curPoint, segment.end}, delta, metric);
    }
}

void splitTrack(const Track& srcTrack, Track& splittedTrack, double delta, Metric metric) {
    assert(splittedTrack.empty());
    for (size_t i = 0; i < srcTrack.size() - 1; ++i) {
        Segment segment(srcTrack[i], srcTrack[i + 1]);
        std::vector<Point> newPoints;
        splitSegment(segment, newPoints, delta, metric);
        splittedTrack.insert(splittedTrack.end(), newPoints.begin(), newPoints.end());
    }
    splittedTrack.push_back(srcTrack.back());
}