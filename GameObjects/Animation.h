#ifndef ANIMATION_H
#define ANIMATION_H

#include "Variables.h"
#include <SDL.h>

class Animation {
public:
    std::vector<SDL_Rect> frames; // Danh sách các frame của animation
    int currentFrameIndex; // Chỉ số frame hiện tại
    int frameDelay; // Độ trễ giữa các frame
    int frameTimer; // Thời gian đã trôi qua kể từ frame cuối cùng

    Animation() {
        currentFrameIndex = 0;
        frameDelay = 100; // Đặt độ trễ mặc định là 100ms
        frameTimer = 0;
    }

    void AddFrame(int x, int y, int width, int height) {
        SDL_Rect frameRect = {x, y, width, height};
        frames.push_back(frameRect);
    }

    void Update(int deltaTime) {
        frameTimer += deltaTime;

        // Kiểm tra xem đã đến lúc chuyển frame mới hay chưa
        if (frameTimer >= frameDelay) {
            frameTimer = 0;
            currentFrameIndex++;
            if (currentFrameIndex >= frames.size()) {
                currentFrameIndex = 0;
            }
        }
    }

    void Draw(SDL_Renderer* renderer, int x, int y) {
        SDL_Rect currentFrame = frames[currentFrameIndex];
        SDL_Rect destRect = {x, y, currentFrame.w, currentFrame.h};
        SDL_RenderCopy(renderer, texture, &currentFrame, &destRect);
    }
};
#endif // ANIMATION_H
