#SRC=main.cpp obj.cpp
SRC=$(wildcard src/*.cpp)
EXE=exe

CXXFLAGS+=-Wall -Wextra -MMD -g -p -std=c++11
LDFLAGS= #-lSDL

OBJ=$(addprefix build/,$(SRC:src/%.cpp=%.o)) #build/main.o
DEP=$(addprefix build/,$(OBJ:.o=.d))

all: $(OBJ)
	$(CXX) -o $(EXE) $^ $(LDFLAGS)

build/%.o: src/%.cpp 
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ -c $<
run: all 
	./$(EXE)
#build/main.o: main.cpp
#	@mkdir -p build
#	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf build core *.gch

-include $(DEP)
