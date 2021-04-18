#ifndef BLOCK_H
#define BLOCK_H

#include "solid.h"
using namespace Blah;

class Block : public Solid{
public:
    Block(int x, int y, int width, int height);
    void draw(Batch *batch) override;
};


#endif
