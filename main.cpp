#include "player.h"
#include "asteroid.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>

void detectCollison(asteroid& Asteroid, player& Player)
{
	if (Player.getPosition().x + 28.0f <= Asteroid.getPosition().x + 100.0f && Player.isFiring() &&
		Player.getPosition().x + 28.0f >= Asteroid.getPosition().x)
		--Asteroid.health;

	if (Asteroid.getPosition().y >= 1199.8f)
	{
		--Player.health;
		std::cout << "You losedd 1 health. You have " << Player.health << " hp remaining" << std::endl;
	}
	if ((Player.getPosition().x + 60 > Asteroid.getPosition().x &&
		Player.getPosition().x < Asteroid.getPosition().x + 100) &&
		(Player.getPosition().y + 60 > Asteroid.getPosition().y &&
		Player.getPosition().y < Asteroid.getPosition().y + 100))
	{
		Player.health = 0;
	}
}

int main()
{
	srand(time(0));
	sf::Clock clock;
	int score = 0;

	sf::RenderWindow window(sf::VideoMode(1200, 900), "Survive!", sf::Style::Close | sf::Style::Titlebar);
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("background.png");

	sf::RectangleShape background;
	background.setSize(sf::Vector2f(1200.0f, 900.0f));
	background.setTexture(&backgroundTexture);

	player Player;
	asteroid Asteroid[20];
	int asteroidCount = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.draw(background);

		if (clock.getElapsedTime().asSeconds() > sf::Time(sf::seconds(5.0f)).asSeconds())
		{
			score += 5;
			if (asteroidCount < 19)
				++asteroidCount;

			clock.restart();
		}

		for (int x = 0; x < asteroidCount; ++x)
		{
			Asteroid[x].draw(window);
			detectCollison(Asteroid[x], Player);
			Asteroid[x].update();
		}

		Player.draw(window); 
		Player.move();
		Player.shoot(window);
		Player.update();

		window.display();
		window.clear();

		if (Player.health <= 0)
			window.close();
	}
	std::cout << "Your died! Your score was: "<< score << std::endl;
}