#ifndef BABY_TURTLE_HH
#define BABY_TURTLE_HH

#include "main.hh"

class Baby_Turtle
{
private:
    int x, y;
    Texture baby_bubble_texture, baby_wo_bubble;
    Sprite baby_sprite;
    bool rescued = false;

public:
    Baby_Turtle(int _x, int _y);
    void draw(RenderWindow &window);
    int get_y() { return y; }
    int calculate_new_x() { return x + STEP_SIZE * delta_x[LEFT]; }
    FloatRect getGlobalBounds() { return baby_sprite.getGlobalBounds(); }
    void rescued_player(FloatRect player);
    int get_mid() { return baby_sprite.getGlobalBounds().top + baby_sprite.getGlobalBounds().height / 2; }
    void move(bool isGround);
};

#endif
