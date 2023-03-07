//
// Created by Иван Назаров on 05.03.2023.
//
#pragma once

#include "core_structs.h"
#include "metrics.h"

#include <string>

double frechet(const Track& track1, const Track& track2, Metric metric = Metric::euclidean);
