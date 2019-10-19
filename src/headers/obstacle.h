//
// Created by Jackson Brajer on 2019-10-18.
//

#ifndef BOIDS_OBSTACLE_H
#define BOIDS_OBSTACLE_H

#include <headers/engn/sprite.h>
#include <headers/math/point.h>

class Obstacle : public Sprite, public Point {
public:
    Obstacle();
    Obstacle(Graphics& graphics, Point pos);
};
#endif //BOIDS_OBSTACLE_H
