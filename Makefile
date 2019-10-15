#Makefile

CXX=clang++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

ascending: ascendingPhoto.o
	${CXX} $^ -o $@

train: trainSorting.o
	${CXX} $^ -o $@

clean:
	rm -f *.o ascending train