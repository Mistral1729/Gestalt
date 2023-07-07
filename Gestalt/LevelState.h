#pragma once

#include <SFML/Graphics.hpp>

#include "State.h"
#include "Game.h"
#include "Bullets.h"
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
		unsigned int score;
		float bullet_frequency;

		sf::Clock _clock;
		sf::Text _scoreText;
		sf::Sprite _bg;

		Bullets *bullets;
		Land *land;
		Sara *sara;
		GameCursor *cursor;
	};
}