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

		void SpawnSpikesDown();
		void SpawnSpikesUp();
		void SpawnBullets();
		void MoveSpikes(float dt);
		void MoveBulletsDown(float dt);
		void DrawSpikes();
		void RandomiseSpikeOffset();
		int GetTilesCount();

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> _spikeSprites;

		int _spikesHeight;
		int _spikeSpawnYOffset;
	};
}