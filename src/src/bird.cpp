//
// Created by Jackson Brajer on 2019-10-17.
//

#include <headers/bird.h>
#include <headers/math/util.h>
#include <headers/engn/globals.h>
#include <iostream>

Bird::Bird() {

}

Bird::Bird(Graphics& graphics, Point pos, double heading) :
    Sprite(graphics, "../res/sprites/roundedArrow.png", 0,0,100,100, pos.getX(), pos.getY()),
    Point(pos), m_heading(heading){

    float x = std::cos(heading * M_PI/180.0);
    float y = std::sin(heading * M_PI/180.0);
    m_move = Point(x,y);
}

Point Bird::alignment() {
    Point steer (0,0);
    for(std::shared_ptr<Bird>& p : this->m_flock) {
        Point head (p->m_move);
        head = head / this->dist(*p);
        steer = steer + head;
    }

    return steer;
}

Point Bird::cohesion() {
    Point steer (0,0);
    for(std::shared_ptr<Bird>& p : this->m_flock) {
        steer = steer + *p;
    }
    if(this->m_flock.size() > 0) {
        steer = steer / this->m_flock.size();
        steer = steer - *this;
        steer = (steer / steer.magnitude()) * 0.1;
        return steer;
    } else {
        return {0,0};
    }
}

Point Bird::separation() {
    Point steer (0,0);
    for(std::shared_ptr<Bird>& p : this->m_flock) {
        Point pos = *this - *p;
        pos = pos / pos.magnitude();
        pos = pos / this->dist(*p);
        steer = steer + pos;
    }

    return steer;
}

Point Bird::obstacleDir() {
    Point steer (0,0);
    for(std::shared_ptr<Obstacle>& p : this->m_obstacles) {
        Point pos = *this - *p;
        pos = pos / pos.magnitude();
        pos = pos / this->dist(*p);
        steer = steer + pos;
    }

    return steer;
}

void Bird::update(int dt, std::vector<std::shared_ptr<Bird>>& birds, std::vector<std::shared_ptr<Obstacle>>& obstacles) {
    // Normalize heading on each start
    while(this->m_heading < 0) {
        this->m_heading += 360;
    }
    while(this->m_heading > 360) {
        this->m_heading -= 360;
    }

    if(true || flockCounter % 25 == 0) {
        updateFlock(birds, this->m_radius);
        updateObstacles(obstacles, this->m_radius);
    }
    flockCounter++;

    // Because right is pos x and down is pos y our angle is change from
    //      90           0             90               90
    //  180    0 to  270   90   +90  0     180 180- 180   0
    //     270          180            270             -90
    // or in other words our render heading is 180-(ch(cartesian heading)+90) = 90 - ch

    //Wrapping position
    this->set(
            std::fmodf((this->getX() + Globals::kScreenWidth), ((float) Globals::kScreenWidth)),
            std::fmodf((this->getY() + Globals::kScreenHeight), ((float) Globals::kScreenHeight)));


    Point alignP = alignment();
    Point coheP = cohesion();
    Point sepP = separation();
    Point obstP = obstacleDir();
    obstP = obstP * 3;
    Point rand = Point((std::rand() % 10000 - 5000) / 10000.f, (std::rand() % 10000 - 5000) / 10000.f);
    rand = rand * 0.1;


    Point final = alignP + coheP + sepP + obstP + rand;

    Point delta = final + m_move;

    if (delta.magnitude() > 75 * (dt/1000.0)) {
        delta = (delta / delta.magnitude()) * (75 * (dt/1000.0));
    }
    if (delta.magnitude() < 30 * (dt/1000.0)) {
        delta = (delta / delta.magnitude()) * (30 * (dt/1000.0));
    }

    this->add(delta);
    if(delta.getX() != 0 && delta.getY() != 0) {
        this->m_move = delta;
    }

    this->m_move = (this->m_move / this->m_move.magnitude());
    m_heading = atan2(delta.getY(), delta.getX()) * 180/M_PI;
}

float Bird::getHeading() {
    return this->m_heading;
}

void Bird::updateFlock(std::vector<std::shared_ptr<Bird>>& birds, float radius) {
    this->m_flock.clear();
    for(std::shared_ptr<Bird>& b : birds) {
        if(b->dist(*this) > 0.1 && b->dist(*this) <= radius) {
            m_flock.push_back(b);
        }
    }
}

void Bird::updateObstacles(std::vector<std::shared_ptr<Obstacle>>& obstacles, float radius) {
    this->m_obstacles.clear();
    for(std::shared_ptr<Obstacle>& obstacle : obstacles) {
        if(obstacle->dist(*this) > 0.1 && obstacle->dist(*this) <= radius) {
            this->m_obstacles.push_back(obstacle);
        }
    }
}
