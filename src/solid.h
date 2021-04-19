#ifndef SOLID_H
#define SOLID_H

#include <blah.h>
#include "entity.h"

class Solid : public Entity{
protected:
    Solid() = default;
public:
    virtual ~Solid() = default;
    virtual void draw(Blah::Batch *batch) = 0;
};


#endif
