#include <sstream>
#include <iostream>

#include "Prologue.h"
#include "LevelState.h"

namespace Tiger
{
	Prologue::Prologue(GameDataRef data) : _data(data)
	{

	}

	void Prologue::Init()
	{
		_data->assets.LoadTexture("Prologue 1", PROLOGUE_1_FILEPATH);

		_bg.setTexture(this->_data->assets.GetTexture("Prologue 1"));

		cursor = new GameCursor(_data);
	}

	void Prologue::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				_data->window.close();
				break;
			default:
				break;
			}
		}

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)))
		{
			_data->machine.AddState(StateRef(new PostPrologue(_data)), true);
		}
	}

	void Prologue::Update(float dt)
	{
		
	}

	void Prologue::Draw(float dt)
	{
		cursor->SetCursorPosition();
		_data->window.clear();

		_data->window.draw(_bg);

		cursor->DrawCursor();
		_data->window.display();
	}

	PostPrologue::PostPrologue(GameDataRef data) : _data(data)
	{

	}

	void PostPrologue::Init()
	{
		_data->assets.LoadTexture("Prologue 2", PROLOGUE_2_FILEPATH);

		_bg.setTexture(this->_data->assets.GetTexture("Prologue 2"));

		cursor = new GameCursor(_data);
	}

	void PostPrologue::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				_data->window.close();
				break;
			default:
				break;
			}
		}

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)))
		{
			if (this->_clock.getElapsedTime().asSeconds() >= PROLOGUE_WAIT_TIME)
			{
				_data->machine.AddState(StateRef(new LevelState(_data)), true);
			}
		}
	}

	void PostPrologue::Update(float dt)
	{

	}

	void PostPrologue::Draw(float dt)
	{
		cursor->SetCursorPosition();
		_data->window.clear();

		_data->window.draw(_bg);

		cursor->DrawCursor();
		_data->window.display();
	}
}