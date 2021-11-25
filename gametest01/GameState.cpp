#define _CRT_SECURE_NO_WARNINGS 1
#include "GameState.h"
#include <time.h>

void GameState::initKeybinds()
{

}

void GameState::initTexture()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("bullet02.png");
}

void GameState::initGUI()
{
	//load font
	if (!this->font.loadFromFile("Pixellari.ttf"))
		std::cout << "error::game::failed to load font" << "\n";

	//init point text
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(25);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setString("Points :");
	this->pointText.setPosition(20.f, 5.f);

	this->pointTextEnd.setFont(this->font);
	this->pointTextEnd.setCharacterSize(50);
	this->pointTextEnd.setFillColor(sf::Color::Black);
	this->pointTextEnd.setString("Your Score");
	this->pointTextEnd.setPosition((this->window->getSize().x / 2.f - this->pointTextEnd.getGlobalBounds().width / 2.f)-70.f, 250.f);

	this->worldLevelText.setFont(this->font);
	this->worldLevelText.setCharacterSize(25);
	this->worldLevelText.setFillColor(sf::Color::White);
	this->worldLevelText.setString("World Level :");
	this->worldLevelText.setPosition(20.f,35.f);

	this->studentNum.setFont(this->font);
	this->studentNum.setCharacterSize(30);
	this->studentNum.setFillColor(sf::Color::White);
	this->studentNum.setString("64011273 Wishu Sriyotee");
	this->studentNum.setPosition(
		this->window->getSize().x / 2.f - this->studentNum.getGlobalBounds().width / 2.f,10.f);

	this->pressEsc.setFont(this->font);
	this->pressEsc.setCharacterSize(30);
	this->pressEsc.setFillColor(sf::Color::White);
	this->pressEsc.setString("press Esc to quit");
	this->pressEsc.setPosition(1000.f, 10.f);

	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(150);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setString("Game Over");
	this->gameOverText.setPosition(
		this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,70.f);

	this->pressEnter.setFont(this->font);
	this->pressEnter.setCharacterSize(40);
	this->pressEnter.setFillColor(sf::Color::Black);
	this->pressEnter.setString("press Enter to continue");
	this->pressEnter.setPosition(
		this->window->getSize().x / 2.f - this->pressEnter.getGlobalBounds().width / 2.f,450.f);

	//init player Gui
	this->playerHpBar.setSize(sf::Vector2f(150.f, 20.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(20.f, 70.f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));

	this->nameSpace.setFont(this->font);
	this->nameSpace.setCharacterSize(40);
	this->nameSpace.setFillColor(sf::Color::Black);
	this->nameSpace.setString("Name :");
	this->nameSpace.setPosition((this->window->getSize().x / 2.f - this->nameSpace.getGlobalBounds().width / 2.f)-70.f, 350.f);

	this->nameInput.setFont(this->font);
	this->nameInput.setCharacterSize(40);
	this->nameInput.setFillColor(sf::Color::Black);
	this->nameInput.setString(nameOutput);
	this->nameInput.setPosition(this->window->getSize().x / 2.f - this->nameInput.getGlobalBounds().width / 2.f, 350.f);

}

void GameState::initWorld()
{
	if (!this->worldBackgroungTex.loadFromFile("NightMoon.png"))
	{
		std::cout << "error::game::could not load background texture" << "\n";
	}
	this->worldBackground.setTexture(this->worldBackgroungTex);
	this->worldBackground.setPosition(sf::Vector2f(0.f, 0.f));
	if (!this->worldBackgroungTex2.loadFromFile("NightMoon.png"))
	{
		std::cout << "error::game::could not load background texture" << "\n";
	}
	this->worldBackground2.setTexture(this->worldBackgroungTex2);
	this->worldBackground2.setPosition(sf::Vector2f(1280.f, 0.f));

	if (!this->mountainTex.loadFromFile("NightMountain.png"))
	{
		std::cout << "error::game::could not load background texture" << "\n";
	}
	this->mountain.setTexture(this->mountainTex);
	this->mountain.setPosition(sf::Vector2f(0.f, 0.f));
	if (!this->mountainTex2.loadFromFile("NightMountain.png"))
	{
		std::cout << "error::game::could not load background texture" << "\n";
	}
	this->mountain2.setTexture(this->mountainTex2);
	this->mountain2.setPosition(sf::Vector2f(1280.f, 0.f));

	if (!this->cloudTex.loadFromFile("NightCloud.png"))
	{
		std::cout << "error::game::could not load background texture" << "\n";
	}
	this->cloud.setTexture(this->cloudTex);
	this->cloud.setPosition(sf::Vector2f(0.f, 0.f));
	if (!this->cloudTex2.loadFromFile("NightCloud.png"))
	{
		std::cout << "error::game::could not load background texture" << "\n";
	}
	this->cloud2.setTexture(this->cloudTex2);
	this->cloud2.setPosition(sf::Vector2f(1280.f, 0.f));

	if (!this->buildTex.loadFromFile("NightBuilding.png"))
	{
		std::cout << "error::game::could not load background texture" << "\n";
	}
	this->build.setTexture(this->buildTex);
	this->build.setPosition(sf::Vector2f(0.f, 0.f));
	if (!this->buildTex2.loadFromFile("NightBuilding.png"))
	{
		std::cout << "error::game::could not load background texture" << "\n";
	}
	this->build2.setTexture(this->buildTex2);
	this->build2.setPosition(sf::Vector2f(1280.f, 0.f));

	if (!this->seaTex.loadFromFile("NightSea.png"))
	{
		std::cout << "error::game::could not load background texture" << "\n";
	}
	this->sea.setTexture(this->seaTex);
	this->sea.setPosition(sf::Vector2f(0.f, 0.f));
	if (!this->seaTex2.loadFromFile("NightSea.png"))
	{
		std::cout << "error::game::could not load background texture" << "\n";
	}
	this->sea2.setTexture(this->seaTex2);
	this->sea2.setPosition(sf::Vector2f(1280.f, 0.f));

	if (!this->overBGTex.loadFromFile("GameoverBG.png"))
	{
		std::cout << "error::game::could not load background texture" << "\n";
	}
	this->overBG.setTexture(this->overBGTex);
	this->overBG.setPosition(sf::Vector2f(0.f, 0.f));
}

void GameState::initSound()
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

void GameState::initSystems()
{
	this->points = 0;
}

void GameState::initPlayer()
{
	this->player = new Player();

}

void GameState::initEnemies()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;
}

void GameState::initCoins()
{
	this->spawnTimerItemMax = 50.f;
	this->spawnTimerItem = this->spawnTimerItemMax;
}

void GameState::initFlie()
{

}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	:State(window, supportedKeys, states)
{
	this->initKeybinds();
	this->initTexture();
	this->initGUI();
	this->initWorld();
	this->initSound();
	this->initSystems();
	this->initPlayer();
	this->initEnemies();
	this->initCoins();
	this->initFlie();
	if (this->player->getHp() <= 0)
	{
		
	}
}

GameState::~GameState()
{
	delete this->player;

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
	}
}

void GameState::endState()
{
	std::cout << "ending gamestate" << "\n";
}

void GameState::updateInput(const float& dt)
{
	this->checkForQuit();
}

void GameState::updatePlayer()
{
	this->player->update();
	int a = 0 ,countshot = 0;
	if (this->upgradeshot % 1 == 0 && this->upgradeshot != 0)
	{
		a = 1;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
	{
		
		if (a == 1)
		{
				//this->player->attackup(2.0f);

				this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 115.f, this->player->getPos().y + 40.f, 1.f, 0.f, 5.f));
				this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 115.f, this->player->getPos().y + 40.f, 0.75f, 0.3f, 5.f));
				this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 115.f, this->player->getPos().y + 40.f, 0.75f, -0.3f, 5.f));
				this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 115.f, this->player->getPos().y + 40.f, 0.5f, 0.5f, 5.f));
				this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 115.f, this->player->getPos().y + 40.f, 0.5f, -0.5f, 5.f));
				this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 115.f, this->player->getPos().y + 40.f, 0.3f, 0.8f, 5.f));
				this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 115.f, this->player->getPos().y + 40.f, 0.3f, -0.8f, 5.f));
				this->shootSound.play();
				a = 0;
				this->upgradeshot = 0;
				countshot++;
		}
		else if (a == 0)
		{
			this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x + 115.f, this->player->getPos().y + 40.f, 1.f, 0.f, 5.f));
			this->shootSound.play();
		}
	}
}

void GameState::updateGUI()
{
	std::stringstream ss;
	ss << "Points : " << this->points;
	this->pointText.setString(ss.str());

	std::stringstream ss2;
	ss2 << "World Level : " << this->worldLevel;
	this->worldLevelText.setString(ss2.str());

	std::stringstream ss3;
	ss3 << "Your Score " << this->points;
	this->pointTextEnd.setString(ss3.str());

	//update playerGUI

	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(150.f * hpPercent, this->playerHpBar.getSize().y));

}

void GameState::updateWorld()
{
	this->mountain.move(-.25f, 0.f);
	this->mountain2.move(-.25f, 0.f);
	if (this->mountain.getGlobalBounds().left < -1280.f)
	{
		this->mountain.setPosition(sf::Vector2f(1279.f, 0.f));
	}
	if (this->mountain2.getGlobalBounds().left < -1280.f)
	{
		this->mountain2.setPosition(sf::Vector2f(1279.f, 0.f));
	}

	this->cloud.move(-.5f, 0.f);
	this->cloud2.move(-.5f, 0.f);
	if (this->cloud.getGlobalBounds().left < -1280.f)
	{
		this->cloud.setPosition(sf::Vector2f(1279.f, 0.f));
	}
	if (this->cloud2.getGlobalBounds().left < -1280.f)
	{
		this->cloud2.setPosition(sf::Vector2f(1279.f, 0.f));
	}

	this->build.move(-1.5f, 0.f);
	this->build2.move(-1.5f, 0.f);
	if (this->build.getGlobalBounds().left < -1280.f)
	{
		this->build.setPosition(sf::Vector2f(1279.f, 0.f));
	}
	if (this->build2.getGlobalBounds().left < -1280.f)
	{
		this->build2.setPosition(sf::Vector2f(1279.f, 0.f));
	}

	this->sea.move(-3.f, 0.f);
	this->sea2.move(-3.f, 0.f);
	if (this->sea.getGlobalBounds().left < -1280.f)
	{
		this->sea.setPosition(sf::Vector2f(1279.f, 0.f));
	}
	if (this->sea2.getGlobalBounds().left < -1280.f)
	{
		this->sea2.setPosition(sf::Vector2f(1279.f, 0.f));
	}
}

void GameState::updateCollision()
{
	//left world collision
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBounds().top);
	}

	//right world collision
	else if (this->player->getBounds().left > 1160.f)
	{
		this->player->setPosition(1160.f, this->player->getBounds().top);
	}

	//top world collision
	if (this->player->getBounds().top < 0.f)
	{
		this->player->setPosition(this->player->getBounds().left, 0.f);
	}

	//bottom world collision
	else if (this->player->getBounds().top > 685.f)
	{
		this->player->setPosition(this->player->getBounds().left, 685.f);
	} 

}

void GameState::updateEnemies()
{
	//spawning
	this->spawnTimer += 2.3f;
	if (this->points >= 50000 && this->points < 100000)
	{
		this->spawnTimer += .45f;
		this->worldLevel = 2;
	}
	if (this->points >= 100000 && this->points < 200000)
	{
		this->spawnTimer += 1.f;
		this->worldLevel = 3;
	}
	if (this->points >= 200000 )
	{
		this->spawnTimer += 1.3f;
		this->worldLevel = 4;
	}
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
		if (enemy->getBounds().left < -100.f || enemy->getBounds().top < -100.f|| enemy->getBounds().top > 820.f)
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

void GameState::updateCoins()
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

void GameState::updateCombat()
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

			upgradeshot++;
			this->getCoin.play();
			delete this->items[i];
			this->items.erase(this->items.begin() + i);
			if (this->player->getHp() < 10)
			{
			this->player->loseHp(-1);
			}
			item_delete = true;
		}

	}

}

void GameState::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();

		//bullet culling (right of screen)
		if (bullet->getBounds().left + bullet->getBounds().width > 1280.f || 
			bullet->getBounds().top + bullet->getBounds().height < 0.f ||
			bullet->getBounds().top + bullet->getBounds().height > 750.f)
		{
			//delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);

		}

		++counter;
	}
}

void GameState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	if (this->player->getHp() > 0)
	{
		
		this->updatePlayer();
		this->updateCollision();
		this->updateBullets();
		this->updateEnemies();
		this->updateCoins();
		this->updateCombat();
		this->updateGUI();
		this->updateWorld();
	}
	if (this->player->getHp() <= 0)
	{
		this->musicPlay.stop();
		
	}

}

void GameState::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->worldLevelText);
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
	this->window->draw(this->studentNum);
	this->window->draw(this->pressEsc);
}

void GameState::renderWorld()
{
	this->window->draw(this->worldBackground);
	this->window->draw(this->worldBackground2);
	this->window->draw(this->mountain);
	this->window->draw(this->mountain2);
	this->window->draw(this->cloud);
	this->window->draw(this->cloud2);
	this->window->draw(this->build);
	this->window->draw(this->build2);
	this->window->draw(this->sea);
	this->window->draw(this->sea2);
}


void GameState::renderPlayer()
{
	this->player->render(*this->window);
}

struct Ranking
{
	char name[11];
	int point;
};

Ranking ranking[5];
Ranking tempRank;

void GameState::render(sf::RenderTarget* target)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && this->player->getHp() > 0)
	{
		this->musicPlay.stop();
		this->states->push(new MainMenuState(this->window, this->supportedKeys, this->states));
	}
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
		int b = 1;
		this->window->draw(this->overBG);
		this->window->draw(this->gameOverText);
		this->window->draw(this->pressEnter);
		this->window->draw(this->pointTextEnd);
		this->window->draw(this->nameInput);
		this->window->draw(this->nameSpace);
		
		while (this->window->pollEvent(event) && b==1)
		{
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode != 0x000008)
				{
					nameOutput += event.text.unicode;
					nameInput.setString(nameOutput);
				}
				else if(event.text.unicode == 0x000008 && nameOutput.size() > 0)
				{
					nameOutput.erase(nameOutput.size() - 1, 1);
					nameInput.setString(nameOutput);
				}
				
			}

		}
		
		strcpy(playercurrentname, nameOutput.c_str());
		printf("%s\n", playercurrentname);
		

		fp = fopen("top5_rank.txt", "r");
		for (int i = 0; i < 5; i++)
		{
			fscanf(fp, "%s %d", ranking[i].name, &ranking[i].point);
		}
		//Data Replace
		if (points > ranking[4].point)
		{
			ranking[4].point = points;
			points = 0;

			strcpy(ranking[4].name, playercurrentname);
		}
		//Data Sort
		for (int i = 0; i < 5; ++i)
		{
			for (int j = i + 1; j < 5; ++j)
			{
				if (ranking[i].point < ranking[j].point)
				{
					tempRank.point = ranking[i].point;
					ranking[i].point = ranking[j].point;
					ranking[j].point = tempRank.point;

					strncpy(tempRank.name, ranking[i].name, sizeof(ranking[i].name));
					tempRank.name[sizeof(ranking[i].name)];

					strncpy(ranking[i].name, ranking[j].name, sizeof(ranking[j].name));
					ranking[i].name[sizeof(ranking[j].name)];

					strncpy(ranking[j].name, tempRank.name, sizeof(tempRank.name));
					ranking[j].name[sizeof(tempRank.point)];
				}
			}

		}
		fclose(fp);
		fp = fopen("top5_rank.txt", "w");
		
			for (int i = 0; i < 5; i++)
			{
				fprintf(fp, "%s %d \n", ranking[i].name, ranking[i].point);
			}
		fclose(fp);
		printf("%s\n", playercurrentname);

		for (int i = 0; i <= 4; i++)
		{
			this->rank[i].setFont(this->font);
			this->rank[i].setCharacterSize(50);
			this->rank[i].setFillColor(sf::Color::White);
			this->rank[i].setPosition(280.f, 180.f + (70 * i));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			this->states->push(new MainMenuState(this->window, this->supportedKeys, this->states));
		}
	}
}
