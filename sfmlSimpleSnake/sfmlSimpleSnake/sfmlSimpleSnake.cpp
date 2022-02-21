// sfmlSimpleSnake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Works");

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {


		}

		window.clear();
		window.display();
	}

	return 0;
}

