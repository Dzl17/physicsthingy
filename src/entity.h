#ifndef ENTITY_H
#define ENTITY_H


class Entity {
private:
    int x{}, y{}, width{}, height{};
protected:
    Entity() = default;
    void setWidth(int width);
    void setHeight(int height);
public:
    virtual ~Entity() = default;

    bool grabbed{};
    static bool grabFlag;

    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    int getWidth() const;
    int getHeight() const;
    void addX(int amount);
    void addY(int amount);

    bool deleting() const;
    void updateGrabbing();
};


#endif
