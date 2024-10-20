#include "ground.hh"

Ground::Ground(int _x, int _y)
{
    x = _x;
    y = _y;
    if (!texture.loadFromFile("sprite/ground.png"))
        abort();
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}
bool Ground::intersects(FloatRect global_bounds)
{
    FloatRect ground_bounds = sprite.getGlobalBounds();
    if (ground_bounds.intersects(global_bounds))
        return true;
    return false;
}