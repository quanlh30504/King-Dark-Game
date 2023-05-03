#ifndef VARIABLES_H
#define VARIABLES_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <utility>
#include "Texture.h"


// nơi thiết lập cấu hình window và khai báo các biến extern như font, sound, flip,...

//Trong C và C++, từ khóa extern được sử dụng để khai báo một biến, hàm hoặc đối tượng
//được xác định ở nơi khác trong chương trình. Từ khóa này cho phép chương trình truy cập
// vào một biến hoặc hàm được xác định ở một tệp tin hoặc một đối tượng được xác định ở một
//thư viện ngoài.

const int FPS = 60;
const int frameDelay = 1000 / FPS;
extern Uint32 frameStart;
extern unsigned int frameTime;

extern SDL_Window *window;
extern int screenWidth;
extern int screenHeight;
extern int _totalCoins;
extern int _totalHearts;

extern int GROUND_WIDTH;
extern int GROUND_HEIGHT;

extern SDL_RendererFlip FLIP_HOR;
extern SDL_RendererFlip FLIP_NONE;

extern SDL_Renderer *renderer;

extern TTF_Font *fGame;

//Game Sounds
//điều chỉnh nguồn sound tại main
extern Mix_Chunk *pickCoin;
extern Mix_Chunk *hit;
extern Mix_Chunk *jump;
extern Mix_Chunk *slash;
extern Mix_Chunk *downSound;
extern Mix_Chunk *tick;
extern Mix_Chunk *pushrock;
extern Mix_Chunk *win;
extern Mix_Chunk *lose;
extern Mix_Chunk *kill;
extern Mix_Chunk *landing;
extern Mix_Chunk *mrjump;
extern Mix_Chunk *die;
extern Mix_Chunk *tele;

//Game Music
extern Mix_Music *mainMusic;
extern Mix_Music *mainMenu;

#endif // VARIABLES_H
