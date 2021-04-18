#include "floor.h"

Floor::Floor(int height) {
    this->setX(0);
    this->setY(App::height() - height);
    this->setWidth(App::width());
    this->setHeight(height);
}

void Floor::draw(Batch *batch) {
    batch->rect(Rect((float)this->getX(),(float)this->getY(), (float)this->getWidth(), (float)this->getHeight()), Color("#017374"));
}
