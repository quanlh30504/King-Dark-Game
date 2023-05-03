#include "Variables.h"
#include "MainScreen.h"

MainScreen::MainScreen(){
}
MainScreen::~MainScreen(){
    if (BackGround != nullptr){
        delete BackGround;
    }
    if (PlayGame != nullptr){
        delete PlayGame;
    }
    if (Ins != nullptr){
        delete Ins;
    }
    if (Exit != nullptr){
        delete Exit;
    }
    if (GameName != nullptr){
        delete GameName;
    }
    if (currentKeyStates != nullptr){
        delete currentKeyStates;
    }
}

void MainScreen::Init(){
    curState = -1;
    timeClick = 0;

    //khởi tạo background menu
    BackGround = new Texture();
    BackGround->loadFromFile("data/textures/Background/menu_background.png");
    BackGround->setPosition({0, 0});
    BackGround->setSize({screenWidth, screenHeight});


    //thiết lập ttf người sáng tạo
    std::string fontPath = "data/Fonts/KGSummerSunshineBlackout.ttf";
	fGame = TTF_OpenFont(fontPath.c_str(), 13);  // 150: kích thước của font chữ được đặt tính bằng điểm ảnh (pt).
    GameName = new Texture();
    GameName->loadFromRenderedText("Maded by Quan Nguyen_22026552", {200, 255, 200});
    GameName->setPosition({20, 520}); // thiết lập vị trí chữ


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

    //sử dụng phím lên và xuống để lựa chọn đối tượng trong menu

    if (currentKeyStates[SDL_SCANCODE_DOWN] && timeClick <= 0) {
        curState++;
        //tạo sound sau 1 sự kiện bàn phím
        Mix_PlayChannel(-1, tick, 0);  //ở chỉ số thứ 3 đặt là 0 sẽ phát lại 1 lần còn đặt là -1 sẽ phát vô hạn
        if (curState > 2) curState = 0;
        timeClick = 200;
    }
    currentKeyStates = SDL_GetKeyboardState(NULL);
    if (currentKeyStates[SDL_SCANCODE_UP] && timeClick <= 0) {
        Mix_PlayChannel(-1, tick, 0);
        curState--;
        if (curState < 0) curState = 2;
        timeClick = 200;
    }
    currentKeyStates = SDL_GetKeyboardState(NULL);
    //SDL_SCANCODE_RETURN  được sử dụng để biểu diễn phím "Enter"
    if (currentKeyStates[SDL_SCANCODE_RETURN] && timeClick <= 0) {
        Mix_PlayChannel(-1, tick, 0);
        timeClick = 200;
        return curState;
    }
    if (timeClick >= 0){
        timeClick -= deltaTime;
    }


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
