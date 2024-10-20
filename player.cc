#ifndef PLAYER_CC
#define PLAYER_CC
#include "player.hh"
Player::Player(int _x, int _y) : x(_x), y(_y)
{
    life = PLAYER_LIVES;
    player_texture.loadFromFile("sprite/player.png");
    player_sprite.setTexture(player_texture);
    player_sprite.setPosition(x, y);
}
void Player::draw(RenderWindow &window)
{
    window.draw(player_sprite);
}
void Player::move(Direction direction)
{
    int new_x = x + delta_x[direction] * STEP_SIZE;
    int new_y = y + delta_y[direction] * STEP_SIZE;

    if (jump && new_y <= start_jump_y - JUMP_Hight)
    {
        jump = false;
    }
    x = new_x;
    y = new_y;
    player_sprite.setPosition(x, y);
}
bool Player::is_jumping()
{
    return jump;
}
void Player::start_jump()
{
    if (jump)
        return;
    jump = true;
    start_jump_y = y;
}
FloatRect Player::getGlobalBounds() { return player_sprite.getGlobalBounds(); }
void Player::player_hurt(int _x, int _y)
{
    x = _x;
    y = _y;
    player_sprite.setPosition(x, y);
    life = life - 1;
    if (life == 0)
        dead = true;
}
int Player::get_bottom() { return player_sprite.getGlobalBounds().top + player_sprite.getGlobalBounds().height; }
int Player::get_x() { return x; }
int Player::get_y() { return y; }
bool Player::game_over() { return dead; }
void Player::player_restart(int _x, int _y)
{
    x = _x;
    y = _y;
    life = PLAYER_LIVES;
    player_sprite.setPosition(x, y);
    dead = false;
}
#endif