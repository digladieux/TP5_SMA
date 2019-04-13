#SRC=main.cpp obj.cpp
SRC=$(wildcard src/*.cpp)
EXE=exe

CXXFLAGS+=-Wall -Wextra -MMD -p -std=c++11
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

check:
	@cppcheck --enable=style -i src/mt19937ar.cpp --suppress='*:header/json.hpp' --suppress='*:header/catch.hpp' src/ 2> cppcheck.txt -j 4

clean:
	rm -rf build core *.gch

-include $(DEP)
