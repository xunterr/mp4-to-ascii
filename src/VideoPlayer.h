#pragma once

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include "Video.h"

using namespace cv;

class VideoPlayer
{
public:
    VideoPlayer();
    VideoPlayer(char *pallete);
    Size getSize();
    void setSize(Size size);
    int play(string path);

private:
    char *pallete;
    Size size;
    Video *load(VideoCapture video);
};