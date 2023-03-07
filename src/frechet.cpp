//
// Created by Иван Назаров on 05.03.2023.
//

#include <cmath>
#include <vector>
#include <iostream>
#include "frechet.h"
#include "metrics.h"

// type for dynamic programming table
using Table = std::vector<std::vector<double>>;

void fillTable(Table& table, const Track& track1, const Track& track2, Metric metric) {
    auto rows = track1.size();
    auto cols = track2.size();

    assert(table.size() == rows);
    assert(table[0].size() == cols);

    table[0][0] = dst(track1[0], track2[0], metric);

    for (size_t i = 1; i < rows; ++i) {
        table[i][0] = std::max(table[i - 1][0], dst(track1[i], track2[0], metric));
    }

    for (size_t j = 1; j < cols; ++j) {
        table[0][j] = std::max(table[0][j - 1], dst(track1[0], track2[j], metric));
    }

    for (size_t i = 1; i < rows; ++i) {
        for (size_t j = 1; j < cols; ++j) {
            auto minVal = std::min({table[i - 1][j], table[i - 1][j - 1], table[i][j - 1]});
            table[i][j] = std::max(minVal, dst(track1[i], track2[j], metric));
        }
    }

}

double frechet(const Track& track1, const Track& track2, Metric metric) {
    auto rows = track1.size();
    auto cols = track2.size();
    Table table(rows, std::vector<double>(cols));
    fillTable(table, track1, track2, metric);
    return table.back().back();
}