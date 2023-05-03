#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>
#include <string>

using namespace std;

class Texture{
public:
	Texture();

	~Texture();

	void setSize(pair<int, int> size);

	void setPosition(pair<int, int> pos);

	void move(pair<int, int> addpos);

	// Tạo ảnh từ font
	bool loadFromRenderedText(string textureText, SDL_Color textColor);

	// Tải ảnh từ đường dẫn
	bool loadFromFile(string path);

	void free();

	// Tạo text tại vị trí bất kì
	void render(bool flip = 0, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL);

	// Lấy vị trí ảnh
	int getWidth();
	int getHeight();
	SDL_Rect getRect() const;
	SDL_Rect* getRect();
	pair<int, int> getPosition() const;
	pair<int, int> getSize() const;

protected:
	SDL_Texture *mTexture;
	SDL_Rect rect;
	int mWidth;
	int mHeight;
};

#endif // TEXTURE_H
