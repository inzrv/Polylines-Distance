cmake_minimum_required(VERSION 3.24)
project(Tracks-Distance)

find_package(OpenCV)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories("/usr/local/include/opencv4/opencv2/")
include_directories(include)
include_directories(src)

set(CMAKE_CXX_STANDARD 17)
add_executable(Tracks-Distance
        src/main.cpp
        src/read_write.cpp
        src/draw.cpp
        src/track_generator.cpp
        src/frechet.cpp
        src/metrics.cpp
        src/split.cpp
        src/hausdorff.cpp)
target_link_libraries(Tracks-Distance ${OpenCV_LIBS})