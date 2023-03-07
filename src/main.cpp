#include <opencv2/core.hpp>
#include <vector>
#include <string>
#include "core_structs.h"
#include "draw.h"
#include "read_write.h"
#include "track_generator.h"
#include "frechet.h"
#include "split.h"
#include "hausdorff.h"

int main() {

}

/* Tracks from tracks.csv
 * std::vector<Track> tracks;
 * getTracksFromCSV("../../test/tracks.csv", tracks);
 */

/* Generate and save random track
 * Track randTrack;
 * generateRandomTrack(randTrack, 20, 1500, 1000);
 * cv::Mat img;
 * std::vector<Track> randTrackVec = {randTrack};
 * getTracksImg(img, randTrackVec);
 * cv::imwrite("../../test/img/rand_track.png", img);
 * writeTracksToCSV(randTrackVec, "../../test/rand_track.csv");
 */