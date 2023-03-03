//
// Created by Иван Назаров on 03.03.2023.
//

#include "csv.h"
#include "tracks_reader.h"
#include <sstream>
#include <algorithm>

int timetoi(const std::string& time) {
    std::vector<int> tokens;
    std::stringstream ss(time);
    std::string item;
    while (getline(ss, item, ':')) {
        tokens.push_back(std::stoi(item));
    }
    int hours = tokens[0];
    int minutes = tokens[1];
    int seconds = tokens[2];
    return (seconds + 60 * minutes + 3600 * hours);
}

void sort(std::vector<Point>& track) {
    std::sort(track.begin(), track.end(),
              [](const auto& left, const auto& right){
                return left.t < right.t;
              });
}

void sortTracks(std::vector<std::vector<Point>>& tracks) {
    for (auto& track : tracks) {
        sort(track);
    }
}

void getTracksFromCSV(const std::string& pathToCSV, std::vector<std::vector<Point>>& tracks) {
    io::CSVReader<4, io::trim_chars<' ', '\t'>, io::no_quote_escape<';'>> in(pathToCSV);
    in.read_header(io::ignore_extra_column, "track", "time", "x", "y");
    size_t track_n;
    std::string time;
    int64_t x, y;
    while(in.read_row(track_n, time, x, y)) {
        if (track_n > tracks.size()) {
            tracks.resize(track_n);
        }
        tracks[track_n - 1].push_back(Point(x, y, timetoi(time)));
    }
    sortTracks(tracks);
}
