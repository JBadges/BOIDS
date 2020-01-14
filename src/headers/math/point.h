//
// Created by Jackson Brajer on 2019-10-17.
//

#ifndef BOIDS_POINT_H
#define BOIDS_POINT_H

class Point {
public:
    Point();
    Point(float x, float y);

    float magnitude();
    float dist(const Point& p);
    float wrappedDist(const Point& p);

    void move(float dist, float angle);
    void add(Point& p);
    void set(float x, float y);

    float getX() const;
    float getY() const;

    Point operator+(const Point& p);
    void operator+=(const Point& p);
    Point operator-(const Point& p);
    void operator-=(const Point& p);
    Point operator*(const float& d);
    void operator*=(const float& d);
    Point operator/(const float& d);
    void operator/=(const float& d);
private:
    float m_x, m_y;
};

#endif //BOIDS_POINT_H
