#ifndef SOLID_H
#define SOLID_H

#include <blah.h>

class Solid {
private:
    int x, y, width, height;
protected:
    Solid() = default;
    void setX(int x);
    void setY(int y);
public:
    ~Solid() = default;
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    void setWidth(int width);
    void setHeight(int height);
    virtual void draw(Blah::Batch *batch) = 0;
};


#endif
