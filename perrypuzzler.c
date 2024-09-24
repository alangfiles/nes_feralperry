/*
 * A peripheral puzzle game based off work by NES Doug
 */

#include "LIB/neslib.h"
#include "LIB/nesdoug.h"
#include "Sprites.h" // holds our metasprite data
#include "perrypuzzler.h"

/**
 * Work Needed
 *
 * [] Sound FX
 * [] Music
 * [] More Levels
 * [] add other controller reading logic
 * [] update title screen
 */
  
/**
 * Level ideas:
 * 1. [Controller] Empty with Flag
 * 2. [Controller] Maze with Obstacles
 * 3. [Controller] 90 Degree shift
 * 4. [Controller] use 2nd controller only
 * 5. [Controller]+[Controller] use both controllers (one looks one moves, a la smashTV)
 * 6. [Controller]+[Zapper] block in middle to shoot
 * 7. [Zapper] Gumshoe style shoot the side of him to move him to the goal? (or Controller on screen to shoot buttons at)
 * 8. [Controller]+[Zapper] Controller shoots, zapper moves on press down
 * 9. [Powerpad]+[Controller] Lights out?
 * 10. [Powerpad]+[Zapper] Lights out-ish, but you have to shoot the lights by turning them on (maybe plus controller)
 * 11. [NESAdvantage/NESMax] use turbo buttons to move obstacles
 * 12. [NESAdvantage] use turbo buttons to move obstacles, but somehow different frequencies
 * 13. [NESAdvantage] read every other command from other controller (aka flip 1/2player switch)
 * 14. [GameGenie]+[Controller] level shows code, input code to produce flag.
 * 15. [Controller]+[NES] Sprite limit of 64 with some small 8px barrier to get through
 * 16. [Controller]+[NES] Buttons swap palette to hide sprite boxes (make them non-collidable)
 * 17. [Controller]+[NES] push boxes into a row to screw up sprite limit on a line
 * 18. [Controller]+[NES] restart the system after writing a bunch of bytes to memory, check for them after.
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
				level = 0; // debug this value
				init_level();
				game_mode = MODE_GAME;
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

			if (level == 3)
			{
				pad1 = pad_poll(1);				 // read the first controller
				pad1_new = get_pad_new(1); // newly pressed button. do pad_poll first
			}
			else
			{
				pad1 = pad_poll(0);				 // read the first controller
				pad1_new = get_pad_new(0); // newly pressed button. do pad_poll first
			}
			movement();
			draw_sprites();
		}
		else if (game_mode == MODE_LEVEL_END)
		{
			for (index = 0; index < 100; ++index)
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

void draw_bg(void)
{
	ppu_off(); // screen off

	p_maps = Level_List[level];
	// copy the collision map to c_map
	memcpy(c_map, p_maps, 240);

	// pal_bg(palette_bg);
	clear_vram_buffer();
	set_data_pointer(Level_List[level]);
	set_mt_pointer(metatiles);
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


	ppu_on_all(); // turn on screen
}

void draw_sprites(void)
{
	// clear all sprites from sprite buffer
	oam_clear();

	// draw 1 metasprite
	draw_player_sprite();
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
	if (collision_D)
		BoxGuy1.Y -= 1;
	if (collision_U)
		BoxGuy1.Y += 1;
}

void sprite_collision(void)
{
	// if (BoxGuy1.X >= level_goal_x[level]-3 && BoxGuy1.X <= level_goal_x[level]+3
	// && BoxGuy1.Y >= level_goal_y[level]-3 && BoxGuy1.Y <= level_goal_y[level]+3)
	// {
	// 	init_mode_level_end();
	//
	// }
	
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
	if (level >= 4)
		level = 0;

	init_level();
}

#include "MAPS/levels/title.c"
void init_mode_title(void)
{
	// draw the title screen
	ppu_off();
	// pal_bg(palette_bg);
	clear_vram_buffer();
	set_data_pointer(title_0);
	set_mt_pointer(metatiles);
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
	multi_vram_buffer_horz("Brian And Alan Games", 20, NTADR_A(6, 24));
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
	//tounge and tail wag continuously
	
	++frame_count3;
	++frame_count4;
	if (frame_count3 <= 20)
	{
		oam_meta_spr(48, 96, tonguewag0_data);
	} else if (frame_count3 <= 40){
		oam_meta_spr(48, 96, tonguewag1_data);
	} else if (frame_count3 <= 60){
		oam_meta_spr(48, 96, tonguewag2_data);
	} else {
		oam_meta_spr(48, 96, tonguewag1_data);
	}

	if(frame_count4 >= 200 && frame_count4 < 210){
		oam_meta_spr(192, 96, tailwag0_data);
	} else if (frame_count4 < 220){
		oam_meta_spr(192, 96, tailwag1_data);
	} else if (frame_count4 < 230){
		oam_meta_spr(192, 96, tailwag2_data);
	} else if (frame_count4 < 240){
		oam_meta_spr(192, 96, tailwag1_data);
	} else if (frame_count4 < 250){
		oam_meta_spr(192, 96, tailwag0_data);
	} else {
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

void init_level(void)
{
	BoxGuy1.X = level_player_x[level];
	BoxGuy1.Y = level_player_y[level];
	oam_clear();
	ppu_off();

	game_mode = MODE_GAME;
	draw_bg();
	multi_vram_buffer_horz("Level", 5, NTADR_A(3, 1));
	one_vram_buffer(49 + level, NTADR_A(9, 1));
	multi_vram_buffer_horz(level_text[level], level_text_length[level], NTADR_A(3, 2));
	set_direction();
	ppu_on_all();
	pal_fade_to(0, 4);
}

void set_direction(void)
{
	local_up = PAD_UP;
	local_down = PAD_DOWN;
	local_left = PAD_LEFT;
	local_right = PAD_RIGHT;

	if (level == 2)
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
	oam_meta_spr(BoxGuy1.X, BoxGuy1.Y, pointer2);
}