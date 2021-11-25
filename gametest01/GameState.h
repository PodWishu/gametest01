#pragma once

#include "State.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <map>
#include <string>
#include <sstream>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Item.h"
#include "MainMenuState.h"
#include "LeaderboardState.h"
#include "Button.h"


class GameState :
    public State
{
private:

	//resource
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	std::map<std::string, Button*> buttons;

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
	sf::Text pointTextEnd;
	sf::Text worldLevelText;
	sf::Text studentNum;
	sf::Text pressEsc;
	sf::Text gameOverText;
	sf::Text pressEnter;
	sf::Text nameSpace;
	sf::Text nameInput;
	std::string nameOutput;
	char playercurrentname[11] = "";
	
	sf::Event event;
	

	//flie
	FILE* fp;
	sf::Text rank[5];
	std::string playername[5];

	//world
	sf::Texture worldBackgroungTex;
	sf::Sprite worldBackground;
	sf::Texture worldBackgroungTex2;
	sf::Sprite worldBackground2;
	sf::Texture mountainTex;
	sf::Sprite mountain;
	sf::Texture mountainTex2;
	sf::Sprite mountain2;
	sf::Texture cloudTex;
	sf::Sprite cloud;
	sf::Texture cloudTex2;
	sf::Sprite cloud2;
	sf::Texture buildTex;
	sf::Sprite build;
	sf::Texture buildTex2;
	sf::Sprite build2;
	sf::Texture seaTex;
	sf::Sprite sea;
	sf::Texture seaTex2;
	sf::Sprite sea2;
	sf::Texture overBGTex;
	sf::Sprite overBG;

	//system
	int upgradeshot = 0;

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

	void initKeybinds();
    void initTexture();
    void initGUI();
    void initWorld();
    void initSound();
    void initSystems();

    void initPlayer();
    void initEnemies();
    void initCoins();

	void initFlie();

public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~GameState();

	unsigned points;
	unsigned worldLevel = 1;


    //function
    void endState();

    void updateInput(const float& dt);
    void updatePlayer();
    void updateGUI();
    void updateWorld();
    void updateCollision();
    void updateEnemies();
    void updateCoins();
    void updateCombat();
    void updateBullets();
    void update(const float& dt);

    void renderGUI();
    void renderWorld();
    void renderPlayer();
    void render(sf::RenderTarget* target = NULL);
};

