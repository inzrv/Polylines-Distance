cmake_minimum_required(VERSION 3.24)
project(Polylines_Distance)

find_package(OpenCV)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories("/usr/local/include/opencv4/opencv2/")

set(CMAKE_CXX_STANDARD 17)
add_executable(Polylines_Distance
        main.cpp
        read.cpp
        draw.cpp
        track_generator.cpp
        frechet.cpp
        metrics.cpp
        split.cpp
        hausdorff.cpp)
target_link_libraries(Polylines_Distance ${OpenCV_LIBS})