#include "solid.h"

int Solid::getX() const {
    return x;
}

void Solid::setX(int xNum) {
    this->x = xNum;
}

int Solid::getY() const {
    return y;
}

void Solid::setY(int yNum) {
    this->y = yNum;
}

int Solid::getWidth() const {
    return width;
}

void Solid::setWidth(int widthNum) {
    this->width = widthNum;
}

int Solid::getHeight() const {
    return height;
}

void Solid::setHeight(int heightNum) {
    this->height = heightNum;
}
