#include <iostream>
#include "VideoPlayer.h"

using namespace cv;
using namespace std;

int main(int, char **)
{
    VideoPlayer player("$@M#*ZO0QCJUYXvxrjft|()[]_+~<>lI:,^    ");
    string path;
    int width;
    int height;

    cout << "Full path to the video: \n";
    getline(cin, path);

    cout << "Output width: \n";
    cin >> width;

    cout << "Output height: \n";
    cin >> height;

    player.setSize(Size(width, height));

    try
    {
        player.play(path);
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }
    return 0;
}
