#include <iostream>
#include "VideoPlayer.h"

using namespace cv;
using namespace std;

int main(int, char **)
{
    VideoPlayer player;
    string path;
    int width;
    int height;

    cout << "Full path to the video: " << endl;
    cin >> path;

    cout << "Output width: " << endl;
    cin >> width;

    cout << "Output height: " << endl;
    cin >> height;

    player.setSize(Size(width, height));

    try
    {
        player.play("C:/Users/User/Downloads/skull.mp4");
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }
    return 0;
}
