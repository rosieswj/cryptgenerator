CC=gcc
CXX=g++
RM=rm -f

CFLAGS=-g -O3 -Wall  -std=c++11
LDFLAGS= -lm

CFILES = num_generator.cpp 	exp.cpp operator.cpp binaryexp.cpp 	crypt.cpp main.cpp
HFILES = num_generator.h		exp.h  	operator.h  binaryexp.h  crypt.h

image: $(CFILES) $(HFILES)
	$(CXX) $(CFLAGS) $(LDFLAGS) $(OMP) -o solveCryptarithm $(CFILES)

clean:
	$(RM) -f solveCryptarithm
	$(RM) -rf *.dSYM

