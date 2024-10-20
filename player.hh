#ifndef PLAYER_HH
#define PLAYER_HH
#include "main.hh"
class Player
{
private:
    Texture player_texture;
    Sprite player_sprite;
    int x;
    int y;
    bool jump;
    int start_jump_y;
    int life;
    bool dead = false;

public:
    Player(int _x, int _y);
    void draw(RenderWindow &window);
    void move(Direction direction);
    bool is_jumping();
    void start_jump();
    FloatRect getGlobalBounds();
    void player_hurt(int _x, int _y);
    int get_bottom();
    int get_x();
    int get_y();
    bool game_over();
    void player_restart(int _x, int _y);
};
#endif