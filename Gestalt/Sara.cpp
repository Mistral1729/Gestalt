#include "Sara.h"

namespace Tiger
{
	Sara::Sara(GameDataRef data) : _data(data)
	{
		_animationIterator = 0;

		_standingFrames.push_back(_data->assets.GetTexture("Stand Frame 1"));
		_standingFrames.push_back(_data->assets.GetTexture("Stand Frame 2"));
		_standingFrames.push_back(_data->assets.GetTexture("Stand Frame 3"));
		_standingFrames.push_back(_data->assets.GetTexture("Stand Frame 4"));
		_standingFrames.push_back(_data->assets.GetTexture("Stand Frame 5"));
		_standingFrames.push_back(_data->assets.GetTexture("Stand Frame 6"));
		_standingFrames.push_back(_data->assets.GetTexture("Stand Frame 7"));
		_standingFrames.push_back(_data->assets.GetTexture("Stand Frame 8"));
		_standingFrames.push_back(_data->assets.GetTexture("Stand Frame 9"));
		_standingFrames.push_back(_data->assets.GetTexture("Stand Frame 10"));
		_standingFrames.push_back(_data->assets.GetTexture("Stand Frame 11"));
		_standingFrames.push_back(_data->assets.GetTexture("Stand Frame 12"));

		_runningFrames.push_back(_data->assets.GetTexture("Run Frame 1"));
		_runningFrames.push_back(_data->assets.GetTexture("Run Frame 2"));
		_runningFrames.push_back(_data->assets.GetTexture("Run Frame 3"));
		_runningFrames.push_back(_data->assets.GetTexture("Run Frame 4"));
		_runningFrames.push_back(_data->assets.GetTexture("Run Frame 5"));
		_runningFrames.push_back(_data->assets.GetTexture("Run Frame 6"));
		_runningFrames.push_back(_data->assets.GetTexture("Run Frame 7"));
		_runningFrames.push_back(_data->assets.GetTexture("Run Frame 8"));
		_runningFrames.push_back(_data->assets.GetTexture("Run Frame 9"));
		_runningFrames.push_back(_data->assets.GetTexture("Run Frame 10"));
		_runningFrames.push_back(_data->assets.GetTexture("Run Frame 11"));

		_saraSprite.setTexture(_standingFrames.at(_animationIterator));
		_saraSprite.setPosition(0.2 * SCREEN_WIDTH, SCREEN_HEIGHT - 50);
	}

	void Sara::AnimateStanding(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > (STAND_ANIMATION_DURATION / _standingFrames.size()))
		{
			if (_animationIterator < _standingFrames.size() - 1)	_animationIterator++;
			else													_animationIterator = 0;

			_saraSprite.setTexture(_standingFrames.at(_animationIterator));
			_clock.restart();
		}
	}

	void Sara::AnimateRunning(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > (RUN_ANIMATION_DURATION / _runningFrames.size()))
		{
			if (_animationIterator < _runningFrames.size() - 1)	_animationIterator++;
			else													_animationIterator = 0;

			_saraSprite.setTexture(_runningFrames.at(_animationIterator));
			_clock.restart();
		}
	}

	void Sara::Draw()
	{
		_data->window.draw(_saraSprite);
	}
}