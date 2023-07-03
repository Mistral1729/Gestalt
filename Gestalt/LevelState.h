#pragma once

#include <SFML/Graphics.hpp>

#include "State.h"
#include "Game.h"
#include "Spikes.h"

namespace Tiger
{
	class LevelState : public State
	{
	public:
		LevelState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
	private:
		GameDataRef _data;

		sf::Clock _clock;

		sf::Sprite _bg;

		Spikes *spikes;
	};
}