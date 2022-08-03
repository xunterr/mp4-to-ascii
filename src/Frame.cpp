#include <opencv2/imgproc.hpp>
#include "Frame.h"

using namespace cv;
using namespace std;

Frame::Frame(Size size, Mat source, char **s)
{
    this->aspect = source.cols / (double)(source.rows * 2);
    this->width = size.width;
    this->height = size.height * aspect;

    this->frame = new char[width * height + 1];
    frame[width * height] = '\0';

    symbols = *s;
    processMatrix(source);
}

int Frame::processMatrix(Mat source)
{
    Mat image;
    resize(source, image, Size(width, height), INTER_LINEAR);
    for (int i = 0; i < image.size().height; i++)
    {
        for (int j = 0; j < image.size().width; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j);
            int r = pixel[0];
            int g = pixel[1];
            int b = pixel[2];
            double brightness = (0.2126 * r + 0.7152 * g + 0.0722 * b) / 255;
            int s_index = brightness * strlen(symbols);
            frame[i * image.size().width + j] = symbols[s_index];
        }
    }
    return 0;
}

char *Frame::getFrame()
{
    return frame;
}