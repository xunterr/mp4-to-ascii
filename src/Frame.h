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
    double aspect;
    char *symbols;
    
    int processMatrix(Mat source);

public:
    Frame(Size size, Mat source, char **symbols);
    char *getFrame();
};