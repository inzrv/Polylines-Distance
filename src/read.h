//
// Created by Иван Назаров on 03.03.2023.
//
#pragma once
#include <string>
#include <vector>
#include "track.h"

void getTracksFromCSV(const std::string& pathToCSV, std::vector<Track>& tracks);
