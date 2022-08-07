#include <opencv2/videoio.hpp>
#include "Video.h"
#include "VideoPlayer.h"

VideoPlayer::VideoPlayer()
{
    this->size = Size(120, 30);
    this->pallete = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,^`'";
}

VideoPlayer::VideoPlayer(char **palette)
{
    this->pallete = *palette;
}

int VideoPlayer::play(char *path)
{
    Video video = *load(path);

    for (size_t i = 0; i < video.frames.size(); i++)
    {
        printf("%s", video.frames.front().getFrame());
        video.frames.pop();
    }

    return 0;
}

Video *VideoPlayer::load(char *path)
{
    VideoCapture video(path);
    Mat source;

    if (!video.isOpened())
    {
        throw "Error opening the file";
    }

    Video *result = new Video;

    while (video.read(source))
    {
        if (!source.data)
        {
            throw "Error reading frame";
        }

        Frame *frame = new Frame(this->size, source, &pallete);
        result->frames.push(*frame);
    }
    return result;
}

Size VideoPlayer::getSize()
{
    return this->size;
}

void VideoPlayer::setSize(Size size)
{
    this->size = size;
}