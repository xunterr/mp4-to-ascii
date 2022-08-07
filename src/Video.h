#pragma once

#include <queue>
#include "Frame.h"

typedef struct Video
{
    queue<Frame> frames;
};