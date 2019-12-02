#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class asteroid
{
public:
	asteroid();
	void draw(sf::RenderWindow& window);
	void update();
	sf::Vector2f getPosition();
	int health;
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::RectangleShape hitbox;
};
