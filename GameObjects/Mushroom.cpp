#include "Mushroom.h"

Mushroom::Mushroom(const std::pair<int, int>& position){
    animation = new Animation("data/textures/Mushroom/mushroom.png", {7, 1}, 150);
    loadFromFile("data/textures/Mushroom/mushroom.png");
    setSize({50, 50});
    setPosition(position);
    collider = new Collider(*this);
}

Mushroom::~Mushroom(){
    if (collider != nullptr){
        delete collider;
    }
    if (animation != nullptr){
        delete animation;
    }
}

void Mushroom::Update(const Uint32& deltaTime){
    animation->update(deltaTime, {6, 0}, false);
}

void Mushroom::Render(){
    render(false, animation->getmBox());
}

Collider* Mushroom::getCollider(){
    return collider;
}
