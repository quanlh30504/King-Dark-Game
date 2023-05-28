#include "Variables.h"
#include "MainScreen.h"

MainScreen::MainScreen(){
}
MainScreen::~MainScreen(){
}

void MainScreen::Init(){
    curState = -1;
    timeClick = 0;

    // thiết lập ttf in nút play
    fontPath = "data/Fonts/ALBA____.TTF";
	fGame = TTF_OpenFont(fontPath.c_str(), 40);
    PlayGame = new Texture();
    PlayGame->loadFromRenderedText("PLAY", {100, 255, 255});
    PlayGame->setPosition({50, 300}); //thiết lập vị trí chữ

    Ins = new Texture();
    Ins->loadFromRenderedText("INSTRUCTION", {255, 255, 255});
    Ins->setPosition({50, 350});

    Exit = new Texture();
    Exit->loadFromRenderedText("EXIT", {255, 255, 255});
    Exit->setPosition({50, 400});
}

int MainScreen::Update(const Uint32& deltaTime){
    currentKeyStates = SDL_GetKeyboardState(NULL);

    PlayGame->loadFromRenderedText("PLAY", {255, 255, 255});
    Ins->loadFromRenderedText("INSTRUCTION", {255, 255, 255});
    Exit->loadFromRenderedText("EXIT", {255, 255, 255});
    PlayGame->setPosition({50, 300});
    Ins->setPosition({50, 350});
    Exit->setPosition({50, 400});

    //thiết lập khi đến thu vực của các nút
    if (curState == 0){
        PlayGame->loadFromRenderedText(">>PLAY", {100, 255, 255}); // tạo màu xanh khi vào vùng dc chọn
        PlayGame->setPosition({60, 300});
    }
    else
        if (curState == 1){
            Ins->loadFromRenderedText(">>INSTRUCTION", {100, 255, 255});// tạo màu xanh khi vào vùng dc chọn
           Ins->setPosition({60, 350});
        }
        else {
            if (curState == 2){
                Exit->loadFromRenderedText(">>EXIT", {100, 255, 255});// tạo màu xanh khi vào vùng dc chọn
                Exit->setPosition({60, 400});
            }
        }
    return -1;
}

void MainScreen::Render(){

    BackGround->render(false);
    PlayGame->render(false);
    Ins->render(false);
    Exit->render(false);
    GameName->render(false);

}
