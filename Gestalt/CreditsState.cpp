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

		_data->assets.LoadTexture("Next Button", NEXT_BUTTON_FILEPATH);
		_nextButton.setTexture(this->_data->assets.GetTexture("Next Button"));

		_data->assets.LoadTexture("Back Button", BACK_BUTTON_FILEPATH);
		_backButton.setTexture(this->_data->assets.GetTexture("Back Button"));
		_backButton.setPosition(0.25 * SCREEN_WIDTH, SCREEN_HEIGHT - 100);

		_data->assets.LoadSound("Back Sound", BACK_SOUND_FILEPATH);
		_backSound.setBuffer(this->_data->assets.GetSound("Back Sound"));
		_backSound.setVolume(SOUND_VOLUME);
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

		if (_data->input.IsSpriteClicked(_backButton, sf::Mouse::Left, _data->window))
		{
			_backSound.play();
		}
	}

	void CreditsState::Update(float dt)
	{

	}

	void CreditsState::Draw(float dt)
	{
		_data->window.clear();

		_data->window.draw(_bg);

		_data->window.draw(_backButton);

		_data->window.display();
	}
}