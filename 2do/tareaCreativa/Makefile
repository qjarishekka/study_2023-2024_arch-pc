

all: compile link

compile: 
	g++ -c main.cpp -IC:/SFML-2.6.1/include -DSFML_STATIC

link: 
	g++ main.o -o main -LC:/SFML-2.6.1/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows

