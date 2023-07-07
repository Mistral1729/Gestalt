#include "Spikes.h"

namespace Tiger
{
	Spikes::Spikes(GameDataRef data) : _data(data)
	{
		_bulletWidth = _data->assets.GetTexture("Bullet").getSize().x;
		_bulletSpawnXOffset = 0;
	}

	void Spikes::SpawnBullets()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Bullet"));

		sprite.setPosition(_data->window.getSize().x - _bulletSpawnXOffset, 0);

		_spikeSprites.push_back(sprite);
	}
	
	void Spikes::MoveBulletsDown(float dt)
	{
		for (unsigned short int i = 0; i < _spikeSprites.size(); i++)
		{
			if ((_spikeSprites.at(i).getPosition().x + _spikeSprites.at(i).getGlobalBounds().width < 0) || 
				(_spikeSprites.at(i).getPosition().y + _spikeSprites.at(i).getGlobalBounds().height > SCREEN_HEIGHT))
			{
				_spikeSprites.erase(_spikeSprites.begin() + i);
			}
			else
			{
				float movement = BULLET_SPEED * dt;

				_spikeSprites.at(i).move(0, movement);
			}
		}
	}

	void Spikes::MoveBulletsLeft(float dt)
	{
		for (unsigned short int i = 0; i < _spikeSprites.size(); i++)
		{
			float movement = BULLET_SPEED * dt;

			_spikeSprites.at(i).move(-movement, 0);
		}
	}

	void Spikes::DrawSpikes()
	{
		for (unsigned short int i = 0; i < _spikeSprites.size(); i++)
		{
			_data->window.draw(_spikeSprites.at(i));
		}
	}

	void Spikes::RandomiseBulletOffset()
	{
		_bulletSpawnXOffset = 25 * (rand() % (_bulletWidth + 1));
	}

	int Spikes::GetTilesCount()
	{
		return _spikeSprites.size();
	}

	bool Spikes::IsCollidingWith(sf::FloatRect mesh)
	{
		for (unsigned short int i = 0; i < _spikeSprites.size(); i++)
		{
			if (_spikeSprites.at(i).getGlobalBounds().intersects(mesh))
			{
				_spikeSprites.erase(_spikeSprites.begin() + i);
				return true;
			}
		}

		return false;
	}
}