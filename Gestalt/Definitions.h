#pragma once

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

#define MUSIC_VOLUME 100.f
#define SOUND_VOLUME 100.f

#define MUSIC_FILEPATH "resources\\audio\\whitebat.ogg"

#define SPLASH_STATE_SHOW_TIME 5.f
#define SPLASH_SCENE_BG_FILEPATH "resources\\splash_scene_bg.png"

#define MAIN_MENU_BG_FILEPATH		"resources\\ui\\menu.png"
#define CREDITS_MENU_BG_FILEPATH	"resources\\ui\\menu.png"
#define CREDITS_INTERFACE_FILEPATH	"resources\\ui\\credits_interface.png"

#define GAME_BG_FILEPATH		"resources\\oga-swm-bg-gradient-sky.png"
#define GAME_OVER_BG_FILEPATH	"resources\\oga-swm-bg-gradient-sky.png"

/**

	UI BUTTONS, MOUSE CURSOR, GAME ICON, STATUS BARS

**/

#define GAME_TITLE_FILEPATH		"resources\\ui\\title.png"
#define START_BUTTON_FILEPATH	"resources\\ui\\start_button.png"
#define QUIT_BUTTON_FILEPATH	"resources\\ui\\quit_button.png"
#define NEXT_BUTTON_FILEPATH	"resources\\ui\\next_button.png"
#define BACK_BUTTON_FILEPATH	"resources\\ui\\back_button.png"
#define CREDITS_BUTTON_FILEPATH "resources\\ui\\credits_button.png"

#define CURSOR_FILEPATH			"resources\\ui\\cursor.png"
#define GAME_ICON_FILEPATH		"resources\\ui\\icon_red.png"
#define STATUS_BAR_FILEPATH		"resources\\ui\\status_bar.png"
#define STATUS_TILE_FILEPATH	"resources\\ui\\status_tile.png"

/**

	SOUNDS

**/

#define CLICK_SOUND_FILEPATH		"resources\\ui\\sounds\\load.wav"
#define BACK_SOUND_FILEPATH			"resources\\ui\\sounds\\load.wav"
#define GAME_OVER_SOUND_FILEPATH	"resources\\ui\\sounds\\misc_sound.wav"

/**

	PLATFORMER TILES AND SPIKES

**/

#define LAND_TILE_FILEPATH	"resources\\land.png"

#define BULLET_FILEPATH	"resources\\bullet1.png"

/**

	TILE SPEEDS, SPAWN FREQUENCIES, ANIMATION DURATIONS

**/

#define TILE_SPEED	100.f
#define BULLET_SPEED	500.f

#define SPIKE_SPAWN_FREQUENCY	3.f
#define BULLET_SPAWN_FREQUENCY	.1f	//must increase frequency gradually

#define STAND_ANIMATION_DURATION		3.f
#define RUN_ANIMATION_DURATION			1.f
#define JUMP_ANIMATION_DURATION			.6f
#define CROUCH_ANIMATION_DURATION		1.f
#define ROLL_ANIMATION_DURATION			.4f
#define FLIP_ANIMATION_DURATION			1.f

/**

	SARA ANIMATION SPRITES

**/

//IDLE

#define SARA_IDLE_SPRITE1_FILEPATH "resources\\sara\\idle1.png"
#define SARA_IDLE_SPRITE2_FILEPATH "resources\\sara\\idle2.png"
#define SARA_IDLE_SPRITE3_FILEPATH "resources\\sara\\idle3.png"
#define SARA_IDLE_SPRITE4_FILEPATH "resources\\sara\\idle4.png"

//STAND

#define SARA_STAND_SPRITE1_FILEPATH		"resources\\sara\\stand1.png"
#define SARA_STAND_SPRITE2_FILEPATH		"resources\\sara\\stand2.png"
#define SARA_STAND_SPRITE3_FILEPATH		"resources\\sara\\stand3.png"
#define SARA_STAND_SPRITE4_FILEPATH		"resources\\sara\\stand4.png"
#define SARA_STAND_SPRITE5_FILEPATH		"resources\\sara\\stand5.png"
#define SARA_STAND_SPRITE6_FILEPATH		"resources\\sara\\stand6.png"
#define SARA_STAND_SPRITE7_FILEPATH		"resources\\sara\\stand7.png"
#define SARA_STAND_SPRITE8_FILEPATH		"resources\\sara\\stand8.png"
#define SARA_STAND_SPRITE9_FILEPATH		"resources\\sara\\stand9.png"
#define SARA_STAND_SPRITE10_FILEPATH	"resources\\sara\\stand10.png"
#define SARA_STAND_SPRITE11_FILEPATH	"resources\\sara\\stand11.png"
#define SARA_STAND_SPRITE12_FILEPATH	"resources\\sara\\stand12.png"

//RUN

#define SARA_RUN_SPRITE1_FILEPATH	"resources\\sara\\run1.png"
#define SARA_RUN_SPRITE2_FILEPATH	"resources\\sara\\run2.png"
#define SARA_RUN_SPRITE3_FILEPATH	"resources\\sara\\run3.png"
#define SARA_RUN_SPRITE4_FILEPATH	"resources\\sara\\run4.png"
#define SARA_RUN_SPRITE5_FILEPATH	"resources\\sara\\run5.png"
#define SARA_RUN_SPRITE6_FILEPATH	"resources\\sara\\run6.png"
#define SARA_RUN_SPRITE7_FILEPATH	"resources\\sara\\run7.png"
#define SARA_RUN_SPRITE8_FILEPATH	"resources\\sara\\run8.png"
#define SARA_RUN_SPRITE9_FILEPATH	"resources\\sara\\run9.png"
#define SARA_RUN_SPRITE10_FILEPATH	"resources\\sara\\run10.png"
#define SARA_RUN_SPRITE11_FILEPATH	"resources\\sara\\run11.png"

//ROLL

#define SARA_ROLL_SPRITE1_FILEPATH "resources\\sara\\roll1.png"
#define SARA_ROLL_SPRITE2_FILEPATH "resources\\sara\\roll2.png"
#define SARA_ROLL_SPRITE3_FILEPATH "resources\\sara\\roll3.png"
#define SARA_ROLL_SPRITE4_FILEPATH "resources\\sara\\roll4.png"
#define SARA_ROLL_SPRITE5_FILEPATH "resources\\sara\\roll5.png"

//FLIP

#define SARA_FLIP_SPRITE1_FILEPATH	"resources\\sara\\flip1.png"
#define SARA_FLIP_SPRITE2_FILEPATH	"resources\\sara\\flip2.png"
#define SARA_FLIP_SPRITE3_FILEPATH	"resources\\sara\\flip3.png"
#define SARA_FLIP_SPRITE4_FILEPATH	"resources\\sara\\flip4.png"
#define SARA_FLIP_SPRITE5_FILEPATH	"resources\\sara\\flip5.png"
#define SARA_FLIP_SPRITE6_FILEPATH	"resources\\sara\\flip6.png"
#define SARA_FLIP_SPRITE7_FILEPATH	"resources\\sara\\flip7.png"
#define SARA_FLIP_SPRITE8_FILEPATH	"resources\\sara\\flip8.png"
#define SARA_FLIP_SPRITE9_FILEPATH	"resources\\sara\\flip9.png"
#define SARA_FLIP_SPRITE10_FILEPATH "resources\\sara\\flip10.png"
#define SARA_FLIP_SPRITE11_FILEPATH "resources\\sara\\flip11.png"
#define SARA_FLIP_SPRITE12_FILEPATH "resources\\sara\\flip12.png"

//JUMP

#define SARA_JUMP_SPRITE1_FILEPATH "resources\\sara\\jump1.png"
#define SARA_JUMP_SPRITE2_FILEPATH "resources\\sara\\jump2.png"
#define SARA_JUMP_SPRITE3_FILEPATH "resources\\sara\\jump3.png"
#define SARA_JUMP_SPRITE4_FILEPATH "resources\\sara\\jump4.png"
#define SARA_JUMP_SPRITE5_FILEPATH "resources\\sara\\jump5.png"
#define SARA_JUMP_SPRITE6_FILEPATH "resources\\sara\\jump6.png"
#define SARA_JUMP_SPRITE7_FILEPATH "resources\\sara\\jump7.png"

//CROUCH

#define SARA_CROUCH_SPRITE1_FILEPATH "resources\\sara\\crouch1.png"
#define SARA_CROUCH_SPRITE2_FILEPATH "resources\\sara\\crouch2.png"
#define SARA_CROUCH_SPRITE3_FILEPATH "resources\\sara\\crouch3.png"
#define SARA_CROUCH_SPRITE4_FILEPATH "resources\\sara\\crouch4.png"
#define SARA_CROUCH_SPRITE5_FILEPATH "resources\\sara\\crouch5.png"
#define SARA_CROUCH_SPRITE6_FILEPATH "resources\\sara\\crouch6.png"
#define SARA_CROUCH_SPRITE7_FILEPATH "resources\\sara\\crouch7.png"
#define SARA_CROUCH_SPRITE8_FILEPATH "resources\\sara\\crouch8.png"
#define SARA_CROUCH_SPRITE9_FILEPATH "resources\\sara\\crouch9.png"