#pragma once

#include <iostream>
#include <opencv2/core.hpp>

using namespace cv;

class VideoPlayer
{
public:
    VideoPlayer();
    VideoPlayer(char **pallete);
    int play(char *path, Size size);

private:
    char *pallete;
};