
.PHONY: build run

build: ANN.h ANN.cpp main.cpp
	@g++ ANN.cpp main.cpp -o main.exe -std=c++11

run: build
	@./main.exe