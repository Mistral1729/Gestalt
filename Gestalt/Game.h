#pragma once

#include <memory>
#include <string>

#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"
#include "Definitions.h"

namespace Tiger
{
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		sf::Music music;
		sf::Sound clickSound, collectSound, winSound, loseSound; 
		bool badEndFlag;
		AssetManager assets;
		InputManager input;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:
		Game(int width, int height, std::string title);
		~Game() { }

	private:
		const float dt = 1.f / 60.f;
		sf::Clock _clock;

		GameDataRef _data = std::make_shared<GameData>();

		void Run();
	};

	class GameCursor
	{
	public:
		GameCursor(GameDataRef data);

		void SetCursorPosition();	// MUST CALL everytime before window is cleared
		void DrawCursor();			// MUST CALL everytime immediately before window is displayed

	private:
		GameDataRef _cursorData;

		sf::Texture _cursorTexture;
		sf::Sprite _cursorSprite;

		sf::View fixed;
	};
	
}
