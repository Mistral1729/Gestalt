#include <sstream>
#include <iostream>

#include "CreditsState.h"
#include "MainMenuState.h"

namespace Tiger
{
	CreditsState::CreditsState(GameDataRef data) : _data(data)
	{

	}

	void CreditsState::Init()
	{
		_data->assets.LoadTexture("Credits BG", CREDITS_MENU_BG_FILEPATH);
		_bg.setTexture(this->_data->assets.GetTexture("Credits BG"));

		_nextButton.setTexture(this->_data->assets.GetTexture("Next Button"));

		_data->assets.LoadTexture("Credits Interface", CREDITS_INTERFACE_FILEPATH);
		_interface.setTexture(this->_data->assets.GetTexture("Credits Interface"));
		_interface.setPosition(50, 0);

		_backButton.setTexture(this->_data->assets.GetTexture("Back Button"));
		_backButton.setPosition(80, 400);

		cursor = new GameCursor(_data);
	}

	void CreditsState::HandleInput()
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

		if (_backButton.getGlobalBounds().contains(_data->window.mapPixelToCoords(sf::Mouse::getPosition(_data->window))))
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

		if (_data->input.IsSpriteClicked(_backButton, sf::Mouse::Left, _data->window))
		{
			_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}

	void CreditsState::Update(float dt)
	{

	}

	void CreditsState::Draw(float dt)
	{
		cursor->SetCursorPosition();
		_data->window.clear();

		_data->window.draw(_bg);
		_data->window.draw(_interface);

		_data->window.draw(_backButton);

		cursor->DrawCursor();
		_data->window.display();
	}
}