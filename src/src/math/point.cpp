//
// Created by Jackson Brajer on 2019-10-17.
//

#include <headers/math/point.h>
#include <cmath>

Point::Point() : m_x(0), m_y(0) {

}

Point::Point(float x, float y) : m_x(x), m_y(y) {

}

float Point::dist(const Point &p) {
    return std::sqrt(
            (this->m_x-p.m_x)*(this->m_x-p.m_x) +
            (this->m_y-p.m_y)*(this->m_y-p.m_y));
}

float Point::magnitude() {
    return this->dist(Point());
}

void Point::set(float x, float y) {
    this->m_x = x;
    this->m_y = y;
}

void Point::move(float dist, float angle) {
    this->set(m_x + std::cos(angle) * dist, m_y + std::sin(angle) * dist);
}

float Point::getX() const {
    return this->m_x;
}

float Point::getY() const {
    return this->m_y;
}

Point Point::operator+(const Point &p) {
    return {this->m_x + p.m_x, this->m_y + p.m_y};
}

Point Point::operator-(const Point &p) {
    return {this->m_x - p.m_x, this->m_y - p.m_y};
}

Point Point::operator*(const float &d) {
    return {this->m_x * d, this->m_y * d};
}

Point Point::operator/(const float &d) {
    return {this->m_x / d, this->m_y / d};
}

void Point::add(Point &p) {
    this->m_x += p.m_x;
    this->m_y += p.m_y;
}

