#ifndef TURTIX_HH
#define TURTIX_HH
#include "main.hh"
#include "baby_turtle.hh"
#include "enemy.hh"
#include "ground.hh"
#include "map.hh"
#include "monster.hh"
#include "player.hh"
#include "portal.hh"
#include "score_objects.hh"
class Turtix
{
    vector<Enemy> enemy_vector;
    vector<Monster> monster_vector;
    vector<Baby_Turtle> baby_turtle_vector;
    vector<Score_Objects> score_objects_vector;
    Map map;
    Player player;
    int score = 0;
    View view;
    bool start_again = false;
    bool win_state = false;

public:
    Turtix();
    void start(RenderWindow &window);
    bool get_start();
    void restart();
    void win();
    void game_over(RenderWindow &window);
    void win_game(RenderWindow &window);
    void move_player(Direction direction);
    void move_enemy(Enemy &enemy);
    void move_monster(Monster &monster);
    void move_baby(Baby_Turtle &baby);
    void baby_rescued();
    void show_score(RenderWindow &window);
    void update_score();
    void tick(RenderWindow &window, Event &event);
    void draw(RenderWindow &window);
    void set_monsters_ability(bool monster_ability);
};
#endif