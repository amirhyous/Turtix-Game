#ifndef MONSTER_HH
#define MONSTER_HH
#include "main.hh"
class Monster
{
private:
    int life;
    int x, y;
    int original_x;
    bool alive = true;
    bool hit = false;
    bool ability;
    Texture monster_helmet_texture, monster_wo_helmet_texture;
    Sprite monster_sprite;
    Direction direction;

public:
    Monster(int _x, int _y);
    void draw(RenderWindow &window);
    int get_y();
    int calculate_new_x();
    FloatRect getGlobalBounds();
    void move(bool isGround);
    void hit_player(FloatRect player);
    void hit_monster(FloatRect player);
    int get_mid();
    bool is_alive();
    bool is_hit();
    void set_ability(bool monster_abilty);
    bool ability_on();
};
#endif