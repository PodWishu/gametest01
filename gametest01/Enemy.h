#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Enemy
{
private:
	unsigned pointCount;
	sf::Sprite sprite;
	sf::Texture textureEnemy;
	sf::Clock animationTimer;
	int type;
	float speedx;
	float speedy;
	int hp;
	int hpMax;
	int damage;
	int points;

	sf::IntRect currentFrame;

	void initTexture();
	void initSprite();
	void initVariables();
	void initAnimations();

public:

	Enemy(float pos_x, float pos_y);
	virtual ~Enemy();

	//accessors
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamage() const;

	//function
	void updateAnimations();
	void update();
	void render(sf::RenderTarget* target);


};

