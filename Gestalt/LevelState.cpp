#include <sstream>
#include <iostream>

#include "GameOverState.h"
#include "LevelState.h"

namespace Tiger
{
	LevelState::LevelState(GameDataRef data) : _data(data)
	{
		
	}

	void LevelState::Init()
	{
		_data->assets.LoadTexture("Game BG", GAME_BG_FILEPATH);
		_bg.setTexture(this->_data->assets.GetTexture("Game BG"));

		_data->assets.LoadTexture("Land", LAND_TILE_FILEPATH);

		_data->assets.LoadTexture("Bullet", BULLET_FILEPATH);

		_data->assets.LoadTexture("Stand Frame 1",  SARA_STAND_SPRITE1_FILEPATH);
		_data->assets.LoadTexture("Stand Frame 2",  SARA_STAND_SPRITE2_FILEPATH);
		_data->assets.LoadTexture("Stand Frame 3",  SARA_STAND_SPRITE3_FILEPATH);
		_data->assets.LoadTexture("Stand Frame 4",  SARA_STAND_SPRITE4_FILEPATH);
		_data->assets.LoadTexture("Stand Frame 5",  SARA_STAND_SPRITE5_FILEPATH);
		_data->assets.LoadTexture("Stand Frame 6",  SARA_STAND_SPRITE6_FILEPATH);
		_data->assets.LoadTexture("Stand Frame 7",  SARA_STAND_SPRITE7_FILEPATH);
		_data->assets.LoadTexture("Stand Frame 8",  SARA_STAND_SPRITE8_FILEPATH);
		_data->assets.LoadTexture("Stand Frame 9",  SARA_STAND_SPRITE9_FILEPATH);
		_data->assets.LoadTexture("Stand Frame 10", SARA_STAND_SPRITE10_FILEPATH);
		_data->assets.LoadTexture("Stand Frame 11", SARA_STAND_SPRITE11_FILEPATH);
		_data->assets.LoadTexture("Stand Frame 12", SARA_STAND_SPRITE12_FILEPATH);

		_data->assets.LoadTexture("Run Frame 1",  SARA_RUN_SPRITE1_FILEPATH);
		_data->assets.LoadTexture("Run Frame 2",  SARA_RUN_SPRITE2_FILEPATH);
		_data->assets.LoadTexture("Run Frame 3",  SARA_RUN_SPRITE3_FILEPATH);
		_data->assets.LoadTexture("Run Frame 4",  SARA_RUN_SPRITE4_FILEPATH);
		_data->assets.LoadTexture("Run Frame 5",  SARA_RUN_SPRITE5_FILEPATH);
		_data->assets.LoadTexture("Run Frame 6",  SARA_RUN_SPRITE6_FILEPATH);
		_data->assets.LoadTexture("Run Frame 7",  SARA_RUN_SPRITE7_FILEPATH);
		_data->assets.LoadTexture("Run Frame 8",  SARA_RUN_SPRITE8_FILEPATH);
		_data->assets.LoadTexture("Run Frame 9",  SARA_RUN_SPRITE9_FILEPATH);
		_data->assets.LoadTexture("Run Frame 10", SARA_RUN_SPRITE10_FILEPATH);
		_data->assets.LoadTexture("Run Frame 11", SARA_RUN_SPRITE11_FILEPATH);

		_data->assets.LoadTexture("Jump Frame 1", SARA_JUMP_SPRITE1_FILEPATH);
		_data->assets.LoadTexture("Jump Frame 2", SARA_JUMP_SPRITE2_FILEPATH);
		_data->assets.LoadTexture("Jump Frame 3", SARA_JUMP_SPRITE3_FILEPATH);
		_data->assets.LoadTexture("Jump Frame 4", SARA_JUMP_SPRITE4_FILEPATH);
		_data->assets.LoadTexture("Jump Frame 5", SARA_JUMP_SPRITE5_FILEPATH);
		_data->assets.LoadTexture("Jump Frame 6", SARA_JUMP_SPRITE6_FILEPATH);
		_data->assets.LoadTexture("Jump Frame 7", SARA_JUMP_SPRITE7_FILEPATH);

		_data->assets.LoadTexture("Crouch Frame 1", SARA_CROUCH_SPRITE1_FILEPATH);
		_data->assets.LoadTexture("Crouch Frame 2", SARA_CROUCH_SPRITE2_FILEPATH);
		_data->assets.LoadTexture("Crouch Frame 3", SARA_CROUCH_SPRITE3_FILEPATH);
		_data->assets.LoadTexture("Crouch Frame 4", SARA_CROUCH_SPRITE4_FILEPATH);
		_data->assets.LoadTexture("Crouch Frame 5", SARA_CROUCH_SPRITE5_FILEPATH);
		_data->assets.LoadTexture("Crouch Frame 6", SARA_CROUCH_SPRITE6_FILEPATH);
		_data->assets.LoadTexture("Crouch Frame 7", SARA_CROUCH_SPRITE7_FILEPATH);
		_data->assets.LoadTexture("Crouch Frame 8", SARA_CROUCH_SPRITE8_FILEPATH);
		_data->assets.LoadTexture("Crouch Frame 9", SARA_CROUCH_SPRITE9_FILEPATH);

		_data->assets.LoadTexture("Flip Frame 1",  SARA_FLIP_SPRITE1_FILEPATH);
		_data->assets.LoadTexture("Flip Frame 2",  SARA_FLIP_SPRITE2_FILEPATH);
		_data->assets.LoadTexture("Flip Frame 3",  SARA_FLIP_SPRITE3_FILEPATH);
		_data->assets.LoadTexture("Flip Frame 4",  SARA_FLIP_SPRITE4_FILEPATH);
		_data->assets.LoadTexture("Flip Frame 5",  SARA_FLIP_SPRITE5_FILEPATH);
		_data->assets.LoadTexture("Flip Frame 6",  SARA_FLIP_SPRITE6_FILEPATH);
		_data->assets.LoadTexture("Flip Frame 7",  SARA_FLIP_SPRITE7_FILEPATH);
		_data->assets.LoadTexture("Flip Frame 8",  SARA_FLIP_SPRITE8_FILEPATH);
		_data->assets.LoadTexture("Flip Frame 9",  SARA_FLIP_SPRITE9_FILEPATH);
		_data->assets.LoadTexture("Flip Frame 10", SARA_FLIP_SPRITE10_FILEPATH);
		_data->assets.LoadTexture("Flip Frame 11", SARA_FLIP_SPRITE11_FILEPATH);
		_data->assets.LoadTexture("Flip Frame 12", SARA_FLIP_SPRITE12_FILEPATH);

		_data->assets.LoadTexture("Roll Frame 1", SARA_ROLL_SPRITE1_FILEPATH);
		_data->assets.LoadTexture("Roll Frame 2", SARA_ROLL_SPRITE2_FILEPATH);
		_data->assets.LoadTexture("Roll Frame 3", SARA_ROLL_SPRITE3_FILEPATH);
		_data->assets.LoadTexture("Roll Frame 4", SARA_ROLL_SPRITE4_FILEPATH);
		_data->assets.LoadTexture("Roll Frame 5", SARA_ROLL_SPRITE5_FILEPATH);

		_data->assets.LoadFont("Score Font", SCORE_FONT_FILEPATH);

		bullets = new Bullets(_data);
		land = new Land(_data);
		sara = new Sara(_data);
		cursor = new GameCursor(_data);
		_run = _jump = _roll = _flip = _crouch = score = 0;
		bullet_frequency = BULLET_SPAWN_FREQUENCY;

		_scoreText.setFont(_data->assets.GetFont("Score Font"));
		_scoreText.setPosition(0.5 * SCREEN_WIDTH, 50);
		_scoreText.setCharacterSize(36);
		_scoreText.setFillColor(sf::Color::Magenta);
	}

	void LevelState::HandleInput()
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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			_run = true;
		}
		else
		{
			_run = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			_jump = true;
		}
		else
		{
			_jump = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
		{
			_crouch = true;
		}
		else
		{
			_crouch = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			_roll = true;
		}
		else
		{
			_roll = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			_flip = true;
		}
		else
		{
			_flip = false;
		}
	}

	void LevelState::Update(float dt)
	{
		if (score >= 100)
		{
			_data->machine.AddState(StateRef(new GameOverState(_data)), true);
		}

		bullets->MoveBulletsDown(dt);
		sara->Update(dt);

		if (bullets->IsCollidingWith(sara->GetSpriteMesh()))
		{
			bullet_frequency += (0.001 * ++score);
			_scoreText.setString(std::to_string(score));
			std::cout << "Current frequency : " << (1.f / bullet_frequency) << "\n";
		}

		if ((_clock.getElapsedTime().asSeconds() > bullet_frequency))
		{
			bullets->RandomiseBulletOffset();
			bullets->SpawnBullets();

			_clock.restart();
		}

		if (_run)
		{
			land->MoveLand(dt);
			bullets->MoveBulletsLeft(dt);
			sara->AnimateRunning(dt);
			
		} 
		else if (_jump)
		{
			sara->AnimateJumping(dt);
		}
		else if (_crouch)
		{
			sara->AnimateCrouching(dt);
		}
		else if (_roll)
		{
			sara->AnimateRolling(dt);
		}
		else if (_flip)
		{
			sara->AnimateFlipping(dt);
		}
		else
		{
			sara->AnimateStanding(dt);
		}

		//Uncomment the line below to ensure that yes, you don't need to worry about infinite tiles crashing your machine ;-)
		//std::cout << "Land tiles count: " << land->GetTilesCount() << "\n" << "Spikes count: " << spikes->GetTilesCount() << "\n";
	}

	void LevelState::Draw(float dt)
	{
		cursor->SetCursorPosition();
		_data->window.clear();

		_data->window.draw(_bg);

		land->DrawLand();
		sara->Draw();
		bullets->DrawSpikes();

		_data->window.draw(_scoreText);
		cursor->DrawCursor();
		_data->window.display();
	}
}