//
// Created by Иван Назаров on 05.03.2023.
//

#pragma once

#include "core_structs.h"

double dst(const Point& p1, const Point& p2, const std::string& metric);

bool isEqual(const Point& p1, const Point& p2, const std::string& metric);
