// sfmlSimpleSnake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <time.h>
#include <conio.h>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>

//size variables
int N = 30, M = 20;
int size = 16;
int w = size * N;
int h = size * M;
int num = 2;
int dir = 0;
int score = 0;
//snake
struct snake {
	int x = 5, y = 5;
} s[100];

//fruit
struct fruit {
	int x, y;
} f;

void gameLogic() {
	for (int i = num; i > 0; i--) {
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y; 
	}
	if (dir == 0) { s[0].y += 1; }
	if (dir == 1) { s[0].y -= 1; }
	if (dir == 2) { s[0].x += 1; }
	if (dir == 3) { s[0].x -= 1; }
	if ((s[0].x == f.x) && (s[0].y == f.y)) {
		num++;
		score++;
		f.x = rand() % N;
		f.y = rand() % M;
	}
}

int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(w, h), "SFML Works");
	//insert textures
	sf::Texture t1, t2, t3, t4, t5, t6;
	t1.loadFromFile("Data/background.png");
	t2.loadFromFile("Data/fruit.png");
	t3.loadFromFile("Data/snake.png");
	t4.loadFromFile("Data/snake1.png");
	t5.loadFromFile("Data/tail.png");

	sf::Sprite sBackground(t1), sFruit(t2), sSnake(t3), sSnake1(t4), sTail(t5);

	sf::Clock clock;
	float timer = 0, delay = 0.1;
	while (window.isOpen()) {

		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		sf::Event event;
		while (window.pollEvent(event)) {
			//closing mechanism
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape) {
				window.close();
			}
		}
		//keyboard events
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { dir = 3; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { dir = 2; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { dir = 1; }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { dir = 0; }

		if (timer > delay) {
			timer = 0; 
			gameLogic();
		}

		window.clear();
		//draw background
		window.draw(sBackground);
		sFruit.setPosition(f.x*size, f.y*size);
		window.draw(sFruit);
		for (int i = 1; i < num - 1; i++) {
			sSnake.setPosition(s[i].x*size, s[i].y*size);
			window.draw(sSnake);
		}
		sSnake1.setPosition(s[0].x*size, s[0].y*size);
		window.draw(sSnake1);
		window.display();
	}

	return 0;
}

