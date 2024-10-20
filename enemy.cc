#include "enemy.hh"

Enemy::Enemy(int _x, int _y) : x(_x), y(_y), original_x(_x)
{
    alive = true;
    life = ENEMY_LIVES;
    direction = RIGHT;
    enemy_texture.loadFromFile("sprite/enemy.png");
    enemy_sprite.setTexture(enemy_texture);
    enemy_sprite.setPosition(x, y);
}

void Enemy::draw(RenderWindow &window)
{
    window.draw(enemy_sprite);
}

void Enemy::move(bool isGround)
{
        hit = false;
        if (!isGround)
        {
            int new_y = y + EVIL_STEP;
            y = new_y;
            enemy_sprite.setPosition(x, y);
            return;
        }
        int new_x = calculate_new_x();
        if (direction == RIGHT)
        {
            if (new_x < original_x + EVIL_MAX_MOVE)
            {
                x = new_x;
                enemy_sprite.setPosition(x, y);
            }
            else
            {
                direction = LEFT;
                new_x = x + delta_x[direction] * EVIL_STEP;
                x = new_x;
                enemy_sprite.setPosition(x, y);
            }
        }
        else
        {
            if (new_x > original_x - EVIL_MAX_MOVE)
            {
                x = new_x;
                enemy_sprite.setPosition(x, y);
            }
            else
            {
                direction = RIGHT;
                new_x = x + delta_x[direction] * EVIL_STEP;
                x = new_x;
                enemy_sprite.setPosition(x, y);
            }
        }
}
void Enemy::hit_player(FloatRect player)
{
    hit = false;
    int player_bottom = player.top + player.height;
    int enemy_bottom = enemy_sprite.getGlobalBounds().top + enemy_sprite.getGlobalBounds().height;
    if (enemy_sprite.getGlobalBounds().intersects(player))
    {
        life = life - 1;
        if (life == 0)
            alive = false;
        hit = true;
    }
}
void Enemy::hit_enemy(FloatRect player)
{
    hit = false;
    if (enemy_sprite.getGlobalBounds().intersects(player))
    {
        hit = true;
    }
}
