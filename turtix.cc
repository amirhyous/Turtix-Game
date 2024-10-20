#ifndef TURTIX_CC
#define TURTIX_CC
#include "turtix.hh"
Turtix::Turtix() : player(map.get_initial_x() + 100, map.get_initial_y()),
                   view(FloatRect(Vector2f(map.get_initial_x(), map.get_initial_y()), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT)))
{
    map.fetch_vecotrs(enemy_vector, monster_vector, baby_turtle_vector, score_objects_vector);
}
void Turtix::start(RenderWindow &window)
{
    map.render(window);
}
bool Turtix::get_start() { return start_again; }
void Turtix::restart()
{
    if (win_state || (player.game_over()))
    {
        start_again = false;
        win_state = false;
        map.fetch_vecotrs(enemy_vector, monster_vector, baby_turtle_vector, score_objects_vector);
        player.player_restart(map.get_initial_x(), map.get_initial_y());
        score = 0;
    }
}
void Turtix::win()
{
    if ((baby_turtle_vector.size() == 0) && (!player.game_over()) && (player.getGlobalBounds().intersects(map.get_portal_bounds())))
    {
        win_state = true;
    }
}
void Turtix::game_over(RenderWindow &window)
{
    if (player.game_over())
    {
        start_again = true;
        window.clear();
        sf::Text text;
        sf::Text score_text;
        sf::Font font;
        font.loadFromFile("TIMESR.ttf");
        score_text.setFont(font);
        score_text.setString("Score: " + to_string(score));
        score_text.setCharacterSize(36);
        score_text.setFillColor(sf::Color::Red);
        score_text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        score_text.setPosition(Vector2f(0, 500));
        window.draw(score_text);

        text.setFont(font);
        text.setString("GAME OVER!");
        text.setCharacterSize(60);
        text.setFillColor(sf::Color::Red);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        text.setPosition(Vector2f(0, 700));
        window.draw(text);
    }
}
void Turtix::win_game(RenderWindow &window)
{
    if (win_state)
    {
        start_again = true;
        window.clear();
        sf::Text text;
        sf::Text score_text;
        sf::Font font;
        font.loadFromFile("TIMESR.ttf");
        score_text.setFont(font);
        score_text.setString("Score: " + to_string(score));
        score_text.setCharacterSize(36);
        score_text.setFillColor(sf::Color::Red);
        score_text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        score_text.setPosition(Vector2f(0, 500));
        window.draw(score_text);

        text.setFont(font);
        text.setString("You Won!");
        text.setCharacterSize(60);
        text.setFillColor(sf::Color::Red);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        text.setPosition(Vector2f(0, 700));
        window.draw(text);
    }
}
void Turtix::move_player(Direction direction)
{
    int new_x = player.get_x() + delta_x[direction] * STEP_SIZE;
    int new_y = player.get_y() + delta_y[direction] * STEP_SIZE;
    if (!map.is_ground(new_x, new_y, player.getGlobalBounds()))
    {
        player.move(direction);
        for (int i = 0; i < enemy_vector.size(); i++)
        {
            if (player.get_bottom() - enemy_vector[i].get_mid() <= 5)
            {
                if (direction == DOWN)
                    enemy_vector[i].hit_player(player.getGlobalBounds());
                if (enemy_vector[i].is_hit())
                    player.start_jump();
                if (!enemy_vector[i].is_alive())
                    enemy_vector.erase(enemy_vector.begin() + i);
            }
            else
            {
                for (int i = 0; i < enemy_vector.size(); i++)
                {
                    enemy_vector[i].hit_enemy(player.getGlobalBounds());
                    if (enemy_vector[i].is_hit())
                    {
                        player.player_hurt(map.get_initial_x(), map.get_initial_y());
                    }
                }
            }
        }
        for (int i = 0; i < monster_vector.size(); i++)
        {
            if (player.get_bottom() - monster_vector[i].get_mid() <= 5)
            {
                if (direction == DOWN)
                    monster_vector[i].hit_player(player.getGlobalBounds());
                if (monster_vector[i].ability_on())
                {
                    if (monster_vector[i].is_hit())
                    {
                        player.player_hurt(map.get_initial_x(), map.get_initial_y());
                    }
                }
                else
                {
                    if (monster_vector[i].is_hit())
                        player.start_jump();
                    if (!monster_vector[i].is_alive())
                        monster_vector.erase(monster_vector.begin() + i);
                }
            }
            else
            {
                for (int i = 0; i < monster_vector.size(); i++)
                {
                    monster_vector[i].hit_monster(player.getGlobalBounds());
                    if (monster_vector[i].is_hit())
                    {
                        player.player_hurt(map.get_initial_x(), map.get_initial_y());
                    }
                }
            }
        }
        for (int i = 0; i < baby_turtle_vector.size(); i++)
        {
            if (player.get_bottom() - baby_turtle_vector[i].get_mid() <= 5)
            {
                baby_turtle_vector[i].rescued_player(player.getGlobalBounds());
            }
        }
    }
}
void Turtix::move_enemy(Enemy &enemy)
{
    if (!map.is_ground(enemy.calculate_new_x(), enemy.get_y(), enemy.getGlobalBounds()))
        enemy.move(false);
    else
        enemy.move(true);
}
void Turtix::move_monster(Monster &monster)
{
    if (!map.is_ground(monster.calculate_new_x(), monster.get_y(), monster.getGlobalBounds()))
        monster.move(false);
    else
        monster.move(true);
}
void Turtix::move_baby(Baby_Turtle &baby)
{
    if (!map.is_ground(baby.calculate_new_x(), baby.get_y(), baby.getGlobalBounds()))
        baby.move(false);
    else
        baby.move(true);
}
void Turtix::baby_rescued()
{
    for (int i = 0; i < baby_turtle_vector.size(); i++)
    {
        if (baby_turtle_vector[i].getGlobalBounds().intersects(map.get_portal_bounds()))
        {
            baby_turtle_vector.erase(baby_turtle_vector.begin() + i);
        }
    }
}
void Turtix::show_score(RenderWindow &window)
{
    sf::Text text;
    sf::Font font;
    font.loadFromFile("TIMESR.ttf");
    text.setFont(font);
    text.setString("Score: " + to_string(score));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setPosition(Vector2f(player.get_x() - VIEW_WIDTH / 2, player.get_y() - VIEW_HEIGHT / 2));
    window.draw(text);
}
void Turtix::update_score()
{
    for (int i = 0; i < score_objects_vector.size(); i++)
    {
        if (score_objects_vector[i].getGlobalBounds().intersects(player.getGlobalBounds()))
        {
            if (score_objects_vector[i].get_type() == STAR)
                score += 1;
            else
                score += 5;
            score_objects_vector.erase(score_objects_vector.begin() + i);
        }
    }
}
void Turtix::tick(RenderWindow &window, Event &event)
{
    if (event.type == Event::KeyPressed)
    {
        if ((event.key.code == Keyboard::Up || event.key.code == Keyboard::W) && (!player.game_over()) && (!win_state))
        {
            int new_x = player.get_x() + delta_x[DOWN] * STEP_SIZE;
            int new_y = player.get_y() + delta_y[DOWN] * STEP_SIZE;
            if (map.is_ground(new_x, new_y, player.getGlobalBounds()))
                player.start_jump();
        }
        else if ((event.key.code == Keyboard::Left || event.key.code == Keyboard::A) && (!player.game_over()) && (!win_state))
        {
            move_player(LEFT);
        }
        else if ((event.key.code == Keyboard::Right || event.key.code == Keyboard::D) && (!player.game_over()) && (!win_state))
        {
            move_player(RIGHT);
        }
        else if ((event.type == Event::MouseButtonPressed) && (player.game_over()))
        {
            if (player.game_over())
                start_again = true;
        }
        else if ((event.type == Event::MouseButtonPressed) && (win_state))
        {
            if (win_state)
                start_again = true;
        }
    }
    if (player.is_jumping())
        move_player(UP);
    else
        move_player(DOWN);
    for (int i = 0; i < baby_turtle_vector.size(); i++)
        move_baby(baby_turtle_vector[i]);
    for (int i = 0; i < enemy_vector.size(); i++)
        move_enemy(enemy_vector[i]);
    for (int i = 0; i < monster_vector.size(); i++)
        move_monster(monster_vector[i]);
    update_score();
    baby_rescued();
    win();
}
void Turtix::draw(RenderWindow &window)
{
    window.clear();
    view.setCenter(Vector2f(player.get_x(), player.get_y()));
    window.setView(view);
    map.render(window);
    for (int i = 0; i < baby_turtle_vector.size(); i++)
        baby_turtle_vector[i].draw(window);
    for (int i = 0; i < score_objects_vector.size(); i++)
        score_objects_vector[i].draw(window);
    for (int i = 0; i < enemy_vector.size(); i++)
        enemy_vector[i].draw(window);
    for (int i = 0; i < monster_vector.size(); i++)
        monster_vector[i].draw(window);
    player.draw(window);
    show_score(window);
    game_over(window);
    win_game(window);
}
void Turtix::set_monsters_ability(bool monster_ability)
{
    for (int i = 0; i < monster_vector.size(); i++)
        monster_vector[i].set_ability(monster_ability);
}
#endif