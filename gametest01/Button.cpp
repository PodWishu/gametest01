#include "Button.h"

void Button::initSound()
{
	if (!this->pressSound.loadFromFile("PressButton.wav"))
	{
		std::cout << "error::game::could not load sound menu" << "\n";
	}
	this->getPressSound.setBuffer(this->pressSound);
	this->getPressSound.setVolume(3.f);
}

Button::Button(float x, float y, float width, float height,
	sf::Font* font, std::string text,
	sf::Color idleColor, sf::Color hoverColor, sf::Color ActiveColor)
{
	this->buttonState = BTN_IDLE;

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(24);
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
	);

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->shape.setFillColor(this->idleColor);

	this->initSound();

}

Button::~Button()
{

}

const bool Button::isPressed() const
{
	if (this->buttonState == BTN_ACTIVE)
		return true;

	return false;
}

//function

void Button::update(const sf::Vector2f mousePos)
{
	/*update the booleans for hover and pressed*/

	//idle
	this->buttonState = BTN_IDLE;

	//Hover

	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = BTN_HOVER;

		//pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->getPressSound.play();
			this->buttonState = BTN_ACTIVE;
		}
	}

	switch (this->buttonState)
	{
	case BTN_IDLE:
		this->shape.setFillColor(this->idleColor);
		break;

	case BTN_HOVER:
		this->shape.setFillColor(this->hoverColor);
		break;

	case BTN_ACTIVE:
		this->shape.setFillColor(this->activeColor);
		break;

	default:
		this->shape.setFillColor(sf::Color::Red);
		break;
	}
}

void Button::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->text);
}
