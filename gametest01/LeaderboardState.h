#pragma once


#include "HowToPlayState.h"
#include "GameState.h"
#include "Button.h"
#include <string.h>
#include <stdio.h>

class LeaderboardState :
	public State
{
private:
	//variables
	sf::RectangleShape background;
	sf::Font font;
	sf::Text rank[5];
	sf::Text pointRank[5];

	FILE* fp;

	//Bg
	sf::Texture menuBGTex;
	sf::Sprite menuBG;
	sf::Texture menuCloudTex;
	sf::Sprite menuCloud;
	sf::Texture menuCloudTex2;
	sf::Sprite menuCloud2;
	sf::Texture logoTex;
	sf::Sprite logo;
	sf::RectangleShape blackboard;

	std::map<std::string, Button*> buttons;

	//function
	void initMenuBG();
	void initFonts();
	void initKeybinds();
	void initButtons();
	void initRank();

public:
	LeaderboardState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~LeaderboardState();

	std::string playername[5];


	//function
	void endState();

	void updateMenuBG();
	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget* target = NULL);
	void render(sf::RenderTarget* target = NULL);
};

