#include "main.hh"
#include "ground.hh"
#include "baby_turtle.hh"
#include "score_objects.hh"
#include "monster.hh"
#include "enemy.hh"
#include "portal.hh"
#include "player.hh"
#include "map.hh"
#include "turtix.hh"

int main()
{
    RenderWindow window(VideoMode().getDesktopMode(), "Turtix", Style::Fullscreen);
    bool game_is_open = true;
    Turtix turtix;
    bool monster_ability;
    Clock clock;
    Clock monster_clock;
    Event event;
    turtix.start(window);
    while (window.isOpen())
    {
        window.pollEvent(event);
        if (event.type == Event::Closed)
        {
            window.close();
            break;
        }
        if (clock.getElapsedTime() >= milliseconds(50))
        {
            turtix.tick(window, event);
            clock.restart();
        }
        if (monster_clock.getElapsedTime() >= seconds(10))
        {
            monster_ability = true;
            turtix.set_monsters_ability(monster_ability);
            monster_clock.restart();
        }
        if ((monster_ability == true) && (monster_clock.getElapsedTime() >= seconds(4)))
        {
            monster_ability = false;
            turtix.set_monsters_ability(monster_ability);
            monster_clock.restart();
        }
        if (event.type == Event::MouseButtonPressed)
            turtix.restart();
        turtix.draw(window);
        window.display();
    }

    return 0;
}