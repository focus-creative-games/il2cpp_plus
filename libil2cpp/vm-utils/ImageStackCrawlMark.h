#pragma once

#include "vm/Image.h"

// Mono uses a StackCrawlMark to mark the location of the caller's stack
// It is a enum with a maximum value of 4.
// We don't use the StackCrawlMark, but we can re-purpose the pointer to pass in
// the calling image (which is what we want anyway)
// So this call start's with an int32_t value of -1 so we can detect if it's a normal
// Mono StackCrawlMark or our ImageStackCrawlMark
class ImageStackCrawlMark
{
    static const int32_t IMAGE_STACK_MARK_VALUE = -1;

public:

    ImageStackCrawlMark(const Il2CppImage* image)
        : image(image), stackMark(IMAGE_STACK_MARK_VALUE) {}

    static const Il2CppImage* GetImageFromStackMark(int32_t* stackMark)
    {
        if (*stackMark == IMAGE_STACK_MARK_VALUE)
            return reinterpret_cast<ImageStackCrawlMark*>(stackMark)->image;
        return nullptr;
    }

private:
    int32_t stackMark;
    const Il2CppImage* image;
};
