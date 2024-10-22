/*
 * A peripheral puzzle game based off work by NES Doug
 */

#include "LIB/neslib.h"
#include "LIB/zaplib.h"
#include "LIB/padlib.h"
#include "LIB/nesdoug.h"
#include "Sprites.h" // holds our metasprite data
#include "perrypuzzler.h"
#include "MAPS/perrytiles.h"
#include "MAPS/titletiles.h"

/**
 * Work Needed
 *
 * [] Sound FX
 * [] Music
 * [] More Levels
 * [] add other controller reading logic
 * [] update title screen
 *
 */

/**
 * Level ideas:
 * 1. [Controller] Empty with Flag
 * 2. [Controller] Maze
 * 3. [Controller]+NES Screen wrap
 * 4. [Controller] 90 Degree shift
 * 5. [2ndController] use 2nd controller only
 * 6. [Controller+Zapper] duck level
 * 7. [Controller]+[Zapper] Controller looks, zapper moves on press down (shoot to move him)
 * 8. [Powerpad] track and field, moves from power
 * 9. [Powerpad]+[Controller] falling floor you gotta press the buttons
 * 10. [Powerpad]+[Controller] Lights out + walk to goal
 * 11. [Powerpad]+[Zapper]+[Controller] but you have to shoot the lights by turning them on (maybe plus controller)
 * 12. [NES Advantage] Flag raising level
 * 13. zen level without controller plugged in? (https://forums.nesdev.org/viewtopic.php?t=7411)
 * 14. [Controller]+[NES] restart the system after writing a bunch of bytes to memory, check for them after.
 * 15. [GameGenie]+[Controller] level shows code, input code to produce flag.
 *
 *
 * microphone on famicom
 * nes famicom adapter
 * button pressing screen scrolling with NES advantage
 * * move house around instead of dog
 * shoot a big NES controller
 * 15. Controller+NES Scrolling?
 * 15. [Controller]+[NES] Sprite limit of 64 with some small 8px barrier to get through
 * 16. [Controller]+[NES] Buttons swap palette to hide sprite boxes (make them non-collidable)
 * 17. [Controller]+[NES] push boxes into a row to screw up sprite limit on a line
 * 12. [NESAdvantage] use turbo buttons to move obstacles, but somehow different frequencies
 * 13. [NESAdvantage] read every other command from other controller (aka flip 1/2player switch)
 * 5. [Controller]+[Controller] use both controllers (one looks one moves, a la smashTV) ?
 *
 * requires save
 * * 14. [GameGenie]+[Controller] level shows code, input code to produce flag.
 */

void main(void)
{

	ppu_off(); // screen off

	// load the palettes
	pal_bg(palette_perrytileset_a);
	pal_spr(palette_perrypuzzlesprites_a);
	bank_spr(1);
	set_scroll_y(0xff); // shift the bg down 1 pixel
	set_vram_buffer();
	ppu_wait_nmi();

	init_mode_title();

	set_music_speed(8);
	music_play(1);
	fade_on = 1;

	game_genie_code = 0xAF; // 0xA9 0xAF is the code we're looking for
	ppu_wait_nmi();
	if (game_genie_code == 0xBB)
	{
		duck_exists = 1;
		scroll_x = 0;
		level = GIMMICK_GAME_GENIE;
		pal_bg(palette_perrytileset_a);
		init_level();
		music_play(0);
		game_mode = MODE_GAME;
	}

	// check for last level gimmick
	if (last_level1 == 0xFE || last_level2 == 0xFE || last_level3 == 0xFE || last_level4 == 0xFE || last_level5 == 0xFE || last_level6 == 0xFE || last_level7 == 0xFE || last_level8 == 0xFE)
	{
		level = GIMMICK_NES;
		game_mode = MODE_GAME;
	}

	while (1)
	{

		if (game_mode == MODE_TITLE)
		{
			ppu_wait_nmi();
			pad1 = pad_poll(0);
			pad1_new = get_pad_new(0);

			title_cutscene();

			if (pad1_new & PAD_START)
			{
				music_stop();
				init_mode_introcutscene();
			}
		}
		else if (game_mode == MODE_INTRO_CUTSCENE)
		{
			ppu_wait_nmi();
			pad1 = pad_poll(0);
			pad1_new = get_pad_new(0);

			if (level == PERRY_HOUSE)
			{
				intro_cutscene_one();
			}
			else
			{
				intro_cutscene_two();
			}

			if (pad1_new & PAD_START)
			{
				init_mode_game();
			}
		}
		else if (game_mode == MODE_GAME_OVER)
		{
			ppu_wait_nmi();
			pad1 = pad_poll(0);
			pad1_new = get_pad_new(0);
			if (pad1_new & PAD_START)
			{
				game_mode = MODE_GAME;
			}
		}
		else if (game_mode == MODE_LEVEL_SELECT)
		{
			ppu_wait_nmi();
			pad1 = pad_poll(0);
			pad1_new = get_pad_new(0);
			// move left and right, up and down to select a level
			// wait til we've got more levels?
			if (pad1_new & PAD_START)
			{
				game_mode = MODE_GAME;
			}
		}
		else if (game_mode == MODE_GAME)
		{
			ppu_wait_nmi();

			// debug code
			//  pad1 = pad_poll(0);				 // read the first controller
			//  pad1_new = get_pad_new(0); // newly pressed button. do pad_poll first
			//  if(pad1_new & PAD_SELECT){
			//  	level_up();
			//  }

			if (level == GIMMICK_RESET)
			{
				last_level1 = 0xFE;
				last_level2 = 0xFE;
				last_level3 = 0xFE;
				last_level4 = 0xFE;
				last_level5 = 0xFE;
				last_level6 = 0xFE;
				last_level7 = 0xFE;
				last_level8 = 0xFE;
			}

			if (level == GIMMICK_TWO_PLAYER)
			{
				pad1 = pad_poll(1);				 // read the first controller
				pad1_new = get_pad_new(1); // newly pressed button. do pad_poll first
			}
			else if (level == GIMMICK_TRACK_AND_FIELD)
			{
				powerpad_cur = read_powerpad(0);
				process_powerpad(); // goes after the read
														// transfers only new presses to powerpad_new
														// powerpad_new isn't used here, but
														// would be very useful for a game

				// 2,3 face up
				// 5 face left
				// 8 face right
				// 10,11 face down
				if (powerpad_new & POWERPAD_2)
				{
					pad1_new = PAD_UP;
				}
				else if (powerpad_new & POWERPAD_3)
				{
					pad1_new = PAD_UP;
				}
				else if (powerpad_new & POWERPAD_5)
				{
					pad1_new = PAD_RIGHT;
				}
				else if (powerpad_new & POWERPAD_8)
				{
					pad1_new = PAD_LEFT;
				}
				else if (powerpad_new & POWERPAD_10)
				{
					pad1_new = PAD_DOWN;
				}
				else if (powerpad_new & POWERPAD_11)
				{
					pad1_new = PAD_DOWN;
				}
				// change where they're looking.
				movement_user_direction();

				if (powerpad_new & POWERPAD_6)
				{
					if (powerpad_old_button == POWERPAD_7)
					{
						amount_to_move = 2;
						movement_user_forward();
					}
					powerpad_old_button = POWERPAD_6;
				}
				else if (powerpad_new & POWERPAD_7)
				{
					if (powerpad_old_button == POWERPAD_6)
					{
						amount_to_move = 2;
						movement_user_forward();
					}
					powerpad_old_button = POWERPAD_7;
				}

				// user needs to press 6 then 7 to move forward.
			}
			else
			{
				pad1 = pad_poll(0);				 // read the first controller
				pad1_new = get_pad_new(0); // newly pressed button. do pad_poll first
			}

			if (level == GIMMICK_DUCK_HUNT)
			{
				zapper_ready = pad2_zapper ^ 1; // XOR last frame, make sure not held down still
				// is trigger pulled?
				pad2_zapper = zap_shoot(1); // controller slot 2
				if ((pad2_zapper) && (zapper_ready))
				{
					// trigger pulled, play bang sound

					// bg off, project white boxes
					oam_clear();
					draw_shootable_box(); // redraw the star as a box
					ppu_mask(0x16);				// BG off, won't happen till NEXT frame

					ppu_wait_nmi(); // wait till the top of the next frame
					// this frame will display no BG and a white box

					draw_bg();
					oam_clear();		// clear the NEXT frame
					ppu_mask(0x1e); // bg on, won't happen till NEXT frame

					hit_detected = zap_read(1); // look for light in zapper, port 2

					if (hit_detected)
					{
						sfx_play(SFX_CRASH, 0);
						// play a sound when duck dies? (dog laughing?)
						//  sfx_play(0, 0);
						duck_exists = 0;
					}
					else
					{
						sfx_play(SFX_FALL, 0);
					}
					// if hit failed, it should have already ran into the next nmi
				}
			}

			if (level == GIMMICK_GUMSHOE)
			{
				// update player movement
				if (player_moving)
				{
					// move player
					movement_user_forward();
				}
				else
				{
					movement_user_direction();

					zapper_ready = pad2_zapper ^ 1; // XOR last frame, make sure not held down still
					// is trigger pulled?
					pad2_zapper = zap_shoot(1); // controller slot 2
					if ((pad2_zapper) && (zapper_ready))
					{
						// trigger pulled, play bang sound

						// bg off, project white boxes
						oam_clear();
						draw_shootable_box(); // redraw the star as a box
						ppu_mask(0x16);				// BG off, won't happen till NEXT frame

						ppu_wait_nmi(); // wait till the top of the next frame
						// this frame will display no BG and a white box

						draw_bg();
						oam_clear();		// clear the NEXT frame
						ppu_mask(0x1e); // bg on, won't happen till NEXT frame

						hit_detected = zap_read(1); // look for light in zapper, port 2

						if (hit_detected)
						{
							sfx_play(SFX_CRASH, 0);
							player_moving = 1;
							is_moving = 1;
							amount_to_move = 4;
						}
						else
						{
							sfx_play(SFX_FALL, 0);
						}
						// if hit failed, it should have already ran into the next nmi
					}
				}
			}
			if (level == GIMMICK_SCREEN_SCROLL)
			{
				++frame_count;
				if (frame_count == 20)
				{
					if (scroll_x > 0)
					{
						--scroll_x;
					}
					frame_count = 0;
				}
				set_scroll_x(scroll_x);

				if (pad1_new & PAD_A || pad1_new & PAD_B)
				{
					if (scroll_x < 256)
					{
						scroll_x += 1;
					}
				}
			}

			if (level == GIMMICK_TURBO_FLAGS)
			{
				++frame_count;

				if (frame_count >= 60)
				{
					frame_count = 0;
					last_turbo_a_rate = turbo_a_rate;
					last_turbo_b_rate = turbo_b_rate;
					turbo_a_rate = 0;
					turbo_b_rate = 0;
				}
				// first flag goes down at 1 pixel every 10 frames
				if (frame_count % 10 == 0)
				{
					if (last_turbo_a_rate > 0)
					{
						if (flag_a > 0)
						{
							--flag_a;
						}
					}
					else
					{ // button hasn't been pressed in 60 second, fast drop
						if (flag_a > 4)
						{
							flag_a -= 4;
						}
						else
						{
							flag_a = 0;
						}
					}
				}

				// second flag goes down at 1 pixel every 25 frames
				if (frame_count == 25 || frame_count == 50)
				{
					if (last_turbo_b_rate > 0)
					{
						if (flag_b > 0)
						{
							--flag_b;
						}
					}
					else
					{ // button hasn't been pressed in 60 second, fast drop
						if (flag_b > 4)
						{
							flag_b -= 4;
						}
						else
						{
							flag_b = 0;
						}
					}
				}

				if (pad1_new & PAD_A)
				{
					++turbo_a_rate;
					if (flag_a < 110)
					{
						++flag_a;
					}
				}

				if (pad1_new & PAD_B)
				{
					++turbo_b_rate;
					if (flag_b < 110)
					{
						++flag_b;
					}
				}

				// check the flags and set them

				if (flag_a >= TURBO_FLAG_A_MIN && flag_a <= TURBO_FLAG_A_MAX)
				{
					if (a_entering)
					{
						sfx_play(SFX_RINGER1, 0);
						a_entering = 0;
					}
					a_flag = 1;
				}
				else
				{
					a_entering = 1;
					a_flag = 0;
				}

				if (flag_b >= TURBO_FLAG_B_MIN && flag_b <= TURBO_FLAG_B_MAX)
				{
					if (b_entering)
					{
						sfx_play(SFX_RINGER2, 0);
						b_entering = 0;
					}
					b_flag = 1;
				}
				else
				{
					b_entering = 1;
					b_flag = 0;
				}
			}

			// this will expand for gumshoe
			if (level != GIMMICK_TRACK_AND_FIELD && level != GIMMICK_GUMSHOE)
			{
				movement();
			}

			draw_sprites();
		}
		else if (game_mode == MODE_LEVEL_END)
		{
			sfx_play(SFX_VICTORY, 0);
			for (index = 0; index < 60; ++index)
			{
				ppu_wait_nmi();
			}
			pal_fade_to(4, 0); // fade to black
			level_up();
			// move to center of tile
			//  draw_sprites();
			// animate out
		}
		else
		{
			game_mode = MODE_TITLE;
		}
	}
}

void draw_shootable_box(void)
{
	if (level == GIMMICK_DUCK_HUNT && duck_exists)
	{
		oam_meta_spr(112, 136, White_duck_data);
	}

	if (level == GIMMICK_GUMSHOE)
	{
		oam_meta_spr(BoxGuy1.X-5, BoxGuy1.Y-6, White_perry_data);
	}
}

void draw_bg(void)
{
	ppu_off(); // screen off

	p_maps = Level_List[level];
	// copy the collision map to c_map
	memcpy(c_map, p_maps, 240);

	clear_vram_buffer();
	set_data_pointer(Level_List[level]);

	set_mt_pointer(perrytiles);

	if (level == GIMMICK_SCREEN_SCROLL)
	{
		nametable_to_use = 1;
		// clear first nametable
		for (y = 0;; y += 0x20)
		{
			for (x = 0;; x += 0x20)
			{
				address = get_ppu_addr(0, x, y);
				buffer_4_mt(address, 0); // ppu_address, index to the data
				flush_vram_update2();
				if (x == 0xe0)
					break;
			}
			if (y == 0xe0)
				break;
		}
	}
	else
	{
		scroll_x = 0;
		set_scroll_x(scroll_x);
		nametable_to_use = 0;
	}

	for (y = 0;; y += 0x20)
	{
		for (x = 0;; x += 0x20)
		{
			address = get_ppu_addr(nametable_to_use, x, y);
			index = (y & 0xf0) + (x >> 4);
			buffer_4_mt(address, index); // ppu_address, index to the data
			flush_vram_update2();
			if (x == 0xe0)
				break;
		}
		if (y == 0xe0)
			break;
	}
	// write level hint
	if (level != PERRY_GET_OUT && level != PERRY_HOUSE)
	{
		multi_vram_buffer_horz("Level", 5, NTADR_A(3, 1));
		if (level < 9)
		{
			one_vram_buffer(49 + level, NTADR_A(9, 1));
		}
		else
		{
			one_vram_buffer(49, NTADR_A(9, 1));					 // 1
			one_vram_buffer(39 + level, NTADR_A(10, 1)); // level-10
		}
		multi_vram_buffer_horz(level_text[level], level_text_length[level], NTADR_A(3, 2));
	}

	// set custom palette for some levels
	if (level == GIMMICK_GAME_GENIE || level == GIMMICK_RESET || level == GIMMICK_NES)
	{
		pal_bg(palette_perrytilesetnintendocolors_a);
	}
	else if (level == PERRY_GET_OUT || level == PERRY_HOUSE)
	{
		pal_bg(palette_perrytilesetcutscenecolors_a);
	}
	else
	{
		pal_bg(palette_perrytileset_a);
	}
	ppu_on_all(); // turn on screen
}

void draw_sprites(void)
{
	// clear all sprites from sprite buffer
	oam_clear();
	if (level == GIMMICK_DUCK_HUNT && duck_exists)
	{
		oam_meta_spr(112, 136, Duck_data);
	}

	if (level == GIMMICK_TURBO_FLAGS)
	{
		if (a_flag == 0 || b_flag == 0)
		{
			// todo fix this location
			oam_meta_spr(TURBO_LOCK_X, TURBO_LOCK_Y, lock_data); // show the lock
		}
	}

	if (level == GIMMICK_TURBO_FLAGS)
	{

		flag_a_pos = 160 - flag_a;
		flag_b_pos = 176 - flag_b;

		oam_meta_spr(53, flag_a_pos, perryflag0_data);	// flag_a
		oam_meta_spr(197, flag_b_pos, perryflag0_data); // flag_b

		oam_meta_spr(51, 106, flagpolelong_data);
		oam_meta_spr(195, 120, flagpolelong_data);
	}

	// draw 1 metasprite
	if (level == GIMMICK_SCREEN_SCROLL)
	{
		// scroll_x is 0x0000 and the full screen is at 0x0100 - 0x01FF
		// so the player location is 0x0100 + boxguy1.x
		// so we want to subtract scroll_x from the player location

		player_x = 0x0100 + BoxGuy1.X - scroll_x;
		draw_player_sprite();
	}
	else
	{
		draw_player_sprite();
	}
}

void movement_user_direction(void)
{
	// change the direction he's looking
	if (pad1_new & local_left)
	{
		BoxGuy1.direction = LEFT;
	}
	else if (pad1_new & local_right)
	{
		BoxGuy1.direction = RIGHT;
	}
	else if (pad1_new & local_up)
	{
		BoxGuy1.direction = UP;
	}
	else if (pad1_new & local_down)
	{
		BoxGuy1.direction = DOWN;
	}
}

void movement_user_forward(void)
{
	// move based on direction.

	if (BoxGuy1.direction == LEFT)
	{
		BoxGuy1.X -= amount_to_move;
	}
	else if (BoxGuy1.direction == RIGHT)
	{
		BoxGuy1.X += amount_to_move;
	}
	else if (BoxGuy1.direction == UP)
	{
		BoxGuy1.Y -= amount_to_move;
	}
	else if (BoxGuy1.direction == DOWN)
	{
		BoxGuy1.Y += amount_to_move;
	}
	bg_collision();
	if (collision_R)
	{
		BoxGuy1.X -= amount_to_move;
		player_moving = 0;
		is_moving = 0;
	}
	if (collision_L)
	{
		BoxGuy1.X += amount_to_move;
		player_moving = 0;
		is_moving = 0;
	}
	if (collision_D)
	{
		BoxGuy1.Y -= amount_to_move;
		player_moving = 0;
		is_moving = 0;
	}
	if (collision_U)
	{
		BoxGuy1.Y += amount_to_move;
		player_moving = 0;
		is_moving = 0;
	}
}

void movement(void)
{

	is_moving = 0;
	has_moved = 0;
	if (pad1 & local_left)
	{
		is_moving = 1;
		BoxGuy1.direction = LEFT;
		BoxGuy1.X -= 1;
		has_moved = 1;
	}
	else if (pad1 & local_right)
	{
		is_moving = 1;
		BoxGuy1.direction = RIGHT;
		BoxGuy1.X += 1;
		has_moved = 1;
	}

	bg_collision();
	if (collision_R)
		BoxGuy1.X -= 1;
	if (collision_L)
		BoxGuy1.X += 1;

	if (pad1 & local_up && has_moved == 0)
	{
		BoxGuy1.direction = UP;
		BoxGuy1.Y -= 1;
		has_moved = 1;
		is_moving = 1;
	}
	else if (pad1 & local_down && has_moved == 0)
	{
		BoxGuy1.direction = DOWN;
		BoxGuy1.Y += 1;
		has_moved = 1;
		is_moving = 1;
	}

	bg_collision();
	sprite_collision();
	if (collision_D)
		BoxGuy1.Y -= 1;
	if (collision_U)
		BoxGuy1.Y += 1;
}

void sprite_collision(void)
{
	// set the first Generic to the players attributes
	if (level == GIMMICK_DUCK_HUNT && duck_exists)
	{
		if (BoxGuy1.X >= 112 && BoxGuy1.X <= 144 && BoxGuy1.Y >= 128 && BoxGuy1.Y <= 176)
		{
			++collision_U;
		}
	}
	if (level == GIMMICK_TURBO_FLAGS)
	{
		if (a_flag == 0 || b_flag == 0)
		{
			if (
					BoxGuy1.X >= TURBO_LOCK_X && BoxGuy1.X <= TURBO_LOCK_X + 16 && BoxGuy1.Y >= TURBO_LOCK_Y && BoxGuy1.Y <= TURBO_LOCK_Y + 16)
			{
				++collision_U;
			}
		}
	}
}

void bg_collision()
{
	// sprite collision with backgrounds

	collision_L = 0;
	collision_R = 0;
	collision_U = 0;
	collision_D = 0;

	temp_x = BoxGuy1.X; // left side
	temp_y = BoxGuy1.Y; // top side

	if (temp_y >= 0xf0)
		return;
	// y out of range

	coordinates = (temp_x >> 4) + (temp_y & 0xf0); // upper left
	collision2 = c_map[coordinates];
	if (metatile_colision_map[collision2])
	{ // find a corner in the collision map
		++collision_L;
		++collision_U;
		if (metatile_colision_map[collision2] == GOAL_FLAG)
		{
			init_mode_level_end();
		}
	}

	temp_x = BoxGuy1.X + BoxGuy1.width; // right side

	coordinates = (temp_x >> 4) + (temp_y & 0xf0); // upper right
	collision2 = c_map[coordinates];
	if (metatile_colision_map[collision2])
	{
		++collision_R;
		++collision_U;
		if (metatile_colision_map[collision2] == GOAL_FLAG)
		{
			init_mode_level_end();
		}
	}

	temp_y = BoxGuy1.Y + BoxGuy1.height; // bottom side
	if (temp_y >= 0xf0)
		return;
	// y out of range

	coordinates = (temp_x >> 4) + (temp_y & 0xf0); // bottom right
	collision2 = c_map[coordinates];
	if (metatile_colision_map[collision2])
	{
		++collision_R;
		++collision_D;
		if (metatile_colision_map[collision2] == GOAL_FLAG)
		{
			init_mode_level_end();
		}
	}

	temp_x = BoxGuy1.X; // left side

	coordinates = (temp_x >> 4) + (temp_y & 0xf0); // bottom left
	collision2 = c_map[coordinates];
	if (metatile_colision_map[collision2])
	{
		++collision_L;
		++collision_D;
		if (metatile_colision_map[collision2] == GOAL_FLAG)
		{
			init_mode_level_end();
		}
	}
}

void init_mode_level_end(void)
{
	game_mode = MODE_LEVEL_END;
}

void level_up(void)
{
	++level;
	if (level >= LAST_LEVEL)
	{
		init_level();
		game_mode = MODE_GAME_OVER;
		level = 0;
	}
	else
	{
		init_level();
	}
}

#include "MAPS/levels/title.c"

void init_mode_title(void)
{
	// draw the title screen
	ppu_off();
	// pal_bg(palette_bg);
	clear_vram_buffer();
	set_data_pointer(title_0);
	set_mt_pointer(titletiles);

	pal_bg(title_bg_palette);

	for (y = 0;; y += 0x20)
	{
		for (x = 0;; x += 0x20)
		{
			address = get_ppu_addr(0, x, y);
			index = (y & 0xf0) + (x >> 4);
			buffer_4_mt(address, index); // ppu_address, index to the data
			flush_vram_update2();
			if (x == 0xe0)
				break;
		}
		if (y == 0xe0)
			break;
	}
	ppu_on_all();
	game_mode = MODE_TITLE;
	frame_count = 0;
	frame_count2 = 0;
	BoxGuy1.X = 0;
	BoxGuy1.Y = 138;
	BoxGuy1.direction = RIGHT;
}

void title_cutscene(void)
{
	oam_clear();
	oam_meta_spr(48, 72, eyewag0_data);

	// tounge and tail wag continuously
	++frame_count3;
	++frame_count4;
	if (frame_count3 <= 10)
	{
		oam_meta_spr(48, 96, tonguewag1_data);
	}
	else if (frame_count3 <= 20)
	{
		oam_meta_spr(48, 96, tonguewag2_data);
	}
	else if (frame_count3 <= 30)
	{
		oam_meta_spr(48, 96, tonguewag1_data);
	}
	else if (frame_count3 <= 40)
	{
		oam_meta_spr(48, 96, tonguewag0_data);
	}
	else if (frame_count3 <= 50)
	{
		oam_meta_spr(48, 96, tonguewag1_data);
	}
	else if (frame_count3 <= 60)
	{
		oam_meta_spr(48, 96, tonguewag2_data);
	}
	else if (frame_count3 <= 70)
	{
		oam_meta_spr(48, 96, tonguewag1_data);
	}
	else
	{
		oam_meta_spr(48, 96, tonguewag0_data);
	}

	if (frame_count4 >= 160 && frame_count4 < 170)
	{
		oam_meta_spr(192, 96, tailwag0_data);
	}
	else if (frame_count4 < 180)
	{
		oam_meta_spr(192, 96, tailwag1_data);
	}
	else if (frame_count4 < 190)
	{
		oam_meta_spr(192, 96, tailwag2_data);
	}
	else if (frame_count4 < 200)
	{
		oam_meta_spr(192, 96, tailwag1_data);
	}
	else if (frame_count4 < 210)
	{
		oam_meta_spr(192, 96, tailwag0_data);
	}
	else if (frame_count4 < 220)
	{
		oam_meta_spr(192, 96, tailwag1_data);
	}
	else if (frame_count4 < 230)
	{
		oam_meta_spr(192, 96, tailwag2_data);
	}
	else if (frame_count4 < 240)
	{
		oam_meta_spr(192, 96, tailwag1_data);
	}
	else if (frame_count4 < 250)
	{
		oam_meta_spr(192, 96, tailwag0_data);
	}
	else
	{
		oam_meta_spr(192, 96, tailwag1_data);
	}

	// perry comes out stage left, walks right, looks back, then runs off stage right

	if (frame_count > 254 && frame_count2 > 1 || BoxGuy1.X > 248)
	{
		return;
	}
	else
	{
		++frame_count;
	}

	if (frame_count > 200)
	{
		++frame_count2;
		frame_count = 0;
	}

	if (frame_count2 < 1)
	{
		return;
	}

	if (frame_count < 60)
	{
		is_moving = 1;
		BoxGuy1.X += 1;
	}
	else if (frame_count < 80)
	{
		BoxGuy1.direction = LEFT;
		is_moving = 0;
	}
	else if (frame_count < 100)
	{
		BoxGuy1.direction = RIGHT;
	}
	else if (frame_count < 110)
	{
		BoxGuy1.direction = LEFT;
		is_moving = 0;
	}
	else if (frame_count < 120)
	{
		BoxGuy1.direction = RIGHT;
	}
	else if (frame_count < 254 && BoxGuy1.X < 248)
	{
		BoxGuy1.X += 2;
	}

	draw_player_sprite();
}

void intro_cutscene_one(void)
{
	// falling then crash noise,
	//  then next level
	oam_clear();
	++frame_count;

	if (frame_count == 40)
	{
		sfx_play(SFX_FALL, 0);
	}

	if (frame_count == 90)
	{
		sfx_play(SFX_CRASH, 0);
	}

	if (frame_count > 130)
	{

		level = PERRY_GET_OUT;
		fade_on = 0;
		init_level();
		fade_on = 1;
		frame_count = 0;
		frame_count2 = 0;
		game_mode = MODE_INTRO_CUTSCENE;
	}
}

void intro_cutscene_two(void)
{
	oam_clear();
	// play the get out sfx
	if (frame_count > 254)
	{
		++frame_count2;
	}
	else
	{
		++frame_count;
	}

	if (frame_count2 > 250)
	{
		return;
	}

	// framecount1 work
	//  perry gets out

	if (frame_count == 100)
	{
		sfx_play(SFX_PERRY, 0);
	}
	if (frame_count == 140)
	{
		sfx_play(SFX_GETOUT, 0);
	}

	// if (frame_count == 170)
	// {
	// 	sfx_play(SFX_DOOROPEN, 0);
	// }
	// if (frame_count == 190)
	// {
	// 	sfx_play(SFX_DOORCLOSE, 0);
	// }
	// wait for a while.

	if (frame_count2 > 1)
	{

		if (frame_count2 < 130)
		{
			// walk to road
			is_moving = 1;
			BoxGuy1.X += 1;
			BoxGuy1.direction = RIGHT;
			draw_player_sprite();
		}
		else
		{
			if (BoxGuy1.Y < 248)  
			{
				// walk down road
				is_moving = 1;
				BoxGuy1.Y += 1;
				BoxGuy1.direction = DOWN;
				draw_player_sprite();
			}
		}
	}
}

void init_level(void)
{

	BoxGuy1.X = level_player_x[level];
	BoxGuy1.Y = level_player_y[level];
	if (game_genie_code == 0xBB)
	{
		BoxGuy1.X += 160;
	}
	oam_clear();
	ppu_off();

	game_mode = MODE_GAME;
	draw_bg();
	// debug, don't draw hints for now
	// if(level < LAST_LEVEL){
	// 	multi_vram_buffer_horz("Level", 5, NTADR_A(3, 1));
	// 	if(level < 9){
	// 		one_vram_buffer(49 + level, NTADR_A(9, 1));
	// 	} else {
	// 		one_vram_buffer(49, NTADR_A(9, 1)); //1
	// 		one_vram_buffer(39 + level, NTADR_A(10, 1)); //level-10
	// 	}
	// 	multi_vram_buffer_horz(level_text[level], level_text_length[level], NTADR_A(3, 2));
	// }
	set_direction();
	ppu_on_all();
	if (fade_on != 0)
	{
		pal_fade_to(0, 4);
	}
}

void set_direction(void)
{
	local_up = PAD_UP;
	local_down = PAD_DOWN;
	local_left = PAD_LEFT;
	local_right = PAD_RIGHT;

	if (level == GIMMICK_NINETY_DEGREE) // gimmick level
	{
		local_up = PAD_LEFT;
		local_down = PAD_RIGHT;
		local_left = PAD_DOWN;
		local_right = PAD_UP;
	}
}

void draw_player_sprite(void)
{
	++player_moved_frames;
	if (player_moved_frames > 32)
	{
		player_moved_frames = 0;
	}

	switch (BoxGuy1.direction)
	{
	case LEFT:
		if (is_moving)
		{
			if (player_moved_frames < 8)
			{
				pointer2 = perrywalkleft0_data;
			}
			else if (player_moved_frames < 16)
			{
				pointer2 = perrywalkleft1_data;
			}
			else if (player_moved_frames < 24)
			{
				pointer2 = perrywalkleft2_data;
			}
			else if (player_moved_frames < 32)
			{
				pointer2 = perrywalkleft1_data;
			}
			else
			{
				pointer2 = perrywalkleft0_data;
			}
		}
		else
		{
			pointer2 = perrystandleft_data;
		}

		break;
	case RIGHT:
		if (is_moving)
		{
			if (player_moved_frames < 8)
			{
				pointer2 = perrywalkright0_data;
			}
			else if (player_moved_frames < 16)
			{
				pointer2 = perrywalkright1_data;
			}
			else if (player_moved_frames < 24)
			{
				pointer2 = perrywalkright2_data;
			}
			else if (player_moved_frames < 32)
			{
				pointer2 = perrywalkright1_data;
			}
			else
			{
				pointer2 = perrywalkright0_data;
			}
		}
		else
		{
			pointer2 = perrystandright_data;
		}

		break;
	case UP:
		if (is_moving)
		{
			if (player_moved_frames < 8)
			{
				pointer2 = perrywalkup0_data;
			}
			else if (player_moved_frames < 16)
			{
				pointer2 = perrywalkup1_data;
			}
			else if (player_moved_frames < 24)
			{
				pointer2 = perrywalkup2_data;
			}
			else if (player_moved_frames < 32)
			{
				pointer2 = perrywalkup1_data;
			}
			else
			{
				pointer2 = perrywalkup0_data;
			}
		}
		else
		{
			pointer2 = perrywalkup0_data;
		}
		break;
	case DOWN:
		if (is_moving)
		{
			if (player_moved_frames < 8)
			{
				pointer2 = perrywalkdown0_data;
			}
			else if (player_moved_frames < 16)
			{
				pointer2 = perrywalkdown1_data;
			}
			else if (player_moved_frames < 24)
			{
				pointer2 = perrywalkdown2_data;
			}
			else if (player_moved_frames < 32)
			{
				pointer2 = perrywalkdown1_data;
			}
			else
			{
				pointer2 = perrywalkdown0_data;
			}
		}
		else
		{
			pointer2 = perrywalkdown0_data;
		}
		break;
	default:
		pointer2 = perrystandright_data;
		break;
	}

	if (level == GIMMICK_SCREEN_SCROLL)
	{
		if (high_byte(player_x) == 0)
		{
			oam_meta_spr(low_byte(player_x) - 1, BoxGuy1.Y - 2, pointer2);
		}
	}
	else
	{
		oam_meta_spr(BoxGuy1.X - 1, BoxGuy1.Y - 2, pointer2);
	}
}

// do after the read
void process_powerpad(void)
{

	powerpad_new = (powerpad_cur ^ powerpad_old) & powerpad_cur;

	powerpad_old = powerpad_cur;
}

void init_mode_game(void)
{
	// init values
	duck_exists = 1;
	scroll_x = 0;
	level = 0; // debug this value for starting level
	pal_bg(palette_perrytileset_a);
	init_level();
	music_play(0);
	game_mode = MODE_GAME;
}

void init_mode_introcutscene(void)
{
	frame_count = 0;
	level = PERRY_HOUSE;
	pal_bg(palette_perrytilesetcutscenecolors_a);
	init_level();
	game_mode = MODE_INTRO_CUTSCENE;
}