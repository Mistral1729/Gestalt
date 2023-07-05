#include <sstream>
#include <iostream>

#include "LevelState.h"
#include "CreditsState.h"
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
		_startButton.setPosition((0.4 * SCREEN_WIDTH) - 15, 0.5 * SCREEN_HEIGHT);

		_data->assets.LoadTexture("Quit Button", QUIT_BUTTON_FILEPATH);
		_quitButton.setTexture(this->_data->assets.GetTexture("Quit Button"));
		_quitButton.setPosition(_startButton.getPosition().x, _startButton.getPosition().y + 50);

		_data->assets.LoadTexture("Credits Button", CREDITS_BUTTON_FILEPATH);
		_creditsButton.setTexture(this->_data->assets.GetTexture("Credits Button"));
		_creditsButton.setPosition(_quitButton.getPosition().x + 5, _quitButton.getPosition().y + 50);
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

		

		if ((_startButton.getGlobalBounds().contains(_data->window.mapPixelToCoords(sf::Mouse::getPosition(_data->window)))) ||
			(_quitButton.getGlobalBounds().contains(_data->window.mapPixelToCoords(sf::Mouse::getPosition(_data->window)))) ||
			(_creditsButton.getGlobalBounds().contains(_data->window.mapPixelToCoords(sf::Mouse::getPosition(_data->window)))))
		{
			if (_clock.getElapsedTime().asSeconds() > 0.3f) //the click sound actually "picks up" at roughly 0.3 seconds, hence this choice 
			{
				_data->clickSound.setLoop(false);
			}
			else
			{
				_data->clickSound.play();
			}
		}
		else
		{
			_clock.restart();
		}

		if (_data->input.IsSpriteClicked(_startButton, sf::Mouse::Left, _data->window))
		{
			_data->machine.AddState(StateRef(new LevelState(_data)), true);
		}

		if (_data->input.IsSpriteClicked(_quitButton, sf::Mouse::Left, _data->window))
		{
			_data->window.close();
		}

		if (_data->input.IsSpriteClicked(_creditsButton, sf::Mouse::Left, _data->window))
		{
			_data->machine.AddState(StateRef(new CreditsState(_data)), true);
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