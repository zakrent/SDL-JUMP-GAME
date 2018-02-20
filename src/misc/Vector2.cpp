//
// Created by zakrent on 2/19/18.
//

#include "Vector2.h"
#include <cmath>

Vector2::Vector2(long double x, long double y) : x(x), y(y) {}

Vector2::~Vector2() = default;

double Vector2::length(){
    return  (double) (sqrt(pow((double)x, 2) + pow((double)y, 2)));
}

void Vector2::normalize() {
    double length = this->length();
    x /= length;
    y /= length;
}

Vector2 Vector2::operator+(Vector2 SecVector) {
    return Vector2(this->x + SecVector.x, this->y + SecVector.y);
}

Vector2 Vector2::operator-(Vector2 SecVector) {
    return Vector2(this->x - SecVector.x, this->y - SecVector.y);
}

Vector2 Vector2::operator*(long double mul) {
    return Vector2(this->x * mul, this->y * mul);
}

void Vector2::operator+=(Vector2 SecVector) {
    this->x += SecVector.x;
    this->y += SecVector.y;
}

void Vector2::operator-=(Vector2 SecVector) {
    this->x -= SecVector.x;
    this->y -= SecVector.y;
}

void Vector2::operator*=(long double mul) {
    this->x *= mul;
    this->y *= mul;
}

Vector2::Vector2() {
    x = 0;
    y = 0;
}

