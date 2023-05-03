#ifndef DOOR_H
#define DOOR_H

#include "Animation.h"
#include "Collider.h"

class Door: public Texture{
public:
    Door(const std::pair<int, int>& position);
    ~Door();
    void Update(const Uint32& deltaTime);
    void Render();
    Collider* getCollider();
    bool checkOpen();
    void setOpen(const bool& set);
private:
    Animation* animation = nullptr;
    Collider* collider = nullptr;
    bool open;
};

#endif // DOOR_H
