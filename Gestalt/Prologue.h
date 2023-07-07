#pragma once

#include <SFML/Graphics.hpp>

#include "State.h"
#include "Game.h"
#include "Definitions.h"

namespace Tiger
{
	class Prologue : public State
	{
	public:
		Prologue(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
	private:
		GameDataRef _data;

		sf::Clock _clock;

		sf::Sprite _bg;

		GameCursor* cursor;
	};

	class PostPrologue : public State
	{
	public:
		PostPrologue(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
	private:
		GameDataRef _data;

		sf::Clock _clock;

		sf::Sprite _bg;

		GameCursor* cursor;
	};
}