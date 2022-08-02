#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include "Frame.h"

using namespace cv;
using namespace std;

int main(int, char **)
{

    int width = 120;
    int height = 30;
    char *path = new char;

    // cout << "Height: ";
    // cin >> height;

    // cout << "Width: ";
    // cin >> width;

    // cout << "Path to file: ";
    // cin >> path;

    VideoCapture video("C:/Users/User/Downloads/y2mate.com - Валентин Стрыкало  Наше лето_v720P.mp4");
    Mat source;

    if (!video.isOpened())
        return -1;

    while (video.read(source))
    {

        if (!source.data)
        {
            printf("No image data");
            return -1;
        }

        Frame *frame = new Frame(width, height, source, "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,^`'", 67);
        cout << frame->getFrame();
    }

    return 0;
}
