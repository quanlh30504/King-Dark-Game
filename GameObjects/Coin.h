#ifndef COIN_H
#define COIN_H

#include "Animation.h"
#include "Collider.h"


class Coin:public Texture{
public:
    Coin(std::pair<int, int> pos);
    ~Coin();
    void Update(const Uint32& deltaTime);
    void Render();
    Collider* getCollider();
    bool deleteCoin;
    int eatCoin;
private:
    Animation* animation = nullptr;
    Collider* collider = nullptr;
};
#endif // COIN_H
