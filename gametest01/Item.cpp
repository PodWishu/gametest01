#include "Item.h"

void Item::initTexture()
{
	if (!this->textureCoin.loadFromFile("coin.png"))
	{
		std::cout << "error::item::inittexture::could not load texture file" << "\n";
	}
}

void Item::initSprite()
{
	this->sprite.setTexture(this->textureCoin);
	this->currentFrame = sf::IntRect(0, 0, 56, 56);

	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(1.f, 1.f);
}

void Item::initVariables()
{
	this->speed = -2.f;
	this->points = 1000.f;
}

void Item::initAnimations()
{
	this->animationTimer.restart();
}

Item::Item(float pos_x, float pos_y)
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
	this->sprite.setPosition(pos_x, pos_y);
}

Item::~Item()
{
}


const sf::FloatRect Item::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Item::getPoints() const
{
	return this->points;
}

void Item::updateAnimations()
{
	if (this->animationTimer.getElapsedTime().asSeconds() >= 0.05f)
	{
		this->currentFrame.top = 0.f;
		this->currentFrame.left += 56.f;
		if (this->currentFrame.left >= 728.f)
			this->currentFrame.left = 0;
		this->animationTimer.restart();
		this->sprite.setTextureRect(this->currentFrame);
	}
}

void Item::update()
{
	this->updateAnimations();
	this->sprite.move(this->speed, 0.f);
}

void Item::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
