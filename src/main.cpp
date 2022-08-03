#include <iostream>
#include "VideoPlayer.h"
#include "Frame.h"

using namespace cv;
using namespace std;

int main(int, char **)
{
    char *symbols = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,^`'";
    VideoPlayer player(&symbols);
    player.play("C:/Users/User/Downloads/skull.mp4", Size(120, 30));
    return 0;
}
