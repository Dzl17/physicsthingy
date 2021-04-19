#ifndef FLOOR_H
#define FLOOR_H

#include "solid.h"
using namespace Blah;

class Floor : public Solid{
public:
    ~Floor() override;
    explicit Floor(int height); // TODO why explicit?
    void draw(Batch *batch) override;
};


#endif
