#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Game.h"
#include "Definitions.h"

namespace Tiger
{
	class Spikes //ATTENTION: THIS IS ACTUALLY IMPLEMENTING BULLETS, BUT NO TIME TO RENAME SHIT YET... SO REUSING SPIKES BOILERPLATE CODE
	{
	public:
		Spikes(GameDataRef data);

		void SpawnBullets();
		void MoveBulletsDown(float dt);
		void MoveBulletsLeft(float dt);
		void DrawSpikes();
		void RandomiseBulletOffset();
		int GetTilesCount();

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> _spikeSprites;

		int _bulletWidth;
		int _bulletSpawnXOffset;
	};
}