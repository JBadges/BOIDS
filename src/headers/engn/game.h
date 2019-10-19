//
// Created by Jackson Brajer on 2019-10-16.
//

#ifndef BOIDS_GAME_H
#define BOIDS_GAME_H

#include <headers/bird.h>
#include <headers/obstacle.h>

class Graphics;

class Game {
public:
    Game();
    ~Game();

    std::vector<std::shared_ptr<Bird>> m_birds;
    std::vector<std::shared_ptr<Obstacle>> m_obsticals;
private:
    bool shouldPlaceBird = true;
    void gameLoop();
    void draw(Graphics &graphics);
    void update(float elapsedTime);
};


#endif //BOIDS_GAME_H
