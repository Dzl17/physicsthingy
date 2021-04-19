#include <iostream>
#include "floor.h"

Floor::Floor(int height) {
    this->setX(0);
    this->setY(App::height() - height);
    this->setWidth(App::width());
    this->setHeight(height);
}

Floor::~Floor() {
    std::cout << "Floor destroyed" << std::endl;
}

void Floor::draw(Batch *batch) {
    batch->rect(Rect((float)this->getX(),(float)this->getY(), (float)this->getWidth(), (float)this->getHeight()), Color("#017374"));
}