#include "Game.h"

//private function
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "H:SW", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(144);
}

void Game::initKeys()
{

	//DEBUG remove later
	for (auto i : this->supportedKeys)
	{
		std::cout << i.first << " " << i.second << "\n";
	}
}

void Game::initStates()
{
	this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
	
}

/*void Game::initTexture()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("bullet02.png");
}

void Game::initGUI()
{
	//load font
	if (!this->font.loadFromFile("Pixellari.ttf"))
		std::cout << "error::game::failed to load font" << "\n";

	//init point text
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(25);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setString("test");

	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(100);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setString("Game Over");
	this->gameOverText.setPosition(
		this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f);

	//init player Gui
	this->playerHpBar.setSize(sf::Vector2f(150.f, 20.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(20.f, 40.f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));

}

void Game::initWorld()
{
	if (!this->worldBackgroungTex.loadFromFile("night city.png"))
	{
		std::cout << "error::game::could not load background texture" << "\n";
	}
	this->worldBackground.setTexture(this->worldBackgroungTex);
}

void Game::initSound()
{
	if (!this->shoot.loadFromFile("Shoot01.wav"))
	{
		std::cout << "error::game::could not load sound" << "\n";
	}
	this->shootSound.setBuffer(this->shoot);
	this->shootSound.setVolume(4.f);

	if (!this->coin.loadFromFile("Getcoin01.wav"))
	{
		std::cout << "error::game::could not load sound" << "\n";
	}
	this->getCoin.setBuffer(this->coin);
	this->getCoin.setVolume(4.f);

	if (!this->boom.loadFromFile("EnemyBoom.wav"))
	{
		std::cout << "error::game::could not load sound" << "\n";
	}
	this->enemyBoom.setBuffer(this->boom);
	this->enemyBoom.setVolume(3.f);

	if (!this->collisionShip.loadFromFile("Collision01.wav"))
	{
		std::cout << "error::game::could not load sound" << "\n";
	}
	this->collShip.setBuffer(this->collisionShip);
	this->collShip.setVolume(3.f);

	if (!this->musicPlay.openFromFile("JeremyBlakePowerup.ogg"))
	{
		std::cout << "error::game::could not load music" << "\n";
	}
	this->musicPlay.setVolume(5.f);
	this->musicPlay.setLoop(true);
	this->musicPlay.play();

}

void Game::initSystems()
{
	this->points = 0;
}

void Game::initPlayer()
{
	this->player = new Player();

}

void Game::initEnemies()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;
}

void Game::initCoins()
{
	this->spawnTimerItemMax = 50.f;
	this->spawnTimerItem = this->spawnTimerItemMax;
}
*/

//con/des
Game::Game()
{
	this->initWindow();
	this->initStates();
	this->initKeys();
	/*this->initTexture();
	this->initGUI();
	this->initWorld();
	this->initSound();
	this->initSystems();
	this->initPlayer();
	this->initEnemies();
	this->initCoins();*/
}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}

	/*delete this->player;

	//delete texture
	for (auto& i : this->textures)
	{
		delete i.second;
	}

	//delete bullets
	for (auto* i : this->bullets)
	{
		delete i;
	}

	//delete enemies
	for (auto* i : this->enemies)
	{
		delete i;
	}

	//delete items
	for (auto* i : this->items)
	{
		delete i;
	}*/
}

void Game::endApplication()
{
	std::cout << "ending  application" << "\n";
}



void Game::updatePollEvent()
{
	//polling window event
	while (this->window->pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::updateDt()
{
	this->dt = this->dtClock.getElapsedTime().asSeconds();
}

/*void Game::updatePlayer()
{
	this->player->update();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
	{
		this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 175.f, this->player->getPos().y + 50.f, 1.f, 0.f, 5.f));
		this->shootSound.play();
	}
}

void Game::updateGUI()
{
	std::stringstream ss;
	ss << "Points : " << this->points;
	this->pointText.setString(ss.str());

	//update playerGUI

	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(150.f * hpPercent, this->playerHpBar.getSize().y));

}

void Game::updateWorld()
{

}

void Game::updateCollision()
{
	//left world collision
	if (this->player->getBounds().left < -70.f)
	{
		this->player->setPosition(-70.f, this->player->getBounds().top);
	}

	//right world collision
	else if (this->player->getBounds().left > 1090.f)
	{
		this->player->setPosition(1090.f, this->player->getBounds().top);
	}

	//top world collision
	if (this->player->getBounds().top < 0.f)
	{
		this->player->setPosition(this->player->getBounds().left, 0.f);
	}

	//bottom world collision
	else if (this->player->getBounds().top > 676.f)
	{
		this->player->setPosition(this->player->getBounds().left, 676.f);
	}

}

void Game::updateEnemies()
{
	//spawning
	this->spawnTimer += 2.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemy(1380.f, rand() % this->window->getSize().y - 20.f));
		this->spawnTimer = 0.f;
	}

	//update
	unsigned counter = 0;
	for (auto* enemy : this->enemies)
	{
		enemy->update();

		//enemy culling (left of screen)
		if (enemy->getBounds().left < -100.f)
		{
			//delete enemy
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}
		//enemy player collision
		else if (enemy->getBounds().intersects(this->player->getBounds()))
		{
			this->collShip.play();
			this->player->loseHp(this->enemies.at(counter)->getDamage());
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}
		++counter;
	}
}

void Game::updateCoins()
{
	//spawn item 
	this->spawnTimerItem += 0.05f;
	if (this->spawnTimerItem >= this->spawnTimerItemMax)
	{
		this->items.push_back(new Item(1380.f, rand() % this->window->getSize().y - 20.f));
		this->spawnTimerItem = 0.f;
	}

	//update
	unsigned counter = 0;
	for (auto* item : this->items)
	{
		item->update();

		//enemy culling (left of screen)
		if (item->getBounds().left < -100.f)
		{
			//delete enemy
			delete this->items.at(counter);
			this->items.erase(this->items.begin() + counter);
			--counter;
		}

		++counter;
	}
}

void Game::updateCombat()
{
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_delete = false;
		for (size_t k = 0; k < this->bullets.size() && enemy_delete == false; k++)
		{
			if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				this->points += this->enemies[i]->getPoints();
				this->enemyBoom.play();
				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);


				enemy_delete = true;
			}
		}
	}
	for (int i = 0; i < this->items.size(); ++i)
	{
		bool item_delete = false;
		if (this->items[i]->getBounds().intersects(this->player->getBounds()))
		{
			this->points += this->items[i]->getPoints();

			this->getCoin.play();
			delete this->items[i];
			this->items.erase(this->items.begin() + i);

			item_delete = true;
		}

	}

}

void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();

		//bullet culling (right of screen)
		if (bullet->getBounds().left + bullet->getBounds().width > 1280.f)
		{
			//delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);

		}

		++counter;
	}
}*/

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->updatePollEvent();
		//if (this->player->getHp() > 0)
		this->update();

		this->render();
	}
}

//function
void Game::update()
{

	/*this->updatePlayer();
	this->updateCollision();
	this->updateBullets();
	this->updateEnemies();
	this->updateCoins();
	this->updateCombat();
	this->updateGUI();
	this->updateWorld();*/
	if (!this->states.empty())
	{
		this->states.top()->update(this->dt);
		if (this->states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	//Application end
	else
	{
		this->endApplication();
		this->window->close();
	}

}
/*
void Game::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
}

void Game::renderWorld()
{
	this->window->draw(this->worldBackground);
}


void Game::renderPlayer()
{
	this->player->render(*this->window);
}
*/
void Game::render()
{
	this->window->clear(sf::Color(150, 150, 150));

	//render game
	if (!this->states.empty())
		this->states.top()->render(this->window);
	/*
	//draw world
	this->renderWorld();

	this->renderPlayer();

	for (auto* bullet : this->bullets)
	{
		bullet->render(this->window);
	}

	for (auto* enemy : this->enemies)
	{
		enemy->render(this->window);
	}

	for (auto* item : this->items)
	{
		item->render(this->window);
	}

	this->renderGUI();

	//Game over screen
	if (this->player->getHp() <= 0)
	{
		this->window->draw(this->gameOverText);
	}*/
	this->window->display();
}






