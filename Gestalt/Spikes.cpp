#include "Spikes.h"

namespace Tiger
{
	Spikes::Spikes(GameDataRef data) : _data(data)
	{
		_spikesHeight = _data->assets.GetTexture("Spike Down").getSize().y;
		_spikeSpawnYOffset = 0;
	}

	void Spikes::SpawnSpikesDown()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Spike Down"));

		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height + _spikeSpawnYOffset);

		_spikeSprites.push_back(sprite);
	}
	
	void Spikes::SpawnSpikesUp()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Spike Up"));

		sprite.setPosition(_data->window.getSize().x, 0);

		_spikeSprites.push_back(sprite);
	}
	
	void Spikes::SpawnInvisibleSpikes()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Spike Up"));

		sprite.setPosition(_data->window.getSize().x, 0);
		sprite.setColor(sf::Color(0, 0, 0, 0));

		_spikeSprites.push_back(sprite);
	}
	
	void Spikes::MoveSpikes(float dt)
	{
		for (unsigned short int i = 0; i < _spikeSprites.size(); i++)
		{
			if (_spikeSprites.at(i).getPosition().x + _spikeSprites.at(i).getGlobalBounds().width < 0) 
			{
				_spikeSprites.erase(_spikeSprites.begin() + i);
			}
			else
			{
				float movement = TILE_SPEED * dt;

				_spikeSprites.at(i).move(-movement, 0);
			}
		}
	}

	void Spikes::DrawSpikes()
	{
		for (unsigned short int i = 0; i < _spikeSprites.size(); i++)
		{
			_data->window.draw(_spikeSprites.at(i));
		}
	}

	void Spikes::RandomiseSpikeOffset()
	{
		_spikeSpawnYOffset = rand() % (_spikesHeight + 1);
	}

	int Spikes::GetTilesCount()
	{
		return _spikeSprites.size();
	}
}