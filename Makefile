CC=g++
LFLAGS=
INCFlAGS= -I"C:\Users\Araz\Documents\C++ Projects\Libraries\eigen-3.4.0" -I".\World" -I".\Objects" -I.
CFLAGS= -std=c++11 -Wconversion $(INCFlAGS)
CPP_FILES= main.cpp .\World\World.cpp
test: main

clean:
	del "*.o"
	del main.exe


# Executables
main:
	$(CC) $(CFLAGS) $(CPP_FILES) -o main


