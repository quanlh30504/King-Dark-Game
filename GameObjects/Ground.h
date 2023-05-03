#ifndef GROUND_H
#define GROUND_H

#include "Texture.h"
#include "Collider.h"
#include <string>

class Ground: public Texture{
public:
    Ground();
    ~Ground();

    void setGround(const std::string& image, const int& x, const int&y, const int&data);
    Collider* getCollider();

private:
    Collider* collider = nullptr;
};
#endif // GROUND_H
