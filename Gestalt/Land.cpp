#include "Land.h"

namespace Tiger
{
	Land::Land(GameDataRef data) : _data(data)
	{
		sf::Sprite sprite1(_data->assets.GetTexture("Land"));
		sf::Sprite sprite2(_data->assets.GetTexture("Land"));
		sf::Sprite sprite3(_data->assets.GetTexture("Land"));
		sf::Sprite sprite4(_data->assets.GetTexture("Land"));
		sf::Sprite sprite5(_data->assets.GetTexture("Land"));
		sf::Sprite sprite6(_data->assets.GetTexture("Land"));

		sprite1.setPosition(0 * 0.5 * SCREEN_WIDTH, SCREEN_HEIGHT - 170);
		sprite2.setPosition(0.5 * 0.5 * SCREEN_WIDTH, SCREEN_HEIGHT - 170);
		sprite3.setPosition(1 * 0.5 * SCREEN_WIDTH, SCREEN_HEIGHT - 170);
		sprite4.setPosition(1.5 * 0.5 * SCREEN_WIDTH, SCREEN_HEIGHT - 170);
		sprite5.setPosition(2 * 0.5 * SCREEN_WIDTH, SCREEN_HEIGHT - 170);
		sprite6.setPosition(2.5 * 0.5 * SCREEN_WIDTH, SCREEN_HEIGHT - 170);

		_landSprites.push_back(sprite1);
		_landSprites.push_back(sprite2);
		_landSprites.push_back(sprite3);
		_landSprites.push_back(sprite4);
		_landSprites.push_back(sprite5);
		_landSprites.push_back(sprite6);
	}

	void Land::MoveLand(float dt)
	{
		for (unsigned short int i = 0; i < _landSprites.size(); i++)
		{
			float movement = TILE_SPEED * dt;

			_landSprites.at(i).move(-movement, 0);

			if (_landSprites.at(i).getPosition().x + _landSprites.at(i).getGlobalBounds().width < 0)
			{
				sf::Vector2f position(SCREEN_WIDTH, _landSprites.at(i).getPosition().y);

				_landSprites.at(i).setPosition(position);
			}
		}
	}

	void Land::DrawLand()
	{
		for (unsigned short int i = 0; i < _landSprites.size(); i++)
		{
			_data->window.draw(_landSprites.at(i));
		}
	}

	int Land::GetTilesCount()
	{
		return _landSprites.size();
	}
}