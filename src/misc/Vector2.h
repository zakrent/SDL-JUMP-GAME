//
// Created by zakrent on 2/19/18.
//

#ifndef SDL_JUMP_VECTOR2_H
#define SDL_JUMP_VECTOR2_H

class Vector2 {
public:
    long double x, y;

    void normalize();

    double length();

    Vector2 operator+(Vector2 SecVector);

    Vector2 operator-(Vector2 SecVector);

    Vector2 operator*(long double mul);

    void operator+=(Vector2 SecVector);

    void operator-=(Vector2 SecVector);

    void operator*=(long double mul);

    Vector2(long double x, long double y);

    ~Vector2();
};

inline bool operator==(const Vector2 &first, const Vector2 &second) {
    return first.x == second.x && first.y == second.y;
}

#endif //SDL_JUMP_VECTOR2_H
