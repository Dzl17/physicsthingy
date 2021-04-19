#ifndef ENTITY_H
#define ENTITY_H


class Entity {
private:
    int x, y, width, height;
protected:
    Entity() = default;
    void setX(int x);
    void setY(int y);
    void setWidth(int width);
    void setHeight(int height);
public:
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    void addX(int amount);
    void addY(int amount);
    bool deleting();
};


#endif
