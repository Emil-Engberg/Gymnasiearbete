all: main.cpp compute.cpp input.cpp draw.cpp
	sudo apt-get install g++ make libsfml-dev
	g++ -std=c++17 -O2 -c main.cpp compute.cpp input.cpp draw.cpp
	g++ -o main main.o compute.o input.o draw.o  -lsfml-graphics -lsfml-window -lsfml-system
	rm *.o
clean:
	rm main
