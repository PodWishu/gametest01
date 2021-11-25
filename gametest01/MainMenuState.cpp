#include "MainMenuState.h"

void MainMenuState::initMenuBG()
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
	
}

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Pixellari.ttf"))
	{
		throw("error::mainmenustate:: could not load font");
	}
}

void MainMenuState::initKeybinds()
{

}

void MainMenuState::initButtons()
{
	this->buttons["GAME_STATE"] = new Button(565, 300, 150, 50,
		&this->font, "Play",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["LEADERBOARD_STATE"] = new Button(565, 400, 150, 50,
		&this->font, "Leaderboard",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["HOWTOPLAY_STATE"] = new Button(565, 500, 150, 50,
		&this->font, "How To Play",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["EXIT_STATE"] = new Button(565, 600, 150, 50,
		&this->font, "Quit",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	:State(window, supportedKeys, states)
{
	this->initMenuBG();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void MainMenuState::endState()
{
	std::cout << "ending mainmenustate" << "\n";
}

void MainMenuState::updateMenuBG()
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

void MainMenuState::updateInput(const float& dt)
{
	this->checkForQuit();

}

void MainMenuState::updateButtons()
{
	/*update all this buttons in the state and handles their functionality.*/
	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	//new game
	if (this->buttons["GAME_STATE"]->isPressed())
	{
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	}

	//go to leaderboard
	if (this->buttons["LEADERBOARD_STATE"]->isPressed())
	{
		this->states->push(new LeaderboardState(this->window, this->supportedKeys, this->states));
	}

	//go to how to play
	if (this->buttons["HOWTOPLAY_STATE"]->isPressed())
	{
		this->states->push(new HowToPlayState(this->window, this->supportedKeys, this->states));
	}

	//quit the game
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->window->close();
	}
}

void MainMenuState::update(const float& dt)
{
	this->updateMenuBG();
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateButtons();

	
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	target->draw(this->background);
	this->window->draw(this->menuBG);
	this->window->draw(this->menuCloud);
	this->window->draw(this->menuCloud2);
	this->window->draw(this->logo);

	this->renderButtons(target);
}