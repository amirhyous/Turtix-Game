#ifndef ENEMY_HH
#define ENEMY_HH

#include "main.hh"

class Enemy
{
private:
    int life;
    int x, y;
    int original_x;
    bool alive = true;
    bool hit = false;
    Texture enemy_texture;
    Sprite enemy_sprite;
    Direction direction;

public:
    Enemy(int _x, int _y);
    void draw(RenderWindow &window);
    void move(bool isGround);
    void hit_player(FloatRect player);
    void hit_enemy(FloatRect player);
    int get_y() { return y; }
    int calculate_new_x() { return x + delta_x[direction] * EVIL_STEP; }
    FloatRect getGlobalBounds() { return enemy_sprite.getGlobalBounds(); }
    int get_mid() { return enemy_sprite.getGlobalBounds().top + enemy_sprite.getGlobalBounds().height / 2; }
    bool is_alive() { return alive; }
    bool is_hit() { return hit; }
};

#endif