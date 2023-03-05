//
// Created by Иван Назаров on 03.03.2023.
//
#include <random>
#include "draw.h"

cv::Scalar generateRandColor() {
    std::random_device os_seed;
    auto seed = os_seed();
    std::mt19937 generator(seed);
    std::uniform_int_distribution<uint32_t> distribute(0, 255);
    auto b = distribute(generator);
    auto g = distribute(generator);
    auto r = distribute(generator);
    auto color = cv::Scalar(b, g, r);
    return color;
}

void drawTrack(cv::Mat& img, const Track& track, const cv::Scalar& color) {
    std::vector<cv::Point> points;
    points.reserve(track.size());
    for (const auto& p : track) {
        points.emplace_back(cv::Point(p));
    }
    cv::polylines(img, points, false, color, 2);
    cv::circle(img, points[0], 7, color, 3);
    for (size_t i = 1; i < points.size(); ++i) {
        cv::circle(img, points[i], 4, color, -1);
    }
}

void drawTracks(cv::Mat& img,
                    const std::vector<Track>& tracks,
                    const std::vector<cv::Scalar>& colors) {
    for (size_t i = 0; i < tracks.size(); ++i) {
        const Track& track = tracks[i];
        if (i < colors.size()) {
            drawTrack(img, track, colors[i]);
        } else {
            drawTrack(img, track, generateRandColor());
        }
    }
}

cv::Size findImgSize(const std::vector<Track>& tracks, int margin) {
    int xMax = 0;
    int yMax = 0;
    for (const auto& track : tracks) {
        for (const auto& point : track) {
            xMax = std::max(xMax, static_cast<int>(point.x));
            yMax = std::max(yMax, static_cast<int>(point.y));
        }
    }
    return {xMax + margin, yMax + margin};
}

void getTracksImg(cv::Mat& img,
                  const std::vector<Track>& tracks,
                  const cv::Scalar& backColor,
                  const std::vector<cv::Scalar>& trackColors,
                  int margin) {
    auto imgSize = findImgSize(tracks, margin);
    img = cv::Mat(imgSize, CV_8UC3, backColor);
    drawTracks(img, tracks, trackColors);
}
