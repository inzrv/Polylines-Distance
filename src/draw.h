//
// Created by Иван Назаров on 03.03.2023.
//
#pragma once
#include "opencv2/opencv.hpp"
#include <vector>
#include "track.h"

static const cv::Scalar red(0, 0, 255);
static const cv::Scalar white(255, 255, 255);
static const cv::Scalar blue(255, 0, 0);
static const cv::Scalar green(0, 255, 0);
static const cv::Scalar pink(147, 20, 255);
static const cv::Scalar black(0, 0, 0);

static const std::vector<cv::Scalar> defaultTracksColors = {red,
                                                    white,
                                                    blue,
                                                    green,
                                                    pink};

cv::Scalar getRandColor();

void drawTrack(cv::Mat& img, const Track& track, const cv::Scalar& color = white);

void drawTracks(cv::Mat& img,
                    const std::vector<Track>& tracks,
                    const std::vector<cv::Scalar>& colors = defaultTracksColors);

cv::Size findImgSize(const std::vector<Track>& tracks, int margin);

void getTracksImg(cv::Mat& img,
                  const std::vector<Track>& tracks,
                  const cv::Scalar& backColor = black,
                  const std::vector<cv::Scalar>& trackColors = defaultTracksColors,
                  int margin = 100);

