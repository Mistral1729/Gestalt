#pragma once

#include <SFML/Graphics.hpp>

#include "State.h"
#include "Game.h"
#include "Spikes.h"
#include "Land.h"
#include "Sara.h"

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
		bool _run, _jump, _roll, _flip, _crouch;

		sf::Clock _clock;

		sf::Sprite _bg;

		Spikes *spikes;
		Land *land;
		Sara *sara;
	};
}