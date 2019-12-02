#include "player.h"
#include <SFML/Graphics.hpp>
#include <iostream>

player::player()
{
	isfiring = false;
	speed = 0.5;
	health = 10;
	damage = 1;
	laser.setSize(sf::Vector2f(4.0f, 0.0f));
	laser.setFillColor(sf::Color::Red);
	texture.loadFromFile("player-texture.png");
	sprite.setTexture(texture);
	hitbox.setSize(sf::Vector2f(60.0f, 60.0f));
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setPosition(600.0f, 450.0f);
}

void player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		hitbox.move(sf::Vector2f(0.0f, -speed));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		hitbox.move(sf::Vector2f(-speed, 0.0f));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		hitbox.move(sf::Vector2f(0.0f, speed));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		hitbox.move(sf::Vector2f(speed, 0.0f));

	if (hitbox.getPosition().x > 1140.0)
		hitbox.move(sf::Vector2f(-1.0f, 0.0f));
	if (hitbox.getPosition().x < 0.0)
		hitbox.move(sf::Vector2f(1.0f, 0.0f));
	if (hitbox.getPosition().y > 840.0)
		hitbox.move(sf::Vector2f(0.0f, -1.0f));
	if (hitbox.getPosition().y < 0.0)
		hitbox.move(sf::Vector2f(0.0f, 1.0f));
}

void player::draw(sf::RenderWindow &window)
{
	window.draw(hitbox);
	window.draw(sprite);
}

void player::update()
{
	sprite.setPosition((hitbox.getPosition()));
}

sf::Vector2f player::getPosition()
{
	return hitbox.getPosition();
}

void player::shoot(sf::RenderWindow &window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		laser.setSize(sf::Vector2f(4.0f, hitbox.getPosition().y));
		laser.setPosition(sf::Vector2f((hitbox.getPosition().x) + 28.0, 0.0));
		speed = 0.2;
		isfiring = true;
		window.draw(laser);
	}
	else
	{
		speed = 0.5;
		isfiring = false;
	}
}

bool player::isFiring()
{
	return isfiring;
}