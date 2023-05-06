#include "Game.h"
#include"SDL_ttf.h"
#include <iostream>

std::string conver(int num){
     num = num * 100;
     int cc = num / 83;
     std::string res = std::to_string(cc);
     cc = num % 83; cc *= 10; cc = cc/ 83;
     res += "." + std::to_string(cc) + "%";
     return res;
}

Game::Game(){
    mainMap = nullptr;
    is_Running = false;
}
Game::~Game(){}

void Game::Init(){
    checkplaysound = false;
    is_Running = true;

    _totalHearts = 3; //khởi tạo số mạng ban đầu là 3
    _totalCoins = 0; //khởi tạo số coin ban đầu  = 0

    //khởi tạo map level 1
    mainMap = new Map();
    mainMap->loadMap("data/map/1.txt");

    TotalCoins_1 = new Texture(); //texture để in hình ảnh coin
    TotalCoins_1->loadFromFile("data/textures/Background/coins.png");
    TotalCoins_1->setSize({40, 40});
    TotalCoins_1->setPosition({20, 10});
    TotalCoins_2 = new Texture();  //texture in định dạng chữ số coin có
    TotalCoins_2->loadFromRenderedText("x0", {255, 255, 255}); //in ra hiện tại có xo coin
    TotalCoins_2->setPosition({70, 10});

    Hearts_1 = new Texture(); //texture để in hình ảnh mạng(tim)
    Hearts_1->loadFromFile("data/textures/Background/lifes.png");
    Hearts_1->setSize({40, 40});
    Hearts_1->setPosition({900, 10});
    Hearts_2 = new Texture(); ////texture in định dạng chữ số mạng có
    Hearts_2->loadFromRenderedText("x3", {255, 255, 255});
    Hearts_2->setPosition({940, 10});

    //tải background cho game
    BackGround = new Texture();
    BackGround->loadFromFile("data/textures/Background/background.png");
    BackGround->setPosition({0, 0});
    BackGround->setSize({screenWidth, screenHeight});

    //về sau cải tiến sẽ in ra 1 ảnh loss màu
    Lose = new Texture(); // texture loss
    Lose->loadFromRenderedText("YOU LOSE!!!", {255, 0, 0});
    Lose->setPosition({410, 100});

    //về sau cải tiến sẽ in ra 1 ảnh win màu
    Win = new Texture(); //texture win
    Win->loadFromRenderedText("YOU WIN!!!", {124, 252, 0});
    Win->setPosition({425, 100});


    gamePause = new Texture();
    gamePause->loadFromRenderedText("GAME PAUSED!!!", {255, 255, 255});
    gamePause->setPosition({350, 100});

    //thiết lập font mới và cỡ chữ cho fGame
    std::string fontPath = "data/Fonts/visitor1.ttf";
	fGame = TTF_OpenFont(fontPath.c_str(), 30);

    //texture return game
    _next = new Texture();
    _next->loadFromRenderedText("PRESS ENTER TO RETURN MENU!", {131, 111, 255});
    _next->setPosition({300, 300});


    _nextpause = new Texture();
    _nextpause->loadFromRenderedText("PRESS ESC TO CONTINUE OR ENTER TO RETURN MENU!", {131, 111, 255});
    _nextpause->setPosition({100, 300});


    _losemain = new Texture();
    _losemain->loadFromRenderedText("LET'S TRY AGAIN!", {255, 255, 255});
    _losemain->setPosition({400, 200});

    // thiết lập lại kiểu và cỡ chữ cho fGame
    fontPath = "data/Fonts/visitor1.ttf";
	fGame = TTF_OpenFont(fontPath.c_str(), 40);
}

void Game::Update(const Uint32& deltaTime){
    if (LOSEGAME) return;
    if (mainMap->winGame && mainMap->getPlayer()->deletePlayer){
        _curMap++;
        if (_curMap > 5){
            WINGAME = true;
        }
        else{
            delete mainMap;
            std::string _curMapPath = "data/map/" + std::to_string(_curMap) + ".txt";
            mainMap = new Map();
			mainMap->loadMap(_curMapPath);
        }
    }
    mainMap->Update(deltaTime);

    // cập nhật lại số mạng
    if (_totalHearts <= 0) LOSEGAME = true;
    else{
       Hearts_2->loadFromRenderedText("x" + std::to_string(_totalHearts), {255, 255, 255});
    }
    TotalCoins_2->loadFromRenderedText("x" + std::to_string(_totalCoins), {255, 255, 255});
}

void Game::Render(){
    mainMap->Render(); //in ra tile map

    // in hình ảnh coin và số coin dạng chũ
    TotalCoins_1->render(false);
    TotalCoins_2->render(false);

    //in hình ảnh mạng và số mạng dạng chữ
    Hearts_1->render(false);
    Hearts_2->render(false);
}

void Game::RenderGameOver(){
    Mix_PlayChannel(-1, lose, 0); //thiết lập sound loss
    BackGround->render(false);  //in texture background
    Lose->render(false);      //in ra màn texture dạng chữ "YOU LOSE!!!"
    _losemain->render(false);  //in ra texture dạng chữ "LET'S TRY AGAIN!"
    _next->render(false);      //"PRESS ENTER TO RETURN MENU!"
}

void Game::RenderGameWin(){
    //thiết lập lại kiểu và cỡ chữ
    std::string fontPath = "data/Fonts/visitor1.ttf";
	fGame = TTF_OpenFont(fontPath.c_str(), 30);

    //thiết lập sound win
    Mix_PlayChannel(-1, win, 0);

    _winmain = new Texture();

    //tính toán thành tích
    std::string winstring = "You have surpassed ";
    winstring += conver(_totalCoins);
    winstring += " players!";
    //load string winstring vào texture
    _winmain->loadFromRenderedText(winstring, {255, 255, 255});
    _winmain->setPosition({250, 200}); //điều chỉnh vị trí

    //khởi tạo lại cỡ chữ
    fontPath = "data/Fonts/visitor1.ttf";
	fGame = TTF_OpenFont(fontPath.c_str(), 40);


    BackGround->render(false);
    Win->render(false);
    _winmain->render(false);
    _next->render(false);
}

void Game::RenderGamePause(){
    // in ra màn hình game pause
    BackGround->render(false);
    gamePause->render(false);
    _nextpause->render(false);
}

void Game::Clean(){
    _totalCoins = 0;
    _curMap = 1;
}
