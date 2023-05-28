
#include "Enemies.h"

Enemies::Enemies(const std::pair<int, int>& position) : position(position), health(100), speed(1.0f) {
    animation = new Animation(/*tham số animation*/);
    animation = new Animation("data/textures/Enemies/worm.png", {6, 2}, 150);
        loadFromFile("data/textures/Enemies/worm.png");
        setSize({68, 56});
        setPosition(position);
        frameLimit = {6, 0};
}

Enemies::~Enemies() {
    delete collider;
    delete animation;
}

void Enemies::Update(const Uint32& deltaTime) {
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

void Enemies::Render() {
    render(faceRight, animation->getmBox());
}

void Enemies::SetPosition(const std::pair<int, int>& position) {
    this->position = position;
}

std::pair<int, int> Enemies::GetPosition() const {
    return position;
}

Collider* Enemies::GetCollider() {
    return collider;
}

void Enemies::SetHealth(int health) {
    this->health = health;
}

int Enemies::GetHealth() const {
    return health;
}

void Enemies::SetSpeed(float speed) {
    this->speed = speed;
}

float Enemies::GetSpeed() const {
    return speed;
}

void Enemies::TakeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
        // Xử lý khi quái vật bị hết máu
    }
}
