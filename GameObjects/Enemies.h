#ifndef ENEMIES_H
#define ENEMIES_H

#include "Texture.h"
#include "Animation.h"
#include "Collider.h"

// 1: pig
// 2: pig bomp
// 3: pig box
// 4: king pig
class Enemies : public Texture {
public:
    Enemies(const std::pair<int, int>& position);
    ~Enemies();

    void Update(const Uint32& deltaTime);
    void Render();

    void SetPosition(const std::pair<int, int>& position);
    std::pair<int, int> GetPosition() const;

    Collider* GetCollider();

    void SetHealth(int health);
    int GetHealth() const;

    void SetSpeed(float speed);
    float GetSpeed() const;

    void TakeDamage(int damage);

private:
    Collider* collider;
    Animation* animation;
    std::pair<int, int> position;
    int health;
    float speed;
};


#endif // ENEMIES_H
