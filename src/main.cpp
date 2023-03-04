#include <opencv2/core.hpp>
#include <vector>
#include <string>
#include "track.h"
#include "draw.h"
#include "read.h"
#include "track_generator.h"

int main() {
    int w = 1000;
    int h = 500;
    size_t size = 10;
    std::vector<Track> tracks;
    size_t n = 3;
    for (size_t i = 0; i < n; ++i) {
        Track track;
        generateRandomTrack(track, size, w, h);
        tracks.push_back(track);
    }

    cv::Mat img;
    getTracksImg(img, tracks);
    cv::imwrite("../../test/img/random_tracks.png", img);
}
