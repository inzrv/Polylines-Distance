//
// Created by Иван Назаров on 03.03.2023.
//
#pragma once
#include <string>
#include <vector>
#include "core_structs.h"

void getTracksFromCSV(const std::string& pathToCSV, std::vector<Track>& tracks);

// For debug only
void writeTracksToCSV(const std::vector<Track>& tracks, const std::string& pathToCSV);