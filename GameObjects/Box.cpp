#include "Box.h"

Box::Box(const std::pair<int, int>& position, bool faceRight){
    animation = new Animation("data/textures/Box/loot_box.png", {12, 1}, 100); //{12,1} số cột, số hàng trong 1 sprite ảnh animation
    setSize({50, 30});
    loadFromFile("data/textures/Box/loot_box.png");
    setPosition(position);
    this->faceRight = faceRight;
    animation->currentFrame = {0, 0};
    collider = new Collider(*this);
}

Box::~Box(){
    if (animation != nullptr)
        delete animation;
    if (collider != nullptr)
        delete collider;
}

void Box::Update(const Uint32& deltaTime){
    if (loot == 0){
        animation->update(deltaTime, {12, 0}, faceRight);
    }
    if (loot == 1){
        loot++;
        loadFromFile("data/textures/Box/loot_box_open.png");
    }
}
Collider* Box::getCollider(){
    return collider;
}

void Box::Render(){
    if (loot != 0) render(faceRight);
    else render(faceRight, animation->getmBox());
}
