#ifndef MAP_HH
#define MAP_HH
#include "main.hh"
#include "baby_turtle.hh"
#include "enemy.hh"
#include "ground.hh"
#include "monster.hh"
#include "player.hh"
#include "portal.hh"
#include "score_objects.hh"
class Map
{
private:
    vector<Ground> ground_vector;
    vector<Enemy> enemy_vector;
    vector<Monster> monster_vector;
    vector<Baby_Turtle> baby_turtle_vector;
    vector<Score_Objects> score_objects_vector;
    Portal portal;
    int initial_x, initial_y;

public:
    Map();
    void render(RenderWindow &window);
    void draw(RenderWindow &window);
    bool is_ground(int x, int y, FloatRect global_bounds);
    int get_initial_x();
    int get_initial_y();
    void fetch_vecotrs(vector<Enemy> &_enemy_vector, vector<Monster> &_monster_vector, vector<Baby_Turtle> &_baby_turtle_vector, vector<Score_Objects> &_score_objects_vector);
    FloatRect get_portal_bounds();
};
#endif