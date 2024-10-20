#ifndef MAIN_HH
#define MAIN_HH

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
using namespace sf;

const double GROUND_MUL = 1;

const int LINE_HEIGHT = 200;

const int JUMP_Hight = 200;
enum Score_Objects_Type
{
    STAR,
    DIAMOND
};
enum Direction
{
    LEFT,
    UP,
    RIGHT,
    DOWN
};
const int delta_x[4] = {-1, 0, 1, 0};
const int delta_y[4] = {0, -1, 0, 1};
const int STEP_SIZE = 10;
const int EVIL_MAX_MOVE = 50;
const int EVIL_STEP = 5;
const int ENEMY_LIVES = 2;
const int MONSTER_LIVES = 1;
const int PLAYER_LIVES = 1;
const int VIEW_WIDTH = 1000;
const int VIEW_HEIGHT = 1000;

#endif