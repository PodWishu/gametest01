#pragma once

#include "HowToPlayState.h"
#include "GameState.h"
#include "Button.h"

class MainMenuState :
    public State
{
private:
	//variables
	sf::RectangleShape background;
	sf::Font font;

	//Bg
	sf::Texture menuBGTex;
	sf::Sprite menuBG;
	sf::Texture menuCloudTex;
	sf::Sprite menuCloud;
	sf::Texture menuCloudTex2;
	sf::Sprite menuCloud2;
	sf::Texture logoTex;
	sf::Sprite logo;

	std::map<std::string, Button*> buttons;

	//function
	void initMenuBG();
	void initFonts();
	void initKeybinds();
	void initButtons();

public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~MainMenuState();

	//function
	void endState();

	void updateMenuBG();
	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget* target = NULL);
	void render(sf::RenderTarget* target = NULL);
};

