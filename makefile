CC = g++ -std=c++11
EXE_FILE = turtix.out
CCFLAGS += -lsfml-graphics -lsfml-window -lsfml-system
&(EXE_FILE) : main.o ground.o baby_turtle.o score_objects.o monster.o enemy.o portal.o player.o map.o turtix.o
	$(CC) main.o ground.o baby_turtle.o score_objects.o monster.o enemy.o portal.o player.o map.o turtix.o $(CCFLAGS) -o $(EXE_FILE)

main.o: main.cc ground.hh baby_turtle.hh score_objects.hh monster.hh enemy.hh portal.hh player.hh map.hh turtix.hh
	$(CC) -c main.cc -o main.o

ground.o: ground.cc ground.hh main.hh
	$(CC) -c ground.cc -o ground.o

baby_turtle.o: baby_turtle.cc baby_turtle.hh main.hh
	$(CC) -c baby_turtle.cc -o baby_turtle.o

score_objects.o: score_objects.cc score_objects.hh main.hh
	$(CC) -c score_objects.cc -o score_objects.o 

monster.o: monster.cc monster.hh main.hh
	$(CC) -c monster.cc -o monster.o

enemy.o: enemy.cc enemy.hh main.hh
	$(CC) -c enemy.cc -o enemy.o

portal.o: portal.cc portal.hh main.hh
	$(CC) -c portal.cc -o portal.o 

player.o: player.cc player.hh main.hh
	$(CC) -c player.cc -o player.o

map.o: map.cc map.hh baby_turtle.hh enemy.hh ground.hh monster.hh player.hh portal.hh score_objects.hh main.hh
	$(CC) -c map.cc -o map.o 

turtix.o: turtix.cc turtix.hh baby_turtle.hh enemy.hh ground.hh map.hh monster.hh player.hh portal.hh score_objects.hh main.hh
	$(CC) -c turtix.cc -o turtix.o
clean:
	rm *.o $(EXE_FILE)