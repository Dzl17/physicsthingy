#include "controllable.h"
#include <iostream> // TEMP

#define SPEED 0.9f
#define FRICTION 0.8f
#define SPEEDLIMIT 18

Controllable::Controllable(int x, int y, int width, int height) {
    this->setX(x);
    this->setY(y);
    this->setWidth(width);
    this->setHeight(height);
    this->speedX = 0;
    this->speedY = 0;
    this->accX = 0;
    this->accY = 0;
}

Controllable::~Controllable()
{

}

float Controllable::getSpeedX(){
    return this->speedX;
}

float Controllable::getSpeedY()
{
    return this->speedY;
}

float Controllable::getAccX()
{
    return this->accX;
}

float Controllable::getAccY()
{
    return this->accY;
}

void Controllable::addSpeedX(float amount) {
    this->speedX += amount;
}

void Controllable::addSpeedY(float amount) {
    this->speedY += amount;
}

void Controllable::addAccX(float amount) {
    this->accX += amount;
}

void Controllable::addAccY(float amount) {
    this->accY += amount;
}

void Controllable::update(std::vector<Solid*> solids) {
    this->accX = 0;
    this->accY = 0;
    // Input
    if (Input::down(Key::Left)) this->addAccX(-SPEED);
    if (Input::down(Key::Right)) this->addAccX(SPEED);
    if (Input::down(Key::Up)) std::cout << "UP" << std::endl;
    if (Input::down(Key::Down)) std::cout << "DOWN" << std::endl;
    // Speed addition
    if (std::abs(this->speedX + this->accX) < SPEEDLIMIT) this->addSpeedX(this->accX);
    this->addSpeedY(this->accY);
    // Friction
    if (!Input::down(Key::Left) && !Input::down(Key::Right)) {
        if (this->speedX > 0) this->addSpeedX(-FRICTION);
        else this->addSpeedX(FRICTION);
    }
    // Movement addition
    this->moveX(speedX, solids);
    this->moveY(speedY, solids);
    if (this->collided) {
        this->speedX = 0;
        this->speedY = 0;
        this->collided = false;
    }

    // Circular screen TODO improve
    if (this->getX() > 1280) this->setX(-this->getWidth());
    if (this->getX() < 0 - this->getWidth()) this->setX(1280);
}

void Controllable::draw(Blah::Batch *batch) {
    batch->rect(Rect((float)this->getX(),(float)this->getY(), (float)this->getWidth(), (float)this->getHeight()), Color::red);
}
