#include "block.h"
#include <iostream>

Block::Block(int x, int y, int width, int height) {
    this->setX(x);
    this->setY(y);
    this->setWidth(width);
    this->setHeight(height);
}

Block::~Block() {
    std::cout << "Block destroyed" << std::endl;
}

void Block::draw(Batch *batch) {
    batch->rect(Rect((float)this->getX(),(float)this->getY(), (float)this->getWidth(), (float)this->getHeight()), Color::blue);
}
