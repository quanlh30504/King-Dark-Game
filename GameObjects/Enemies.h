#ifndef ENEMIES_H
#define ENEMIES_H

#include "Texture.h"
#include "Animation.h"
#include "Collider.h"

// 1: pig
// 2: pig bomp
// 3: pig box
// 4: king pig

class Enemies: public Texture{
public:
    Enemies(int type, const std::pair<int, int>& start, const std::pair<int, int>& end, const std::pair<int, int>& position);
    ~Enemies();
    void Update(const Uint32& deltaTime);
    void Render();
    Collider* getCollider();
    int checkDie;
    bool deleteBot;
    float speed;
    bool faceRight;
    int _Move;
    int type;
private:
    Animation* animation = nullptr;
    Collider* collider = nullptr;
    std::pair<int, int> start, end;
    std::pair<int, int> frameLimit;
};


#endif // ENEMIES_H
