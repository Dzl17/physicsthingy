#include "entity.h"
#include <blah.h>

using namespace Blah;

bool Entity::grabFlag = false;

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

void Entity::addWidth(int amount) {
    this->width += amount;
}

void Entity::addHeight(int amount) {
    this->height += amount;
}

bool Entity::deleting() const {
    Vec2 m = Input::mouse();
    bool b =this->x <= (int)m.x &&
            this->x + this->width >= (int)m.x &&
            this->y <= (int)m.y &&
            this->y + this->height >= (int)m.y &&
            Input::pressed(Key::D);
    if (b) {
        if (this->grabbed) grabFlag = false;
        return true;
    } else {
        return false;
    }
}

void Entity::updateGrabbing() {
    Vec2 m = Input::mouse();
    if(     this->x <= (int)m.x &&
            this->x + this->width >= (int)m.x &&
            this->y <= (int)m.y &&
            this->y + this->height >= (int)m.y &&
            Input::down(MouseButton::Left) &&
            !this->grabbed && !grabFlag) {
        this->grabbed = true;
        grabFlag = true;
    }

    if (this->grabbed) {
        this->setX((int) m.x - this->getWidth()/2);
        this->setY((int) m.y - this->getHeight()/2);
        if (Input::released(MouseButton::Left)) {
            this->grabbed = false;
            grabFlag = false;
        }
    }
}
