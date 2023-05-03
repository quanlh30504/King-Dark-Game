#ifndef EXITDOOR_H
#define EXITDOOR_H

#include "Texture.h"
#include "Collider.h"

class ExitDoor: public Texture{
public:
    ExitDoor(const std::pair<int, int> position);
    ~ExitDoor();
    Collider* getCollider();
    void Render();
private:
    Collider* collider = nullptr;

};

#endif // EXITDOOR_H
