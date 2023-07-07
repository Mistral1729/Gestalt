#pragma once

#include <SFML/Graphics.hpp>

#include "State.h"
#include "Game.h"
#include "Definitions.h"

namespace Tiger
{
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
	private:
		GameDataRef _data;

		sf::Clock _clock;

		sf::Sprite _bg;
		sf::Sprite _title;
		sf::Sprite _startButton;
		sf::Sprite _quitButton;
		sf::Sprite _creditsButton;

		GameCursor* cursor;
	};
}