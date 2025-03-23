sfml-app: main.o
	g++ main.o -o sfml-app -L /home/lui/SFML-3.0.0/lib -lsfml-graphics -lsfml-window -lsfml-system
	export LD_LIBRARY_PATH=/home/lui/SFML-3.0.0/lib && ./sfml-app

main.o: main.cpp
	g++ -c main.cpp -I /home/lui/SFML-3.0.0/include
