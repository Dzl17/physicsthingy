#include "entity.h"
#include <blah.h>

using namespace Blah;

int Entity::getX() const {
    return x;
}

void Entity::setX(int xNum) {
    this->x = xNum;
}

int Entity::getY() const {
    return y;
}

void Entity::setY(int yNum) {
    this->y = yNum;
}

int Entity::getWidth() const {
    return width;
}

void Entity::setWidth(int widthNum) {
    this->width = widthNum;
}

int Entity::getHeight() const {
    return height;
}

void Entity::setHeight(int heightNum) {
    this->height = heightNum;
}

void Entity::addX(int amount)
{
    this->x += amount;
}

void Entity::addY(int amount)
{
    this->y += amount;
}

bool Entity::deleting() {
    Vec2 m = Input::mouse();
    return  this->x <= (int)m.x &&
            this->x + this->width >= (int)m.x &&
            this->y <= (int)m.y &&
            this->y + this->height >= (int)m.y &&
            Input::pressed(Key::D);
}
