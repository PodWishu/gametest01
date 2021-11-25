#include "HowToPlayState.h"

void HowToPlayState::initMenuBG()
{
	if (!this->menuBGTex.loadFromFile("MenuControl.png"))
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
	if (!this->controlTex.loadFromFile("Control.png"))
	{
		std::cout << "error::game::could not load backgroundmenu texture" << "\n";
	}
	this->control.setTexture(this->controlTex);
	this->control.setPosition(sf::Vector2f(0.f, 0.f));

}

void HowToPlayState::initFonts()
{
	if (!this->font.loadFromFile("Pixellari.ttf"))
	{
		throw("error::mainmenustate:: could not load font");
	}
}

void HowToPlayState::initKeybinds()
{

}

void HowToPlayState::initButtons()
{
	this->buttons["BACK_STATE"] = new Button(1000, 600, 175, 50,
		&this->font, "Back To Menu",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

HowToPlayState::HowToPlayState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	:State(window, supportedKeys, states)
{
	this->initMenuBG();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
}

HowToPlayState::~HowToPlayState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

void HowToPlayState::endState()
{
	std::cout << "ending howtoplaystate" << "\n";
}

void HowToPlayState::updateMenuBG()
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

void HowToPlayState::updateInput(const float& dt)
{

}

void HowToPlayState::updateButtons()
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

void HowToPlayState::update(const float& dt)
{
	this->updateMenuBG();
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateButtons();


}

void HowToPlayState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void HowToPlayState::render(sf::RenderTarget* target)
{
	target->draw(this->background);
	this->window->draw(this->menuBG);
	this->window->draw(this->menuCloud);
	this->window->draw(this->menuCloud2);
	this->window->draw(this->control);

	this->renderButtons(target);
}
