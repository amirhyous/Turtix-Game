#ifndef GROUND_HH
#define GROUND_HH

#include "main.hh"

class Ground
{
    Texture texture;
    Sprite sprite;
    int x, y;

public:
    Ground(int _x, int _y);
    int get_width() { return sprite.getGlobalBounds().width; }
    int get_height() { return sprite.getGlobalBounds().height; }
    void draw(RenderWindow &window) { window.draw(sprite); };
    bool intersects(FloatRect global_bounds);
};

#endif

