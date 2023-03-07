//
// Created by Иван Назаров on 03.03.2023.
//
#pragma once

#include "core_structs.h"

#include <string>
#include <vector>

void getTracksFromCSV(const std::string& pathToCSV, std::vector<Track>& tracks);

// For debug only
void writeTracksToCSV(const std::vector<Track>& tracks, const std::string& pathToCSV);