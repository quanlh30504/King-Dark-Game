#ifndef BUTTOM_H
#define BUTTOM_H

#include "Animation.h"
#include "Collider.h"

//lớp sử lí nút nhấn trong game

class Buttom: public Texture{
public:
    Buttom(const std::pair<int, int>& position);
    ~Buttom();
    void Update();
    void Render();
    int checkCollider(Collider* other, const Uint32& deltaTime);
    Collider* getCollider();
    bool getPressed();
    void setPressed(const bool& set);
private:
    Animation* animation = nullptr;
    Collider* collider = nullptr;
    bool pressed;
};

#endif // BUTTOM_H
