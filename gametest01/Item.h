#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
class Item
{
private:
	unsigned pointCount;
	sf::Sprite sprite;
	sf::Texture textureCoin;
	sf::Clock animationTimer;
	float speed;
	int points;

	sf::IntRect currentFrame;

	void initTexture();
	void initSprite();
	void initVariables();
	void initAnimations();

public:

	Item(float pos_x, float pos_y);
	virtual ~Item();

	//accessors
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;

	//function
	void updateAnimations();
	void update();
	void render(sf::RenderTarget* target);
};

