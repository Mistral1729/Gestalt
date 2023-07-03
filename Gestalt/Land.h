#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Game.h"
#include "Definitions.h"

namespace Tiger
{
	class Land
	{
	public:
		Land(GameDataRef data);

		//void SpawnLand();
		void MoveLand(float dt);
		void DrawLand();
		int GetTilesCount();

	private:
		GameDataRef _data;

		std::vector<sf::Sprite> _landSprites;
	};
}