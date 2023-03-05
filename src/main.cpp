#include <opencv2/core.hpp>
#include <vector>
#include <string>
#include "track.h"
#include "draw.h"
#include "read.h"
#include "track_generator.h"
#include "frechet.h"

int main() {
    std::vector<Track> tracks;
    getTracksFromCSV("../../test/tracks.csv", tracks);
    cv::Mat img12;
    getTracksImg(img12, {tracks[0], tracks[1]});
    cv::imwrite("../../test/img/img12.png", img12);
    std::cout << frechet(tracks[0], tracks[1]) << std::endl;
}
