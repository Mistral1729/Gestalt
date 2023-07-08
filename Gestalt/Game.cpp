#include <stdlib.h>
#include <time.h>

#include "Game.h"
#include "SplashState.h"

namespace Tiger
{
	Game::Game(int width, int height, std::string title)
	{
		srand(time(NULL));

		sf::Image icon;

		_data->badEndFlag = false;

		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		_data->machine.AddState(StateRef(new SplashState(this->_data)), true);
		_data->window.setMouseCursorVisible(false);

		if (icon.loadFromFile(GAME_ICON_FILEPATH))	_data->window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
		
		_data->music.openFromFile(MUSIC_FILEPATH);
		_data->music.setVolume(0.4 * MUSIC_VOLUME);
		_data->music.setLoop(true);

		_data->music.play();

		sf::SoundBuffer clickBuffer, collectBuffer, winBuffer, loseBuffer;
		clickBuffer.loadFromFile(CLICK_SOUND_FILEPATH);
		collectBuffer.loadFromFile(COLLECT_SOUND_FILEPATH);
		winBuffer.loadFromFile(GAME_OVER_SOUND_FILEPATH);
		loseBuffer.loadFromFile(GAME_OVER_BAD_SOUND_FILEPATH);
		
		_data->clickSound.setBuffer(clickBuffer);
		_data->clickSound.setVolume(0.6 * SOUND_VOLUME);

		_data->collectSound.setBuffer(collectBuffer);
		_data->collectSound.setVolume(0.6 * SOUND_VOLUME);

		_data->winSound.setBuffer(winBuffer);
		_data->winSound.setVolume(0.6 * SOUND_VOLUME);

		_data->loseSound.setBuffer(loseBuffer);
		_data->loseSound.setVolume(0.6 * SOUND_VOLUME);

		this->Run();
	}

	void Game::Run()
	{
		float newTime, frameTime, interpolation;

		float currentTime = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.f;

		while (this->_data->window.isOpen())
		{
			this->_data->machine.ProcessStateChanges();

			newTime = this->_clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;

			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				this->_data->machine.GetActiveState()->HandleInput();
				this->_data->machine.GetActiveState()->Update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->_data->machine.GetActiveState()->Draw(interpolation);
		}
	}

	GameCursor::GameCursor(GameDataRef data) : _cursorData(data)
	{
		_cursorTexture.loadFromFile(CURSOR_FILEPATH);
		_cursorSprite.setTexture(_cursorTexture);

		fixed = _cursorData->window.getView();
	}

	void GameCursor::SetCursorPosition()
	{
		_cursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(this->_cursorData->window)));
	}

	void GameCursor::DrawCursor()
	{
		_cursorData->window.setView(fixed);
		_cursorData->window.draw(_cursorSprite);
	}

}