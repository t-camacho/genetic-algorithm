INCLUDE = -Iinclude
OBJ     = ./obj
SRC     = ./src
APP     = ./app
BIN     = ./bin

all:
	g++ -c $(SRC)/Population.cpp $(INCLUDE) -o $(OBJ)/Populatio.o
	g++ -c $(SRC)/DNA.cpp $(INCLUDE) -o $(OBJ)/DNA.o
	g++ $(APP)/genetic.cpp $(OBJ)/*.o $(INCLUDE) -o $(BIN)/genetic

