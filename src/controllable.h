#ifndef CONTROLLABLE_H
#define CONTROLLABLE_H

#include "actor.h"
using namespace Blah;

class Controllable : public Actor {
private:
    float speedX, speedY; // Speed
    float accX, accY; // Acceleration
public:
    Controllable(int x, int y, int width, int height);
    ~Controllable();
    float getSpeedX();
    float getSpeedY();
    float getAccX();
    float getAccY();
    void addSpeedX(float amount);
    void addSpeedY(float amount);
    void addAccX(float amount);
    void addAccY(float amount);
    void update(std::vector<Solid*> solids) override;
    void draw(Batch *batch) override;
};


#endif
