#include "baby_turtle.hh"

Baby_Turtle::Baby_Turtle(int _x, int _y) : x(_x), y(_y)
{
    baby_bubble_texture.loadFromFile("sprite/baby_turtle_bubble.png");
    baby_wo_bubble.loadFromFile("sprite/baby_turtle_wo_bubble.png");
    baby_sprite.setTexture(baby_bubble_texture);
    baby_sprite.setPosition(x, y);
}
    
void Baby_Turtle::draw(RenderWindow &window)
{
    window.draw(baby_sprite);
}
void Baby_Turtle::rescued_player(FloatRect player)
{
    int player_bottom = player.top + player.height;
    int enemy_bottom = baby_sprite.getGlobalBounds().top + baby_sprite.getGlobalBounds().height;
    if (baby_sprite.getGlobalBounds().intersects(player))
    {
        rescued = true;
        baby_sprite.setTexture(baby_wo_bubble);
    }
}
void Baby_Turtle::move(bool isGround)
{
    if (!isGround)
    {
        int new_y = y + STEP_SIZE;
        y = new_y;
        baby_sprite.setPosition(x, y);
        return;
    }
    if (rescued)
    {
        int new_x = x + STEP_SIZE * delta_x[LEFT];
        x = new_x;
        baby_sprite.setPosition(x, y);
    }
}