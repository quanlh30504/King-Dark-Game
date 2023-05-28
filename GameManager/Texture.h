#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>
#include <string>

using namespace std;

class Texture {
public:
    SDL_Texture* texture;
    SDL_Rect rect;

    Texture() {
        texture = nullptr;
        rect = {0, 0, 0, 0};
    }

    ~Texture() {
        Free();
    }

    bool LoadFromFile(SDL_Renderer* renderer, const std::string& filePath) {
        // Tải ảnh từ file
        SDL_Surface* surface = IMG_Load(filePath.c_str());
        if (surface == nullptr) {
            printf("Unable to load image %s! SDL_image Error: %s\n", filePath.c_str(), IMG_GetError());
            return false;
        }

        // Tạo texture từ surface
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (texture == nullptr) {
            printf("Unable to create texture from %s! SDL Error: %s\n", filePath.c_str(), SDL_GetError());
            SDL_FreeSurface(surface);
            return false;
        }

        // Lấy kích thước từ surface
        rect.w = surface->w;
        rect.h = surface->h;

        // Giải phóng surface
        SDL_FreeSurface(surface);

        return true;
    }

    void Free() {
        // Giải phóng texture
        if (texture != nullptr) {
            SDL_DestroyTexture(texture);
            texture = nullptr;
            rect = {0, 0, 0, 0};
        }
    }

    void Render(SDL_Renderer* renderer, int x, int y) {
        rect.x = x;
        rect.y = y;

        // Vẽ texture lên renderer
        SDL_RenderCopy(renderer, texture, nullptr, &rect);
    }
};


#endif // TEXTURE_H
