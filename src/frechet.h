//
// Created by Иван Назаров on 05.03.2023.
//
#pragma once

#include "track.h"

#include <string>

double frechet(const Track& track1, const Track& track2, const std::string& metric = "euclidean");
