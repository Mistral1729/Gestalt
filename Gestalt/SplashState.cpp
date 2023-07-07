#include <sstream>
#include <iostream>

#include "MainMenuState.h"
#include "SplashState.h"

namespace Tiger
{
	SplashState::SplashState(GameDataRef data) : _data(data)
	{

	}
	
	void SplashState::Init()
	{
		_data->assets.LoadTexture("Splash State BG", SPLASH_SCENE_BG_FILEPATH);
		_bg.setTexture(this->_data->assets.GetTexture("Splash State BG"));

		cursor = new GameCursor(_data);
	}

	void SplashState::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed :
				_data->window.close();
				break;
			default :
				break;
			}
		}
	}

	void SplashState::Update(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}

	void SplashState::Draw(float dt)
	{
		cursor->SetCursorPosition();
		_data->window.clear();

		_data->window.draw(_bg);

		cursor->DrawCursor();
		_data->window.display();

	}
}