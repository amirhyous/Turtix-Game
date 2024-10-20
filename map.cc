#ifndef MAP_CC
#define MAP_CC
#include "map.hh"
Map::Map() : portal(0, 0), initial_x(0), initial_y(0)
{
    fstream file("map/map.txt");
    string line;
    int x = (220 * GROUND_MUL) / 2, y = LINE_HEIGHT / 2;
    while (getline(file, line))
    {
        x = 0;
        for (int i = 0; i < line.size(); i++)
        {
            switch (line[i])
            {
            case '.':
            {
                Ground *g = new Ground(x, y);
                ground_vector.push_back(*g);
                break;
            }
            case 'E':
            {
                Enemy *e = new Enemy(x, y);
                enemy_vector.push_back(*e);
                break;
            }
            case 'M':
            {
                Monster *m = new Monster(x, y);
                monster_vector.push_back(*m);
                break;
            }
            case 'O':
            {
                Baby_Turtle *bt = new Baby_Turtle(x, y);
                baby_turtle_vector.push_back(*bt);
                break;
            }
            case '*':
            {
                Score_Objects *sb = new Score_Objects(x, y, STAR);
                score_objects_vector.push_back(*sb);
                break;
            }
            case '^':
            {
                Score_Objects *sb = new Score_Objects(x, y, DIAMOND);
                score_objects_vector.push_back(*sb);
                break;
            }
            case '$':
            {
                initial_x = x;
                initial_y = y + LINE_HEIGHT / 2;
                portal.set_position(initial_x, initial_y);
                break;
            }

            default:
                break;
            }
            x += 220 * GROUND_MUL;
        }
        y += LINE_HEIGHT;
    }
}
void Map::render(RenderWindow &window)
{
    window.clear();
    for (int i = 0; i < ground_vector.size(); i++)
        ground_vector[i].draw(window);
    portal.draw(window);
}
void Map::draw(RenderWindow &window)
{
    for (int i = 0; i < baby_turtle_vector.size(); i++)
        baby_turtle_vector[i].draw(window);
    for (int i = 0; i < enemy_vector.size(); i++)
        enemy_vector[i].draw(window);
    for (int i = 0; i < monster_vector.size(); i++)
        monster_vector[i].draw(window);
    for (int i = 0; i < score_objects_vector.size(); i++)
        score_objects_vector[i].draw(window);
}
bool Map::is_ground(int x, int y, FloatRect global_bounds)
{
    global_bounds.left = x - global_bounds.width / 2;
    global_bounds.top = y - global_bounds.height / 2;
    for (int i = 0; i < ground_vector.size(); i++)
    {
        if (ground_vector[i].intersects(global_bounds))
            return true;
    }
    return false;
}
int Map::get_initial_x() { return initial_x; }
int Map::get_initial_y() { return initial_y; }
void Map::fetch_vecotrs(vector<Enemy> &_enemy_vector, vector<Monster> &_monster_vector, vector<Baby_Turtle> &_baby_turtle_vector, vector<Score_Objects> &_score_objects_vector)
{
    _enemy_vector = enemy_vector;
    _monster_vector = monster_vector;
    _baby_turtle_vector = baby_turtle_vector;
    _score_objects_vector = score_objects_vector;
}
FloatRect Map::get_portal_bounds() { return portal.getGlobalBounds(); }
#endif