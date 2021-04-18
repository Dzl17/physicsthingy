#ifndef ACTOR_H
#define ACTOR_H

#include <blah.h>
#include "solid.h"

class Actor {
private:
    int x, y, width, height;
protected:
    Actor() = default;
    void setX(int x);
    void setY(int y);
    void setWidth(int width);
    void setHeight(int height);
public:
    ~Actor() = default;
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    bool collided;
    void moveX(float amount, std::vector<Solid*> solids);
    void moveY(float amount, std::vector<Solid*> solids);
    bool collideAt(int x, int y, int w, int h);
    bool collideAt(Solid* solid);
    bool collideAt(std::vector<Solid*> solids, int xOffset, int yOffset);
    virtual void draw(Blah::Batch *batch) = 0;
    virtual void update(std::vector<Solid*>) = 0;
};


#endif
