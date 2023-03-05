#include <opencv2/core.hpp>
#include <vector>
#include <string>
#include "core_structs.h"
#include "draw.h"
#include "read.h"
#include "track_generator.h"
#include "frechet.h"
#include "split.h"

int main() {

    /*
    std::vector<Track> tracks;
    getTracksFromCSV("../../test/tracks.csv", tracks);
     */

    Track randomTrack, splittedRandomTrack;

    generateRandomTrack(randomTrack, 30, 1500, 1000);
    splitTrack(randomTrack, splittedRandomTrack, 50);

    std::vector<Track> randomTrackVec = {randomTrack};
    cv::Mat randomTrackImg;
    getTracksImg(randomTrackImg, randomTrackVec);
    cv::imwrite("../../test/img/random_track.png", randomTrackImg);


    std::vector<Track> splittedRandomTrackVec = {splittedRandomTrack};
    cv::Mat splittedRandomTrackImg;
    getTracksImg(splittedRandomTrackImg, splittedRandomTrackVec);
    cv::imwrite("../../test/img/splitted_random_track.png", splittedRandomTrackImg);




}
