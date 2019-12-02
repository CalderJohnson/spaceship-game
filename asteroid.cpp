#include "asteroid.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>

asteroid::asteroid()
{
	health = 500;
	texture.loadFromFile("asteroid-texture.png");
	sprite.setTexture(texture);
	hitbox.setSize(sf::Vector2f(100.0f, 100.0f));
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setPosition(sf::Vector2f((float (rand() % 1140)), 0.0f));
}

void asteroid::draw(sf::RenderWindow& window)
{
	window.draw(hitbox);
	window.draw(sprite);
}

void asteroid::update()
{
	hitbox.move(sf::Vector2f(float (1 - rand() % 3), 0.2f));
	sprite.setPosition(hitbox.getPosition());

	if (hitbox.getPosition().y >= 1200.0f || health <= 0)
	{
		hitbox.setPosition(sf::Vector2f((float(rand() % 1140)), -500.0f));
		health = 500;
	}
}

sf::Vector2f asteroid::getPosition()
{
	return hitbox.getPosition();
}