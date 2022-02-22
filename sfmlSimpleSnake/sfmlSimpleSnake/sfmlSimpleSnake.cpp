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

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {


		}

		window.clear();
		window.display();
	}

	return 0;
}

