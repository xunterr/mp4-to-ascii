#pragma once

#include <iostream>
#include <opencv2/core.hpp>

using namespace cv;
using namespace std;

class Frame
{
private:
    char *frame;
    int width, height;
    int aspect;
    char *symbols;

    int processMatrix(Mat source, int n);

public:
    Frame(int width, int height, Mat source, char *symbols, int n);
    char *getFrame();
};