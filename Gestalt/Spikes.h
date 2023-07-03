#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Game.h"
#include "Definitions.h"

namespace Tiger
{
	class Spikes
	{
	public:
		Spikes(GameDataRef data);

		void SpawnSpikesDown();
		void SpawnSpikesUp();
		void SpawnInvisibleSpikes();
		void MoveSpikes(float dt);
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