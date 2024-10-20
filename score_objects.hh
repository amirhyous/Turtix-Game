#ifndef SCORE_OBJECTS_HH
#define SCORE_OBJECTS_HH
#include "main.hh"
class Score_Objects
{
private:
    int x, y;
    Texture score_objects_texture;
    Sprite score_objects_sprite;
    Score_Objects_Type type;

public:
    Score_Objects(int _x, int _y, Score_Objects_Type _type);
    void draw(RenderWindow &window);
    Score_Objects_Type get_type();
    FloatRect getGlobalBounds();
};
#endif