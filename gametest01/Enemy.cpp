#include "Enemy.h"

void Enemy::initTexture()
{
	if (!this->textureEnemy.loadFromFile("enemycom01.png"))
	{
		std::cout << "error::enemy::inittexture::could not load texture file" << "\n";
	}
}

void Enemy::initSprite()
{
	this->sprite.setTexture(this->textureEnemy);
	this->sprite.setOrigin(60.f, 40.f);
	this->currentFrame = sf::IntRect(0, 0, 120, 80);

	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(1.f, 1.f);
}

void Enemy::initVariables()
{
	this->pointCount = rand() & 8 + 3; // min = 3 max = 10
	this->type = 0;
	this->speedx = static_cast<float>(rand() % 4 - 6);
	this->speedy = static_cast<float>(rand() % 3 - 1);
	this->hp = static_cast<float>(this->pointCount);
	this->hpMax = 0;
	this->damage = 2.f;
	this->points = 500.f;
}

void Enemy::initAnimations()
{
	this->animationTimer.restart();
}

Enemy::Enemy(float pos_x, float pos_y)
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
	this->sprite.setPosition(pos_x, pos_y);

}

Enemy::~Enemy()
{
}


const sf::FloatRect Enemy::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Enemy::getPoints() const
{
	return this->points;
}

const int& Enemy::getDamage() const
{
	return this->damage;
}

void Enemy::updateAnimations()
{
	if (this->animationTimer.getElapsedTime().asSeconds() >= 0.05f)
	{
		this->currentFrame.top = 0.f;
		this->currentFrame.left += 120.f;
		if (this->currentFrame.left >= 600.f)
			this->currentFrame.left = 0;
		this->animationTimer.restart();
		this->sprite.setTextureRect(this->currentFrame);
	}
}

//function
void Enemy::update()
{
	this->updateAnimations();
	this->sprite.move(this->speedx, this->speedy);
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
