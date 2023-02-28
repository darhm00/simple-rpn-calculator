FLAGS=-Wall

all: build

build:
	g++ ./src/*.cpp $(FLAGS)
