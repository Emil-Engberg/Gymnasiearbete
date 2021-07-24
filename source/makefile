all: main.cpp compute.cpp input.cpp
	g++ -std=c++17  -O2 -c main.cpp compute.cpp input.cpp
	g++ -o build/main main.o compute.o input.o
	rm *.o
clean:
	rm main
dep:
	sudo apt-get install make g++
