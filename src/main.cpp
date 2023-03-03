#include <opencv2/core.hpp>
#include <vector>
#include <string>
#include "track.h"
#include "draw.h"
#include "read.h"

int main() {
    std::vector<Track> tracks;
    std::string pathToCSV("../../test/tracks.csv");
    getTracksFromCSV(pathToCSV, tracks);

    std::string  pathToImg("../../test/img/");
    cv::Mat img;
    getTracksImg(img, tracks);
    cv::imwrite(pathToImg + "img1.png", img);
}
