#include <opencv2/core.hpp>
#include <vector>
#include <string>
#include "core_structs.h"
#include "draw.h"
#include "read.h"
#include "track_generator.h"
#include "frechet.h"
#include "split.h"
#include "hausdorff.h"

int main() {
    std::vector<Track> tracks;
    getTracksFromCSV("../../test/tracks.csv", tracks);
    Track track1 = tracks[1];
    Track track2 = tracks[2];

    Track split_track1, split_track2;
    splitTrack(track1, split_track1, 40);
    splitTrack(track2, split_track2, 40);

    std::cout << hausdorff(split_track1, split_track2) << std::endl;
}
