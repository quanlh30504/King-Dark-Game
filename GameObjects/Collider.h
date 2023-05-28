#ifndef COLLIDER_H
#define COLLIDER_H

#include "Variables.h"
#include "Texture.h"

enum collider {
    top = 8, right = 6, left = 4, down = 2,
    _top = -8, _right = -6, _left = -4, _down = -2,
};

class Collider {
public:
    SDL_Rect rect; // Hình chữ nhật đại diện cho collider

    Collider(int x, int y, int width, int height) {
        rect.x = x;
        rect.y = y;
        rect.w = width;
        rect.h = height;
    }

    bool CheckCollision(const Collider& otherCollider) {
        // Kiểm tra va chạm giữa hai collider
        if (SDL_HasIntersection(&rect, &otherCollider.rect) == SDL_TRUE) {
            return true; // Va chạm xảy ra
        }
        return false; // Không có va chạm
    }
};

#endif // COLLIDER_H
