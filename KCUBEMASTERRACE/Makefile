
CXXFLAGS=-Wall
CXX=g++

lol: combinat.o cube.o cubepars.o facecube.o kcube.o kocicube.o movetabl.o pruningt.o solver.o vector.o
	$(CXX) -o $@ $^
	
clean:
	rm -f lol *.o
	
combinat.o: combinat.cpp
cube.o: cube.cpp
cubepars.o: cubepars.cpp
facecube.o: facecube.cpp
kcube.o: kcube.cpp
kocicube.o: kocicube.cpp
movetabl.o: movetabl.cpp
pruningt.o: pruningt.cpp
solver.o: solver.cpp
vector.o: vector.cpp

