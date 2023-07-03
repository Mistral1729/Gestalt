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

		_data->assets.LoadTexture("Land", LAND_TILE_FILEPATH);
		_data->assets.LoadTexture("Spike Up", SPIKE_UP_FILEPATH);
		_data->assets.LoadTexture("Spike Down", SPIKE_DOWN_FILEPATH);

		_data->assets.LoadTexture("Stand Frame 1", SARA_STAND_SPRITE1_FILEPATH);
		_data->assets.LoadTexture("Stand Frame 2", SARA_STAND_SPRITE2_FILEPATH);
		_data->assets.LoadTexture("Stand Frame 3", SARA_STAND_SPRITE3_FILEPATH);
		_data->assets.LoadTexture("Stand Frame 4", SARA_STAND_SPRITE4_FILEPATH);
		_data->assets.LoadTexture("Stand Frame 5", SARA_STAND_SPRITE5_FILEPATH);
		_data->assets.LoadTexture("Stand Frame 6", SARA_STAND_SPRITE6_FILEPATH);
		_data->assets.LoadTexture("Stand Frame 7", SARA_STAND_SPRITE7_FILEPATH);
		_data->assets.LoadTexture("Stand Frame 8", SARA_STAND_SPRITE8_FILEPATH);
		_data->assets.LoadTexture("Stand Frame 9", SARA_STAND_SPRITE9_FILEPATH);
		_data->assets.LoadTexture("Stand Frame 10", SARA_STAND_SPRITE10_FILEPATH);
		_data->assets.LoadTexture("Stand Frame 11", SARA_STAND_SPRITE11_FILEPATH);
		_data->assets.LoadTexture("Stand Frame 12", SARA_STAND_SPRITE12_FILEPATH);

		spikes = new Spikes(_data);
		land = new Land(_data);
		sara = new Sara(_data);
		_run = _jump = _roll = _flip = _crouch = false;
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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			_run = true;
		}
		else
		{
			_run = false;
		}

		if (_data->input.IsSpriteClicked(_bg, sf::Mouse::Left, _data->window))
		{
			//Do something...
		}
	}

	void LevelState::Update(float dt)
	{
		if (_run)
		{
			land->MoveLand(dt);
			spikes->MoveSpikes(dt);
		}

		//Uncomment the line below to ensure that yes, you don't need to worry about infinite tiles crashing your machine ;-)
		//std::cout << "Land tiles count: " << land->GetTilesCount() << "\n" << "Spikes count: " << spikes->GetTilesCount() << "\n";

		if ((_clock.getElapsedTime().asSeconds() > SPIKE_SPAWN_FREQUENCY) && (_run))
		{
			spikes->RandomiseSpikeOffset();

			spikes->SpawnSpikesDown();

			_clock.restart();
		}

		if (!_run && !_jump && !_roll && !_flip && !_crouch)
		{
			sara->AnimateStanding(dt);
		}
	}

	void LevelState::Draw(float dt)
	{
		_data->window.clear();

		_data->window.draw(_bg);

		land->DrawLand();
		sara->Draw();
		spikes->DrawSpikes();

		_data->window.display();
	}
}