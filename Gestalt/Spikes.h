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

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> _spikeSprites;
	};
}