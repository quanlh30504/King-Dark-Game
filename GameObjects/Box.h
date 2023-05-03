#ifndef BOX_H
#define BOX_H

#include "Animation.h"
#include "Collider.h"

// lớp sử lí hòm trong game

class Box: public Texture{
public:
    Box(const std::pair<int, int>& position,bool faceRight);
    ~Box();
    int loot = 0;
    void Update(const Uint32& deltaTime);
    Collider* getCollider();
    void Render();
private:
    Collider* collider;
    Animation* animation;
    bool faceRight;
};

#endif // BOX_H
