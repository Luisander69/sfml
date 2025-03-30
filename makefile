sfml-app: main.o Game.o Player.o
	g++ main.o Game.o Player.o -o sfml-app -L /home/lui/SFML-3.0.0/lib -lsfml-graphics -lsfml-window -lsfml-system
	export LD_LIBRARY_PATH=/home/lui/SFML-3.0.0/lib && ./sfml-app

main.o: main.cpp Game.h Player.h
	g++ -c main.cpp -I /home/lui/SFML-3.0.0/include

Game.o: Game.cpp Game.h Player.h
	g++ -c Game.cpp -I /home/lui/SFML-3.0.0/include

Player.o: Player.cpp Player.h
	g++ -c Player.cpp -I /home/lui/SFML-3.0.0/include

clean:
	rm -f *.o sfml-app
