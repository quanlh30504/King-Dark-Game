#include "Enemies.h"

Enemies::Enemies(int type, const std::pair<int, int>& start, const std::pair<int, int>& end, const std::pair<int, int>& position){
    collider = new Collider(*this);
    this->type = type;
    _Move = 0;
    faceRight = false;
    deleteBot = false;
    checkDie = 0;
    speed = 10;
    if (type == 1){
        animation = new Animation("data/textures/Enemies/worm.png", {6, 2}, 150);
        loadFromFile("data/textures/Enemies/worm.png");
        setSize({68, 56});
        setPosition(position);
        frameLimit = {6, 0};
    }
    if (type == 2){
        animation = new Animation("data/textures/Enemies/slime_spritesheet.png", {6, 2}, 150);
        loadFromFile("data/textures/Enemies/slime_spritesheet.png");
        setSize({70, 70});
        setPosition(position);
        frameLimit = {6, 0};
    }
    if (type == 3){
        animation = new Animation("data/textures/Enemies/mushroom_spritesheet.png", {6, 2}, 150);
        loadFromFile("data/textures/Enemies/mushroom_spritesheet.png");
        setSize({70, 70});
        setPosition(position);
        frameLimit = {6, 0};
    }
    if(type == 4)
    {
        animation = new Animation("data/textures/Enemies/king_pig.png", {6, 2}, 150);
        loadFromFile("data/textures/Enemies/king_pig.png");
        setSize({100,80});
        setPosition(position);
        frameLimit = {6 , 0};
    }
    this->start = start;
    this->end = end;
    if (start.first < end.first) _Move = 1;
    else {
        _Move = -1;
        swap(this->start, this->end);
    }
}

Enemies::~Enemies(){
    if (collider != nullptr){
        delete collider;
    }
    if (animation != nullptr){
        delete animation;
    }
}

void Enemies::Update(const Uint32& deltaTime){
    if (deleteBot){
        return;
    }
    if (checkDie == 1){
        checkDie++;
        if (type == 1) {
			frameLimit = {6, 1};
			animation->currentFrame = {0, 1};
		}
		if (type == 2) {
			frameLimit = {4, 1};
			animation->currentFrame = {0, 1};
		}
		if (type == 3) {
			frameLimit = {4, 1};
			animation->currentFrame = {0, 1};
		}
		if (type == 4) {
			frameLimit = {4, 1};
			animation->currentFrame = {0, 1};
		}

    }

    if (_Move == 1){
        //if (type == 2) faceRight = false;
        //else faceRight = true;
        faceRight = true;
    }
    else{
//        if (type == 2) faceRight = true;
//        else faceRight = false;
          faceRight = false;
    }

    if (_Move == 1) {
		if (getPosition().first > end.first) {
			setPosition({end.first, getPosition().second});
			_Move = -1;
		}
	}
	else {
		if (getPosition().first < start.first) {
			setPosition({start.first, getPosition().second});
			_Move = 1;
		}
	}
    if (animation->update(deltaTime, frameLimit, faceRight) && checkDie){
        deleteBot = true;
    }
    move({(float) _Move * speed * deltaTime * 0.01f, 0});
}

void Enemies::Render(){
    render(faceRight, animation->getmBox());
}

Collider* Enemies::getCollider(){
    return collider;
}
