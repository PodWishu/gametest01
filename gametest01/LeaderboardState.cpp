#define _CRT_SECURE_NO_WARNINGS 1
#include "LeaderboardState.h"
#include <string.h>
#include <stdio.h>



void LeaderboardState::initMenuBG()
{
	if (!this->menuBGTex.loadFromFile("MenuGame.png"))
	{
		std::cout << "error::game::could not load backgroundmenu texture" << "\n";
	}
	this->menuBG.setTexture(this->menuBGTex);
	this->menuBG.setPosition(sf::Vector2f(0.f, 0.f));

	if (!this->menuCloudTex.loadFromFile("MenuCloud.png"))
	{
		std::cout << "error::game::could not load background texture" << "\n";
	}
	this->menuCloud.setTexture(this->menuCloudTex);
	this->menuCloud.setPosition(sf::Vector2f(0.f, 0.f));
	if (!this->menuCloudTex2.loadFromFile("MenuCloud.png"))
	{
		std::cout << "error::game::could not load background texture" << "\n";
	}
	this->menuCloud2.setTexture(this->menuCloudTex2);
	this->menuCloud2.setPosition(sf::Vector2f(1280.f, 0.f));

	if (!this->logoTex.loadFromFile("logo.png"))
	{
		std::cout << "error::game::could not load backgroundmenu texture" << "\n";
	}
	this->logo.setTexture(this->logoTex);
	this->logo.setPosition(sf::Vector2f(0.f, 0.f));
	this->blackboard.setSize(sf::Vector2f(800.f, 400.f));
	this->blackboard.setFillColor(sf::Color(40, 40, 40, 200));
	this->blackboard.setPosition(sf::Vector2f(240.f, 150.f));
}

void LeaderboardState::initFonts()
{
	if (!this->font.loadFromFile("Pixellari.ttf"))
	{
		throw("error::leaderboardstate:: could not load font");
	}

	
}

void LeaderboardState::initKeybinds()
{
	
}

void LeaderboardState::initButtons()
{
	this->buttons["BACK_STATE"] = new Button(1000, 600, 175, 50,
		&this->font, "Back To Menu",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

struct Ranking
{
	char name[11];
	int point;
};

Ranking rankingboard[5];


void LeaderboardState::initRank()
{
	
	fp = fopen("top5_rank.txt", "r");
	for (int i = 0; i < 5; i++)
	{
		fscanf(fp, "%s %d", rankingboard[i].name, &rankingboard[i].point);
		playername[i] = rankingboard[i].name;
	}
	
	fclose(fp);

	this->rank[0].setString("1.  " + playername[0]);
	this->rank[1].setString("2.  " + playername[1]);
	this->rank[2].setString("3.  " + playername[2]);
	this->rank[3].setString("4.  " + playername[3]);
	this->rank[4].setString("5.  " + playername[4]);
	
	this->pointRank[0].setString(std::to_string(rankingboard[0].point));
	this->pointRank[1].setString(std::to_string(rankingboard[1].point));
	this->pointRank[2].setString(std::to_string(rankingboard[2].point));
	this->pointRank[3].setString(std::to_string(rankingboard[3].point));
	this->pointRank[4].setString(std::to_string(rankingboard[4].point));
	for (int i = 0; i <= 4; i++)
	{
		this->rank[i].setFont(this->font);
		this->rank[i].setCharacterSize(50);
		this->rank[i].setFillColor(sf::Color::White);
		this->rank[i].setPosition(280.f, 180.f + (70 * i));
		this->pointRank[i].setFont(this->font);
		this->pointRank[i].setCharacterSize(50);
		this->pointRank[i].setFillColor(sf::Color::White);
		this->pointRank[i].setPosition(800.f, 180.f + (70 * i));
	}
	
}

LeaderboardState::LeaderboardState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	:State(window, supportedKeys, states)
{
	this->initMenuBG();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();
	this->initRank();

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
}

LeaderboardState::~LeaderboardState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void LeaderboardState::endState()
{
	std::cout << "ending LeaderboardState" << "\n";
}

void LeaderboardState::updateMenuBG()
{
	this->menuCloud.move(-.5f, 0.f);
	this->menuCloud2.move(-.5f, 0.f);
	if (this->menuCloud.getGlobalBounds().left < -1280.f)
	{
		this->menuCloud.setPosition(sf::Vector2f(1279.f, 0.f));
	}
	if (this->menuCloud2.getGlobalBounds().left < -1280.f)
	{
		this->menuCloud2.setPosition(sf::Vector2f(1279.f, 0.f));
	}
}

void LeaderboardState::updateInput(const float& dt)
{
	this->checkForQuit();

}

void LeaderboardState::updateButtons()
{
	/*update all this buttons in the state and handles their functionality.*/
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	//back to menu
	if (this->buttons["BACK_STATE"]->isPressed())
	{
		this->states->push(new MainMenuState(this->window, this->supportedKeys, this->states));
	}
}

void LeaderboardState::update(const float& dt)
{
	this->updateMenuBG();
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateButtons();


}

void LeaderboardState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void LeaderboardState::render(sf::RenderTarget* target)
{
	target->draw(this->background);
	this->window->draw(this->menuBG);
	this->window->draw(this->menuCloud);
	this->window->draw(this->menuCloud2);
	this->window->draw(this->logo);
	this->window->draw(this->blackboard);
	for (int i = 0; i <= 4; i++)
	{
		this->window->draw(this->rank[i]);
		this->window->draw(this->pointRank[i]);
	}

	this->renderButtons(target);
}