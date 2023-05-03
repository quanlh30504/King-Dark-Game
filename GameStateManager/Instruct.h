#ifndef INSTRUCT_H
#define INSTRUCT_H

#include "Texture.h"

// lớp instruction 

class Instruct{
public:
    Instruct();
    ~Instruct();

    void Init();
    void Render();
private:
    Texture* BackGround;
    Texture* title;
    Texture* main;
    Texture* _next;
};

#endif // INSTRUCT_H
