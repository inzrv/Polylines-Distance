//
// Created by Иван Назаров on 03.03.2023.
//

#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include "csv.h"
#include "read_write.h"

double timetod(const std::string& time) {
    std::vector<int> tokens;
    std::stringstream ss(time);
    std::string item;
    while (getline(ss, item, ':')) {
        tokens.push_back(std::stoi(item));
    }
    int hours = tokens[0];
    int minutes = tokens[1];
    int seconds = tokens[2];
    return static_cast<double>(seconds + 60 * minutes + 3600 * hours);
}

void sort(Track& track) {
    std::sort(track.begin(), track.end(),
              [](const auto& left, const auto& right){
                return left.t < right.t;
              });
}

void sortTracks(std::vector<Track>& tracks) {
    for (auto& track : tracks) {
        sort(track);
    }
}

void getTracksFromCSV(const std::string& pathToCSV, std::vector<Track>& tracks) {
    io::CSVReader<4, io::trim_chars<' ', '\t'>, io::no_quote_escape<';'>> in(pathToCSV);
    in.read_header(io::ignore_extra_column, "track", "time", "x", "y");
    size_t track_n;
    std::string time;
    double x, y;
    while(in.read_row(track_n, time, x, y)) {
        if (track_n > tracks.size()) {
            tracks.resize(track_n);
        }
        tracks[track_n - 1].emplace_back(x, y, timetod(time));
    }
    sortTracks(tracks);
}

// For debug only
std::string dtotime(double t) {
    int t_int = static_cast<int>(t);
    int h = t_int / 3600;
    int m = t_int / 60;
    int s = t_int % 60;
    std::string time = std::to_string(h) + ':' + std::to_string(m) + ':' +std::to_string(s);
    return time;
}

// For debug only
void writeTracksToCSV(const std::vector<Track>& tracks, const std::string& pathToCSV) {
    std::fstream csv;
    csv.open(pathToCSV, std::ios::out);
    csv << "track;time;x;y\n";
    for (size_t i = 0; i < tracks.size(); ++i) {
        for (const auto& point : tracks[i]) {
            csv << i + 1 << ';' << dtotime(point.t) << ';' << static_cast<int>(point.x) << ';' << static_cast<int>(point.y) << '\n';
        }
    }
    csv.close();
}