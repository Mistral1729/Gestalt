#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Game.h"
#include "Definitions.h"

namespace Tiger
{
	class Bullets 
	{
	public:
		Bullets(GameDataRef data);

		void SpawnBullets();
		void MoveBulletsDown(float dt);
		void MoveBulletsLeft(float dt);
		void DrawSpikes();
		void RandomiseBulletOffset();
		int GetTilesCount();

		bool IsCollidingWith(sf::FloatRect mesh);

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> _bulletSprites;

		sf::Text _scoreText;

		int _bulletWidth;
		int _bulletSpawnXOffset;
	};
}