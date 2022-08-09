#include <opencv2/videoio.hpp>
#include <chrono>
#include "Video.h"
#include "VideoPlayer.h"

using namespace std;
using namespace cv;

VideoPlayer::VideoPlayer()
{
    this->size = Size(120, 30);
    this->pallete = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,^`'";
}

VideoPlayer::VideoPlayer(char *pallete)
{
    this->pallete = pallete;
}

int VideoPlayer::play(string path)
{
    VideoCapture capture(path);
    Video video = *load(capture);
    int fps = capture.get(CAP_PROP_FPS);

    auto time_between_frames = chrono::microseconds(std::chrono::seconds(1)) / fps;
    auto target_tp = chrono::system_clock::now();

    system("cls");

    for (size_t i = 0; i < video.frames.size(); i++)
    {
        printf("%s", video.frames.front().getFrame());
        video.frames.pop();
        target_tp += time_between_frames;
        this_thread::sleep_until(target_tp);
    }

    return 0;
}

Video *VideoPlayer::load(VideoCapture video)
{
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
    video.release();
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