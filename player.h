#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class player
{
public:
	player();
	void move();
	void shoot(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void update();
	bool isFiring();
	sf::Vector2f getPosition();
	int health;
private:
	bool isfiring;
	float speed;
	int damage;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::RectangleShape hitbox;
	sf::RectangleShape laser;
};