#include <sstream>
#include <iostream>

#include "LevelState.h"

namespace Tiger
{
	LevelState::LevelState(GameDataRef data) : _data(data)
	{

	}

	void LevelState::Init()
	{
		_data->assets.LoadTexture("Game BG", GAME_BG_FILEPATH);
		_bg.setTexture(this->_data->assets.GetTexture("Game BG"));

		_data->assets.LoadTexture("Spike Up", SPIKE_UP_FILEPATH);
		_data->assets.LoadTexture("Spike Down", SPIKE_DOWN_FILEPATH);

		spikes = new Spikes(_data);
	}

	void LevelState::HandleInput()
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

		if (_data->input.IsSpriteClicked(_bg, sf::Mouse::Left, _data->window))
		{
			//Do something...
		}
	}

	void LevelState::Update(float dt)
	{
		spikes->MoveSpikes(dt);

		if (_clock.getElapsedTime().asSeconds() > SPIKE_SPAWN_FREQUENCY)
		{
			spikes->SpawnSpikesUp();
			spikes->SpawnInvisibleSpikes();
			spikes->SpawnSpikesDown();

			_clock.restart();
		}
	}

	void LevelState::Draw(float dt)
	{
		_data->window.clear();

		_data->window.draw(_bg);

		spikes->DrawSpikes();

		_data->window.display();
	}
}