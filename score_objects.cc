#ifndef SCORE_OBJECTS_CC
#define SCORE_OBJECTS_CC
#include "score_objects.hh"
Score_Objects::Score_Objects(int _x, int _y, Score_Objects_Type _type) : x(_x), y(_y), type(_type)
{
    if (type == STAR)
        score_objects_texture.loadFromFile("sprite/star.png");
    else
        score_objects_texture.loadFromFile("sprite/diamond.png");
    score_objects_sprite.setTexture(score_objects_texture);
    score_objects_sprite.setPosition(x, y);
}
void Score_Objects::draw(RenderWindow &window)
{
    window.draw(score_objects_sprite);
}
Score_Objects_Type Score_Objects::get_type() { return type; }
FloatRect Score_Objects::getGlobalBounds() { return score_objects_sprite.getGlobalBounds(); }
#endif