#include <iostream>
#include <opencv2/opencv.hpp>
#include "csv.h"

#include "point.h"
#include <vector>
#include "tracks_reader.h"
#include <string>

int main() {
    std::vector<std::vector<Point>> tracks;
    std::string pathToCSV("../../test/tracks.csv");
    getTracksFromCSV(pathToCSV, tracks);

    for (const auto& point : tracks[0]) {
        std::cout << point.x << ' ' << point.y << ' ' << point.t << std::endl;
    }

}
