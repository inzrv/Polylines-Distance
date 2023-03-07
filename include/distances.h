//
// Created by Иван Назаров on 07.03.2023.
//

#pragma once

#include "metrics.h"

double frechet(const Track& track1, const Track& track2, Metric metric = Metric::euclidean);

double hausdorff(const Track& track1, const Track& track2, Metric metric = Metric::euclidean);

double dst(const Point& p1, const Point& p2, Metric metric = Metric::euclidean);

bool isEqual(const Point& p1, const Point& p2, Metric metric = Metric::euclidean );