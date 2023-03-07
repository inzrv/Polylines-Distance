//
// Created by Иван Назаров on 05.03.2023.
//

#pragma once

#include "core_structs.h"

enum class Metric {euclidean, manhattan, XYT};

double euclidean(const Point& p1, const Point& p2);

double manhattan(const Point& p1, const Point& p2);

double XYT(const Point& p1, const Point& p2);