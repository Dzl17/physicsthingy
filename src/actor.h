#ifndef ACTOR_H
#define ACTOR_H

#include <blah.h>
#include "entity.h"
#include "solid.h"

class Actor : public Entity{
protected:
    Actor() = default;
public:
    virtual ~Actor() = default;
    bool collidedX;
    bool collidedY;
    void moveX(float amount, std::vector<Solid*> solids);
    void moveY(float amount, std::vector<Solid*> solids);
    bool collideAt(int x, int y, int w, int h);
    bool collideAt(Solid* solid);
    bool collideAt(std::vector<Solid*> solids, int xOffset, int yOffset);
    virtual void draw(Blah::Batch *batch) = 0;
    virtual void update(std::vector<Solid*>) = 0;
};


#endif
