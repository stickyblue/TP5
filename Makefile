FLAGS=-Wall -Werror -lm -g -std=c++20

Exercice : o/main.o o/WorldMap.o o/User.o o/GeneralUser.o o/EcoUser.o o/BigIndustrialLogisticUser.o
	g++ $(FLAGS) o/main.o o/WorldMap.o o/User.o o/GeneralUser.o o/EcoUser.o o/BigIndustrialLogisticUser.o -o Exercice

o/main.o: src/main.cpp
	g++ $(FLAGS) -c src/main.cpp -o o/main.o

o/WorldMap.o: src/WorldMap.cpp
	g++ $(FLAGS) -c src/WorldMap.cpp -o o/WorldMap.o

o/User.o: src/User.cpp
	g++ $(FLAGS) -c src/User.cpp -o o/User.o

o/GeneralUser.o: src/GeneralUser.cpp
	g++ $(FLAGS) -c src/GeneralUser.cpp -o o/GeneralUser.o

o/EcoUser.o: src/EcoUser.cpp
	g++ $(FLAGS) -c src/EcoUser.cpp -o o/EcoUser.o

o/BigIndustrialLogisticUser.o: src/BigIndustrialLogisticUser.cpp
	g++ $(FLAGS) -c src/BigIndustrialLogisticUser.cpp -o o/BigIndustrialLogisticUser.o

