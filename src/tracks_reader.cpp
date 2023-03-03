//
// Created by Иван Назаров on 03.03.2023.
//

#include "csv.h"
#include "tracks_reader.h"
#include <sstream>

int timetoi(std::string& time) {
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

void getTracksFromCSV(std::string& pathToCSV, std::vector<std::vector<Point>>& tracks) {
    io::CSVReader<4, io::trim_chars<' ', '\t'>, io::no_quote_escape<';'>> in(pathToCSV);
    in.read_header(io::ignore_extra_column, "track", "time", "x", "y");
    size_t track_n;
    std::string time;
    int64_t x, y;
    while(in.read_row(track_n, time, x, y)) {
        if (track_n > tracks.size()) {
            tracks.resize(track_n);
        }
        int t = timetoi(time);
        tracks[track_n - 1].push_back(Point(x, y, t));
    }
}
