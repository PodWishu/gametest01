#pragma once

#include "MainMenuState.h"

class Game
{

private:
	sf::RenderWindow* window;
	sf::Event ev;

	sf::Clock dtClock;
	float dt;

	std::stack <State*> states;

	std::map<std::string, int> supportedKeys;
	/*
	//resource
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	//sound
	sf::SoundBuffer shoot;
	sf::Sound shootSound;
	sf::SoundBuffer coin;
	sf::Sound getCoin;
	sf::SoundBuffer boom;
	sf::Sound enemyBoom;
	sf::SoundBuffer collisionShip;
	sf::Sound collShip;
	sf::Music musicPlay;

	//GUI
	sf::Font font;
	sf::Text pointText;

	sf::Text gameOverText;

	//world
	sf::Texture worldBackgroungTex;
	sf::Sprite worldBackground;

	//system
	unsigned points;

	//PLayer
	Player* player;

	//playerGUI

	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;

	//enemyy
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;

	//Item
	float spawnTimerItem;
	float spawnTimerItemMax;
	std::vector<Item*> items;
	*/
	//private function
	void initWindow();
	void initKeys();
	void initStates();
	
	/*
	void initTexture();
	void initGUI();
	void initWorld();
	void initSound();
	void initSystems();

	void initPlayer();
	void initEnemies();
	void initCoins();
	*/

public:
	Game();

	virtual ~Game();

	//regular
	void endApplication();

	//function
	void updatePollEvent();
	void updateDt();
	/*
	void updatePlayer();
	void updateGUI();
	void updateWorld();
	void updateCollision();
	void updateEnemies();
	void updateCoins();
	void updateCombat();
	void updateBullets();
	*/
	void run();
	void update();
	/*
	void renderGUI();
	void renderWorld();
	void renderPlayer();
	*/
	void render();


};


