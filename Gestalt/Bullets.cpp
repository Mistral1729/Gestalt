#include "Bullets.h"

namespace Tiger
{
	Bullets::Bullets(GameDataRef data) : _data(data)
	{
		_saraXPos = 0.2 * SCREEN_WIDTH;
		_bulletSpawnXOffset = 0;
	}

	void Bullets::SpawnBullets()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Bullet"));

		sprite.setPosition(_bulletSpawnXOffset, 0);

		_bulletSprites.push_back(sprite);
	}
	
	void Bullets::MoveBulletsDown(float dt)
	{
		for (unsigned short int i = 0; i < _bulletSprites.size(); i++)
		{
			if ((_bulletSprites.at(i).getPosition().x + _bulletSprites.at(i).getGlobalBounds().width < 0) || 
				(_bulletSprites.at(i).getPosition().y + _bulletSprites.at(i).getGlobalBounds().height > SCREEN_HEIGHT))
			{
				_bulletSprites.erase(_bulletSprites.begin() + i);
			}
			else
			{
				float movement = BULLET_SPEED * dt;

				_bulletSprites.at(i).move(0, movement);
			}
		}
	}

	void Bullets::MoveBulletsLeft(float dt)
	{
		for (unsigned short int i = 0; i < _bulletSprites.size(); i++)
		{
			float movement = BULLET_SPEED * dt;

			_bulletSprites.at(i).move(-movement, 0);
		}
	}

	void Bullets::DrawSpikes()
	{
		for (unsigned short int i = 0; i < _bulletSprites.size(); i++)
		{
			_data->window.draw(_bulletSprites.at(i));
		}
	}

	void Bullets::RandomiseBulletOffset()
	{
		_bulletSpawnXOffset = (rand() % (SCREEN_WIDTH - _saraXPos - 50)) + _saraXPos + 50; //Any integer in the range [_saraXPos + 50, SCREEN_WIDTH - 1]  
	}

	int Bullets::GetTilesCount()
	{
		return _bulletSprites.size();
	}

	bool Bullets::IsCollidingWith(sf::FloatRect mesh)
	{
		for (unsigned short int i = 0; i < _bulletSprites.size(); i++)
		{
			if (_bulletSprites.at(i).getGlobalBounds().intersects(mesh))
			{
				_bulletSprites.erase(_bulletSprites.begin() + i);
				return true;
			}
		}

		return false;
	}
}