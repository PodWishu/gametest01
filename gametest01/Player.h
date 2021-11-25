#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


class Player
{
private:
	sf::Sprite sprite;
	sf::Texture textureSheet;
	bool moving;
	sf::Clock animationTimer;

	//hitbox
	sf::RectangleShape hitbox;

	float attackCooldown;
	float attackCooldownMax;

	int hp;
	int hpMax;

	//animation
	sf::IntRect currentFrame;


	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimations();

public:
	Player();
	virtual ~Player();

	//accessor
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	const int& getHp() const;
	const int& getHpMax() const;

	//modifiers
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);
	void setHp(const int hp);
	void loseHp(const int value);
	void attackup(float cool);

	//function
	const bool canAttack();

	void updateMovement();
	void updateAnimations();
	void updateAttack();
	void update();
	void render(sf::RenderTarget& target);

};

