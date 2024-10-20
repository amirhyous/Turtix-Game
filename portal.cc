#ifndef PORTAL_CC
#define PORTAL_CC
#include "portal.hh"
Portal::Portal(int _x, int _y) : x(_x), y(_y)
{
    portal_texture.loadFromFile("sprite/portal.png");
    portal_sprite.setTexture(portal_texture);
    portal_sprite.setPosition(x, y);
}
void Portal::set_position(int _x, int _y)
{
    x = _x;
    y = _y;
    portal_sprite.setPosition(x, y);
}
void Portal::draw(RenderWindow &window)
{
    window.draw(portal_sprite);
}
FloatRect Portal::getGlobalBounds() { return portal_sprite.getGlobalBounds(); }
#endif