#ifndef PORTAL_HH
#define PORTAL_HH
#include "main.hh"
class Portal
{
private:
    int x, y;
    Texture portal_texture;
    Sprite portal_sprite;

public:
    Portal(int _x, int _y);
    void set_position(int _x, int _y);
    void draw(RenderWindow &window);
    FloatRect getGlobalBounds();
};
#endif