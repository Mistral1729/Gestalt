#include <sstream>
#include <iostream>

#include "GameOverState.h"
#include "MainMenuState.h"

namespace Tiger
{
	GameOverState::GameOverState(GameDataRef data) : _data(data)
	{

	}

	void GameOverState::Init()
	{
		_data->assets.LoadTexture("Good End", GAME_OVER_BG_FILEPATH); 
		_data->assets.LoadTexture("Bad End", GAME_OVER_BAD_BG_FILEPATH);
		
		if (this->_data->badEndFlag)
		{
			_bg.setTexture(this->_data->assets.GetTexture("Bad End"));
		}
		else
		{
			_bg.setTexture(this->_data->assets.GetTexture("Good End"));
		}

		cursor = new GameCursor(_data);
	}

	void GameOverState::HandleInput()
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

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)))
		{
			_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}

	void GameOverState::Update(float dt)
	{

	}

	void GameOverState::Draw(float dt)
	{
		cursor->SetCursorPosition();
		_data->window.clear();

		_data->window.draw(_bg);

		cursor->DrawCursor();
		_data->window.display();
	}
}