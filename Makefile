CC=g++
LFLAGS= -L"C:\Users\Araz\Documents\C++ Projects\Libraries\SFML-2.6.1\lib" -l"sfml-graphics" -l"sfml-window" -"lsfml-system"
INCFlAGS= -I"C:\Users\Araz\Documents\C++ Projects\Libraries\eigen-3.4.0" -I".\World" -I".\Objects" -I. -I"C:\Users\Araz\Documents\C++ Projects\Libraries\SFML-2.6.1\include"
CFLAGS= -std=c++11 -Wconversion $(INCFlAGS)
CPP_FILES= main.cpp .\World\World.cpp

test: main

clean:
	del "*.o"
	del .\Out\main.exe


# Executables
main:
	$(CC) -m32 -o .\Out\main $(CPP_FILES) $(CFLAGS) $(LFLAGS)

run:
	.\Out\main.exe
