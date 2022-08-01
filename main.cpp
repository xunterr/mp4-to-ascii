#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void handleFrame(Mat image, char *symbols, int n);

int main(int, char **)
{

    int WIDTH;
    int HEIGHT;

    char symbols[] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,^`'   \0";
    char *path = new char;

    cout << "Height: ";
    cin >> HEIGHT;

    cout << "Width: ";
    cin >> WIDTH;

    cout << "Path to file: ";
    cin >> path;

    Mat source = imread(path);
    const float ASPECT = ((float)source.cols / 2) / (float)source.rows;

    if (!source.data)
    {
        printf("No image data");
        return -1;
    }

    Mat image;
    resize(source, image, Size(WIDTH, HEIGHT * ASPECT), INTER_LINEAR);

    handleFrame(image, symbols, sizeof(symbols));
    waitKey(0);
    return 0;
}

void handleFrame(Mat image, char *symbols, int n)
{
    for (int i = 0; i < image.size().height; i++)
    {
        for (int j = 0; j < image.size().width; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j);
            int r = pixel[0];
            int g = pixel[1];
            int b = pixel[2];
            double brightness = (0.2126 * r + 0.7152 * g + 0.0722 * b) / 255;
            int s_index = brightness * n;
            printf("%c", symbols[s_index]);
        }
    }
}