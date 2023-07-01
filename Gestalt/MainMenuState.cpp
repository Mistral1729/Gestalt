#include <sstream>
#include <iostream>

#include "MainMenuState.h"

namespace Tiger
{
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{

	}

	void MainMenuState::Init()
	{
		_data->assets.LoadTexture("Main Menu State BG", MAIN_MENU_BG_FILEPATH);
		_bg.setTexture(this->_data->assets.GetTexture("Main Menu State BG"));

		_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
		_title.setTexture(this->_data->assets.GetTexture("Game Title"));
		_title.setPosition(0.25 * SCREEN_WIDTH, 0.05 * SCREEN_HEIGHT);

		_data->assets.LoadTexture("Start Button", START_BUTTON_FILEPATH);
		_startButton.setTexture(this->_data->assets.GetTexture("Start Button"));
		_startButton.setPosition(50, 400);

		_data->assets.LoadTexture("Quit Button", QUIT_BUTTON_FILEPATH);
		_quitButton.setTexture(this->_data->assets.GetTexture("Quit Button"));
		_quitButton.setPosition(50, 450);

		_data->assets.LoadTexture("Next Button", NEXT_BUTTON_FILEPATH);
		_nextButton.setTexture(this->_data->assets.GetTexture("Next Button"));

		_data->assets.LoadTexture("Back Button", BACK_BUTTON_FILEPATH);
		_backButton.setTexture(this->_data->assets.GetTexture("Back Button"));

		_data->assets.LoadTexture("Credits Button", CREDITS_BUTTON_FILEPATH);
		_creditsButton.setTexture(this->_data->assets.GetTexture("Credits Button"));
		_creditsButton.setPosition(50, 500);
	}

	void MainMenuState::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				_data->window.close();
				break;
			default:
				break;
			}
		}
	}

	void MainMenuState::Update(float dt)
	{
		
	}

	void MainMenuState::Draw(float dt)
	{
		_data->window.clear();

		_data->window.draw(_bg);

		_data->window.draw(_title);

		_data->window.draw(_startButton);
		_data->window.draw(_quitButton);
		_data->window.draw(_creditsButton);

		_data->window.display();
	}
}