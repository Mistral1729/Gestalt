#include <stdlib.h>
#include <time.h>

#include "Game.h"
#include "SplashState.h"

namespace Tiger
{
	Game::Game(int width, int height, std::string title)
	{
		srand(time(NULL));

		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		_data->machine.AddState(StateRef(new SplashState(this->_data)), true);
		
		_data->music.openFromFile(MUSIC_FILEPATH);
		_data->music.setVolume(0.4 * MUSIC_VOLUME);
		_data->music.setLoop(true);

		_data->music.play();

		sf::SoundBuffer clickBuffer;
		clickBuffer.loadFromFile(CLICK_SOUND_FILEPATH);
		
		_data->clickSound.setBuffer(clickBuffer);
		_data->clickSound.setVolume(0.6 * SOUND_VOLUME);

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

}