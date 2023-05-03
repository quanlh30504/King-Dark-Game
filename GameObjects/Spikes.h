#ifndef SPIKES_H
#define SPIKES_H

#include "Animation.h"
#include "Collider.h"
#include "Player.h"

class Spikes: public Texture{
public:
    Spikes(const std::pair<int, int> position, bool direction);
    ~Spikes();
    void Update(const Uint32& deltaTime);
    Collider* getCollider();
    bool checkPlayer(Player* player);
    void Render();
    std::pair<float, float> velocity = {0.0f, 0.0f};
    bool canDrop = false;
    bool touchGround = false;
private:
    bool direction; // 0: top, 1: down
    Animation* animation = nullptr;
    Collider* collider = nullptr;
    bool checkTop(Player* player);
    bool checkDown(Player* player);
};

#endif // SPIKES_H
