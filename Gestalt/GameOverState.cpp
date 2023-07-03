#include <sstream>
#include <iostream>

#include "GameOverState.h"

namespace Tiger
{
	GameOverState::GameOverState(GameDataRef data) : _data(data)
	{

	}

	void GameOverState::Init()
	{
		_data->assets.LoadTexture("Game Over BG", GAME_OVER_BG_FILEPATH);
		_bg.setTexture(this->_data->assets.GetTexture("Game Over BG"));
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
	}

	void GameOverState::Update(float dt)
	{

	}

	void GameOverState::Draw(float dt)
	{
		_data->window.clear();

		_data->window.draw(_bg);

		_data->window.display();
	}
}