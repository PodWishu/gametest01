#include "Player.h"

void Player::initVariables()
{
	this->moving = false;

	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;

	this->hpMax = 10;
	this->hp = this->hpMax;
}

void Player::initTexture()
{
	if (!this->textureSheet.loadFromFile("perfectredship.png"))
	{
		std::cout << "error::player::inittexture::could not load texture file" << "\n";
	}
}

void Player::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->sprite.setPosition(300.f, 360.f);
	this->currentFrame = sf::IntRect(0, 0, 152, 44);

	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(1.25f, 1.25f);

	this->hitbox.setPosition(370.f, 370.f);
	this->hitbox.setSize(sf::Vector2f(120, 35));
	this->hitbox.setFillColor(sf::Color::Transparent);
	this->hitbox.setOutlineThickness(0);
	this->hitbox.setOutlineColor(sf::Color::Green);
}

void Player::initAnimations()
{
	this->animationTimer.restart();
}

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();

}

Player::~Player()
{

}

const sf::Vector2f& Player::getPos() const
{
	return this->hitbox.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return this->hitbox.getGlobalBounds();
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}


void Player::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
	this->hitbox.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x - 70.f, y - 10);
	this->hitbox.setPosition(x, y);
}

void Player::setHp(const int hp)
{
	this->hp = hp;
}

void Player::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}

void Player::attackup(float cool)
{
	attackCooldown = cool + attackCooldown;
}



//function


const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	return false;
}

void Player::updateMovement()
{
	this->moving = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //left
	{
		this->sprite.move(-1.35f, 0.f);
		this->hitbox.move(-1.35f, 0.f);
		this->moving = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //right
	{
		this->sprite.move(1.35f, 0.f);
		this->hitbox.move(1.35f, 0.f);
		this->moving = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) //top
	{
		this->sprite.move(0.f, -1.35f);
		this->hitbox.move(0.f, -1.35f);
		this->moving = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) //down
	{
		this->sprite.move(0.f, 1.35f);
		this->hitbox.move(0.f, 1.35f);
		this->moving = true;
	}
}

void Player::updateAnimations()
{

	if (this->animationTimer.getElapsedTime().asSeconds() >= 0.04f)
	{
		if (this->moving == false)//idle animation
		{
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 152.f;
			if (this->currentFrame.left >= 608.f)
				this->currentFrame.left = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			this->currentFrame.top = 44.f;
			this->currentFrame.left += 152.f;
			if (this->currentFrame.left >= 608.f)
				this->currentFrame.left = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			this->currentFrame.top = 88.f;
			this->currentFrame.left += 152.f;
			if (this->currentFrame.left >= 608.f)
				this->currentFrame.left = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			this->currentFrame.top = 132.f;
			this->currentFrame.left += 152.f;
			if (this->currentFrame.left >= 608.f)
				this->currentFrame.left = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			this->currentFrame.top = 176.f;
			this->currentFrame.left += 152.f;
			if (this->currentFrame.left >= 608.f)
				this->currentFrame.left = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			this->currentFrame.top = 220.f;
			this->currentFrame.left += 152.f;
			if (this->currentFrame.left >= 608.f)
				this->currentFrame.left = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			this->currentFrame.top = 264.f;
			this->currentFrame.left += 152.f;
			if (this->currentFrame.left >= 608.f)
				this->currentFrame.left = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			this->currentFrame.top = 308.f;
			this->currentFrame.left += 152.f;
			if (this->currentFrame.left >= 608.f)
				this->currentFrame.left = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			this->currentFrame.top = 352.f;
			this->currentFrame.left += 152.f;
			if (this->currentFrame.left >= 608.f)
				this->currentFrame.left = 0;
		}

		this->animationTimer.restart();
		this->sprite.setTextureRect(this->currentFrame);
	}
}

void Player::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += 0.175f;
}

void Player::update()
{
	this->updateMovement();
	this->updateAnimations();
	this->updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
	target.draw(this->hitbox);
}
