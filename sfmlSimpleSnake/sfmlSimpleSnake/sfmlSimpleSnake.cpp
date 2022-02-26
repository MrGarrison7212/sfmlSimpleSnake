// sfmlSimpleSnake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>

//size variables
int N = 30, M = 20;
int size = 16;
int w = size * N;
int h = size * M;


int main()
{
	sf::RenderWindow window(sf::VideoMode(w, h), "SFML Works");
	//insert textures
	sf::Texture t1, t2, t3, t4, t5, t6;
	t1.loadFromFile("Data/background.png");
	t2.loadFromFile("Data/fruit.png");
	t3.loadFromFile("Data/snake.png");
	t4.loadFromFile("Data/snake1.png");
	t5.loadFromFile("Data/tail.png");

	sf::Sprite sBackground(t1), sFruit(t2), sSnake(t3), sSnake1(t4), sTail(t5);

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {


		}

		window.clear();
		window.display();
	}

	return 0;
}

