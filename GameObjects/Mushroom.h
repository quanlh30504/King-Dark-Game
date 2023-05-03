#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "Animation.h"
#include "Collider.h"

class Mushroom: public Texture{
public:
    Mushroom(const std::pair<int, int>& position);
    ~Mushroom();
    void Update(const Uint32& deltaTime);
    void Render();
    Collider* getCollider();
private:
    Animation* animation = nullptr;
    Collider* collider = nullptr;
};
#endif // MUSHROOM_H
