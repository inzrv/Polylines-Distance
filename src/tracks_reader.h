//
// Created by Иван Назаров on 03.03.2023.
//
#pragma once
#include <string>
#include "point.h"
#include <vector>

void getTracksFromCSV(const std::string& pathToCSV, std::vector<std::vector<Point>>& tracks);
