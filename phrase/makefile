INCLUDE = ./include
OBJ     = ./obj
SRC     = ./src
APP     = ./app
BIN     = ./bin
TARGET  = $(BIN)/genetic
FILE    = $(APP)/genetic.cpp

all: libed apps

libed:                \
	build               \
	$(OBJ)/Population.o \
	$(OBJ)/DNA.o        \
	$(OBJ)/Target.o

apps: $(TARGET)

build:
	@mkdir -p $(OBJ)
	@mkdir -p $(BIN)

$(OBJ)/%.o: $(SRC)/%.cpp $(INCLUDE)/%.hpp
	g++ -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APP)/%.cpp
	g++ -g $< $(OBJ)/*.o -I $(INCLUDE) -o $@

clean:
	rm -rf $(BIN)
	rm -rf $(OBJ)
