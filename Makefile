CXX=g++
CXXFLAGS=-std=c++11
LIBS=-lGLEW -lGL -lglfw
SRC=main.cpp
EXE=space_invader

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXE) $(LIBS)

clean:
	rm -f $(EXE)