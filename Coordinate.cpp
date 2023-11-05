#include "Coordinate.h"

Coordinate::Coordinate(int x, int y): x(x), y(y) {}

bool Coordinate::operator==(const Coordinate& other) const{
    return x == other.x && y == other.y;
}

int Coordinate::getXCoord() {
    return x;
}

void Coordinate::setXCoord(int newX) {
    x = newX;
}

void Coordinate::setYCoord(int newY) {
    y = newY;
}

int Coordinate::getYCoord() {
    return y;
}