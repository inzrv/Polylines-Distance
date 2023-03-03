//
// Created by Иван Назаров on 03.03.2023.
//
#include "draw.h"

cv::Scalar getRandColor() {
    return cv::Scalar(rand() & 255, rand() & 255, rand() & 255);
}

void drawTrack(cv::Mat& img, const Track& track, const cv::Scalar& color) {
    std::vector<cv::Point> points;
    points.reserve(track.size());
    for (const auto& p : track) {
        points.emplace_back(cv::Point(p));
    }
    cv::polylines(img, points, false, color, 2);
    for (const auto& p : points) {
        cv::circle(img, p, 5, color, -1);
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
            drawTrack(img, track, getRandColor());
        }
    }
}

cv::Size findImgSize(const std::vector<Track>& tracks, int margin) {
    int max_x = 0;
    int max_y = 0;
    for (const auto& track : tracks) {
        for (const auto& point : track) {
            max_x = std::max(max_x, point.x);
            max_y = std::max(max_y, point.y);
        }
    }
    return cv::Size(max_x + margin, max_y + margin);
}

void getTracksImg(cv::Mat& img,
                  const std::vector<Track>& tracks,
                  const cv::Scalar& backColor,
                  const std::vector<cv::Scalar>& trackColors,
                  int margin) {
    cv::Size imgSize = findImgSize(tracks, margin);
    img = cv::Mat(imgSize, CV_8UC3, backColor);
    drawTracks(img, tracks, trackColors);
}
