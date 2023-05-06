#include <SDL_image.h>
#include <iostream>
#include "Texture.h"
#include "Variables.h"

Texture::Texture(){
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

Texture::~Texture(){
	free();
}

// lấy kích thước
void Texture::setSize(std::pair<int, int> size){
	mWidth = size.first;
	mHeight = size.second;
	rect.w = size.first;
	rect.h = size.second;
}

// khởi tạo vị trí
void Texture::setPosition(std::pair<int, int> pos){
	rect.x = pos.first;
	rect.y = pos.second;
}

void Texture::move(std::pair<int, int> addpos){
	rect.x += addpos.first;
	rect.y += addpos.second;
}

// typedef struct SDL_Color {
//     Uint8 r;
//     Uint8 g;
//     Uint8 b;
//     Uint8 a; a: Giá trị độ sáng của kênh alpha (từ 0 đến 255),
//				   trong đó giá trị 0 đại diện cho hoàn toàn trong suốt (không màu),
//				   và giá trị 255 đại diện cho hoàn toàn không trong suốt (màu đầy đủ).
// } SDL_Color;


bool Texture::loadFromRenderedText(std::string textureText, SDL_Color textColor){
	// SDL_Surface* TTF_RenderText_Solid(TTF_Font* font, const char* text, SDL_Color color);
	// font: con trỏ tới font được sử dụng để vẽ văn bản.
	// text: nội dung văn bản cần được vẽ lên bề mặt hình ảnh.
	// color: màu sắc của văn bản.

	SDL_Surface *textSurface = TTF_RenderText_Solid(fGame, textureText.c_str(), textColor);
	if (textSurface == NULL)
		std::cout << "Khong the tao khong gian ve! SDL_ttf Error: " << TTF_GetError() << std::endl;
	else{
		mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
		if (mTexture == NULL)
			std::cout << "Khong ve duoc chu len man hinh! SDL Error: " << SDL_GetError() << std::endl;
		else{
			mWidth = textSurface->w;
			mHeight = textSurface->h;
			rect.w = mWidth;
			rect.h = mHeight;
		}

		SDL_FreeSurface(textSurface);
	}
	return mTexture != NULL;
}

bool Texture::loadFromFile(std::string path){
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
		std::cout << "Khong the load anh! SDL_image error: " << IMG_GetError() << std::endl;
	else{
		mTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (mTexture == NULL)
			std::cout << "Khong ve duoc anh tai " << path << "! SDL error: " << SDL_GetError() << std::endl;
		else{
			if (!mHeight && !mWidth){
				mWidth = loadedSurface->w;
				mHeight = loadedSurface->h;
				rect.w = mWidth;
				rect.h = mHeight;
			}
		}
		SDL_FreeSurface(loadedSurface);
	}
	return mTexture != NULL;
}

void Texture::free(){
	SDL_DestroyTexture(mTexture);
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

void Texture::render(bool flip, SDL_Rect* clip, double angle, SDL_Point* center){
	if (flip){
		SDL_RenderCopyEx(renderer, mTexture, clip, &rect, angle, center, SDL_FLIP_HORIZONTAL);
	}
	else{
		SDL_RenderCopyEx(renderer, mTexture, clip, &rect, angle, center, SDL_FLIP_NONE);
	}
}

int Texture::getWidth(){
	return mWidth;
}

int Texture::getHeight(){
	return mHeight;
}

SDL_Rect Texture::getRect() const{
	return rect;
}

std::pair<int, int> Texture::getPosition() const{
	return {rect.x, rect.y};
}

std::pair<int, int> Texture::getSize() const{
	return {rect.w, rect.h};
}
