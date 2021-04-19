#include <iostream>
#include "floor.h"

Floor::Floor(int width, int height) {
    this->setX(0 - (width - App::width())/2);
    this->setY(App::height() - height);
    this->setWidth(width);
    this->setHeight(height);
}

Floor::~Floor() {
    std::cout << "Floor destroyed" << std::endl;
}

void Floor::draw(Batch *batch) {
    batch->rect(Rect((float)this->getX(),(float)this->getY(), (float)this->getWidth(), (float)this->getHeight()), Color("#017374"));
}