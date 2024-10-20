#ifndef MONSTER_CC
#define MONSTER_CC
#include "monster.hh"
Monster::Monster(int _x, int _y)
{
    ability = false;
    alive = true;
    life = MONSTER_LIVES;
    direction = RIGHT;
    monster_helmet_texture.loadFromFile("sprite/monster.png");
    monster_wo_helmet_texture.loadFromFile("sprite/monster_wo_helmet.png");
    monster_sprite.setTexture(monster_wo_helmet_texture);
    monster_sprite.setPosition(x, y);
}
void Monster::draw(RenderWindow &window)
{
    window.draw(monster_sprite);
}
int Monster::get_y() { return y; }
int Monster::calculate_new_x() { return x + delta_x[direction] * EVIL_STEP; }
FloatRect Monster::getGlobalBounds() { return monster_sprite.getGlobalBounds(); }
void Monster::move(bool isGround)
{
    hit = false;
    if (!isGround)
    {
        int new_y = y + EVIL_STEP;
        y = new_y;
        monster_sprite.setPosition(x, y);
        return;
    }
    int new_x = calculate_new_x();
    if (direction == RIGHT)
    {
        if (new_x < original_x + EVIL_MAX_MOVE)
        {
            x = new_x;
            monster_sprite.setPosition(x, y);
        }
        else
        {
            direction = LEFT;
            new_x = x + delta_x[direction] * EVIL_STEP;
            x = new_x;
            monster_sprite.setPosition(x, y);
        }
    }
    else
    {
        if (new_x > original_x - EVIL_MAX_MOVE)
        {
            x = new_x;
            monster_sprite.setPosition(x, y);
        }
        else
        {
            direction = RIGHT;
            new_x = x + delta_x[direction] * EVIL_STEP;
            x = new_x;
            monster_sprite.setPosition(x, y);
        }
    }
}
void Monster::hit_player(FloatRect player)
{
    hit = false;
    int player_bottom = player.top + player.height;
    int monster_bottom = monster_sprite.getGlobalBounds().top + monster_sprite.getGlobalBounds().height;
    if (monster_sprite.getGlobalBounds().intersects(player))
    {
        if (!ability)
        {
            life = life - 1;
            if (life == 0)
                alive = false;
            hit = true;
        }
        else
        {
            hit = true;
        }
    }
}
void Monster::hit_monster(FloatRect player)
{

    hit = false;
    if (monster_sprite.getGlobalBounds().intersects(player))
    {
        hit = true;
    }
}
int Monster::get_mid() { return monster_sprite.getGlobalBounds().top + monster_sprite.getGlobalBounds().height / 2; }
bool Monster::is_alive() { return alive; }
bool Monster::is_hit() { return hit; }
void Monster::set_ability(bool monster_abilty)
{
    ability = monster_abilty;
    if (ability)
        monster_sprite.setTexture(monster_helmet_texture);
    else
        monster_sprite.setTexture(monster_wo_helmet_texture);
}
bool Monster::ability_on() { return ability; }
#endif