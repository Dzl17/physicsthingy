#include "controllable.h"
#include <iostream> // TEMP

#define SPEED 0.9f
#define FRICTION 1.8f
#define SPEEDLIMIT 18
#define GRAVITY 0.9f
#define JUMP -20

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
    std::cout << "Controllable destroyed" << std::endl;
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

void Controllable::resetSpeedX() {
    this->speedX = 0;
}

void Controllable::resetSpeedY() {
    this->speedY = 0;
}

void processInput(Controllable *c, std::vector<Solid*> solids);

void Controllable::update(std::vector<Solid*> solids) {
    // Acceleration resets
    this->accX = 0;
    this->accY = 0;

    processInput(this, solids);

    // Add gravity
    this->addAccY(GRAVITY);

    // Add speed
    if (std::abs(this->speedX + this->accX) < SPEEDLIMIT) this->addSpeedX(this->accX);
    this->addSpeedY(this->accY);

    // Movement addition
    this->moveX(speedX, solids);
    this->moveY(speedY, solids);
    if (this->collidedX) {
        this->speedX = 0;
        this->collidedX = false;
    } else if (this->collidedY) {
        this->speedY = 0;
        this->collidedY = false;
    }

    // Circular screen
    if (this->getX() > 1280) this->setX(-this->getWidth());
    if (this->getX() < 0 - this->getWidth()) this->setX(1280);
}

void processInput(Controllable *c, std::vector<Solid*> solids)
{
    // Input
    if (Input::down(Key::Left)) c->addAccX(-SPEED);
    if (Input::down(Key::Right)) c->addAccX(SPEED);
    if ((Input::down(Key::Up) || Input::pressed(Key::Space)) && c->collideAt(solids, 0, 1)) {
        c->addSpeedY(JUMP); // TODO regulate jump (more height depending on the pressing time)
    }
    if (Input::down(Key::Down)) std::cout << "DOWN" << std::endl;

    // Friction
    if (!Input::down(Key::Left) && !Input::down(Key::Right)) {
        if (std::abs(c->getSpeedX()) - FRICTION <= 0) c->resetSpeedX();
        else if (c->getSpeedX() > 0) c->addSpeedX(-FRICTION);
        else c->addSpeedX(FRICTION);
    }
}

void Controllable::draw(Blah::Batch *batch) {
    batch->rect(Rect((float)this->getX(),(float)this->getY(), (float)this->getWidth(), (float)this->getHeight()), Color::red);
}
