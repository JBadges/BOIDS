//
// Created by Jackson Brajer on 2019-10-16.
//

#ifndef BOIDS_GAME_H
#define BOIDS_GAME_H

#include <headers/bird.h>

class Graphics;

class Game {
public:
    Game();
    ~Game();

private:
    void gameLoop();
    void draw(Graphics &graphics);
    void update(float elapsedTime);

    std::vector<std::shared_ptr<Bird>> m_birds;
};


#endif //BOIDS_GAME_H
