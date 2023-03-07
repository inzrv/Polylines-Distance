//
// Created by Иван Назаров on 06.03.2023.
//
#pragma once

#include "core_structs.h"
#include <string>

double hausdorff(const Track& track1, const Track& track2, const std::string& metric = "euclidean");
