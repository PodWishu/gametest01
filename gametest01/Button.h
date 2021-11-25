#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <sstream>

#include <iostream>
#include <ctime>
#include <cstdlib>

enum button_state { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };

class Button
{
private:
	short unsigned buttonState;

	//sound
	sf::SoundBuffer pressSound;
	sf::Sound getPressSound;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

	void initSound();


public:
	Button(float x,float y, float width, float height, 
		sf::Font* font, std::string text,
		sf::Color idleColor, sf::Color hoverColor, sf::Color ActiveColor);
	~Button();

	//accessors
	const bool isPressed() const;

	//function
	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);

};

