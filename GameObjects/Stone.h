#ifndef STONE_H
#define STONE_H

#include "Texture.h"
#include "Collider.h"

class Stone {
public:
    Stone(const std::pair<int, int>& position);
    ~Stone();
    void Render();
    void Update(const Uint32& deltaTime);
    Collider* getCollider();
    bool canDrop;
    Texture body;
private:
    void limitPosition();
    std::pair<float, float> veclocity;
    Collider* collider = nullptr;
};
#endif // STONE_H
