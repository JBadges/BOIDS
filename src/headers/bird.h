//
// Created by Jackson Brajer on 2019-10-17.
//

#ifndef BOIDS_BIRD_H
#define BOIDS_BIRD_H

#include <headers/engn/sprite.h>
#include <headers/math/point.h>
#include "vector"
#include <headers/obstacle.h>

class Bird : public Sprite, public Point {
public:
    Bird();
    Bird(Graphics& graphics, Point pos, double heading);

    void update(int dt, std::vector<std::shared_ptr<Bird>>& birds, std::vector<std::shared_ptr<Obstacle>>& obstacles);

    float getHeading();

private:
    Point m_move;
    float m_heading;
    float m_radius = 35;
    int flockCounter = 0;
    std::vector<std::shared_ptr<Bird>> m_flock;
    std::vector<std::shared_ptr<Obstacle>> m_obstacles;

    Point alignment();
    Point cohesion();
    Point separation();
    Point obstacleDir();
    void updateFlock(std::vector<std::shared_ptr<Bird>>& birds, float radius);
    void updateObstacles(std::vector<std::shared_ptr<Obstacle>>& obstacles, float radius);
};

#endif //BOIDS_BIRD_H
