//
// Created by Jackson Brajer on 2019-10-16.
//

#ifndef BOIDS_GAME_H
#define BOIDS_GAME_H

#include "sprite.h"

class Graphics;

class Game {
public:
    Game();
    ~Game();

private:
    void gameLoop();
    void draw(Graphics &graphics);
    void update(float elapsedTime);

    Sprite m_bird;
};


#endif //BOIDS_GAME_H
