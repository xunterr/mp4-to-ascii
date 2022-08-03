#include <opencv2/videoio.hpp>
#include "Video.h"
#include "VideoPlayer.h"

VideoPlayer::VideoPlayer(char **palette)
{
    this->pallete = *palette;
}

int VideoPlayer::play(char *path, Size size)
{
    VideoCapture video(path);
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

        Frame *frame = new Frame(size, source, &pallete);
        printf("%s", frame->getFrame());
    }
    return 0;
}