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
	pal_bg(palette_bg);
	pal_spr(palette_sp);  
	bank_spr(1);
	set_scroll_y(0xff); // shift the bg down 1 pixel
	set_vram_buffer();
	ppu_wait_nmi();
	ppu_off();
	multi_vram_buffer_horz("Feral Perry's", 13, NTADR_A(9,10));
	multi_vram_buffer_horz("Peripheral Palace", 17, NTADR_A(7,12));
	ppu_on_all();
	
	game_mode = MODE_TITLE;

	while (1)
	{

		if (game_mode == MODE_TITLE)
		{
			ppu_wait_nmi();
			pad1 = pad_poll(0);
			pad1_new = get_pad_new(0);
			if (pad1_new & PAD_START)
			{
				level = 0; //debug this value
				init_level_text();
				game_mode = MODE_LEVEL_TITLE;
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
		else if (game_mode == MODE_LEVEL_TITLE)
		{  
			oam_clear();
			// draw a blank background with the text provided
			ppu_wait_nmi();
			pad1 = pad_poll(0);
			pad1_new = get_pad_new(0);
			if (pad1_new & PAD_START)
			{
				game_mode = MODE_GAME;
				draw_bg(); 
				set_direction();
			}
		}
		else if (game_mode == MODE_GAME)
		{
			ppu_wait_nmi();

			if(level == 3){
				pad1 = pad_poll(1);				 // read the first controller
				pad1_new = get_pad_new(1); // newly pressed button. do pad_poll first
			} else {
				pad1 = pad_poll(0);				 // read the first controller
				pad1_new = get_pad_new(0); // newly pressed button. do pad_poll first
			}
			

			movement();
			sprite_collision();
			draw_sprites();
			check_start();
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

	p_maps = All_Collision_Maps[level];
	// copy the collision map to c_map
	memcpy(c_map, p_maps, 240);

	// this sets a start position on the BG, top left of screen
	vram_adr(NAMETABLE_A);

	// draw a row of tiles
	for (temp_y = 0; temp_y < 15; ++temp_y)
	{
		for (temp_x = 0; temp_x < 16; ++temp_x)
		{
			temp1 = (temp_y << 4) + temp_x;

			if (c_map[temp1])
			{
				vram_put(0x10); // wall
				vram_put(0x10);
			}
			else
			{
				vram_put(0); // blank
				vram_put(0);
			}
		}

		// draw a second row of tiles
		for (temp_x = 0; temp_x < 16; ++temp_x)
		{
			temp1 = (temp_y << 4) + temp_x;

			if (c_map[temp1])
			{
				vram_put(0x10); // wall
				vram_put(0x10);
			}
			else
			{
				vram_put(0); // blank
				vram_put(0);
			}
		}
	}

	ppu_on_all(); // turn on screen
}

void draw_sprites(void)
{
	// clear all sprites from sprite buffer
	oam_clear();
     
	// draw 1 metasprite
	draw_player_sprite();
	oam_meta_spr(level_goal_x[level], level_goal_y[level], GoalFlag);
}

void movement(void)
{
	has_moved = 0;
	if (pad1 & local_left)
	{
		BoxGuy1.direction = LEFT;
		BoxGuy1.X -= 1;
		has_moved = 1;
	}
	else if (pad1 & local_right)
	{
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
	}
	else if (pad1 & local_down && has_moved == 0)
	{
		BoxGuy1.direction = DOWN;
		BoxGuy1.Y += 1;
		has_moved = 1;
	}

	bg_collision();
	if (collision_D)
		BoxGuy1.Y -= 1;
	if (collision_U)
		BoxGuy1.Y += 1;
}

void sprite_collision(void)
{
	if (BoxGuy1.X >= level_goal_x[level]-3 && BoxGuy1.X <= level_goal_x[level]+3
	&& BoxGuy1.Y >= level_goal_y[level]-3 && BoxGuy1.Y <= level_goal_y[level]+3)
	{
		level_up();
		show_text = 1;
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
	if (c_map[coordinates])
	{ // find a corner in the collision map
		++collision_L;
		++collision_U;
	}

	temp_x = BoxGuy1.X + BoxGuy1.width; // right side

	coordinates = (temp_x >> 4) + (temp_y & 0xf0); // upper right
	if (c_map[coordinates])
	{
		++collision_R;
		++collision_U;
	}

	temp_y = BoxGuy1.Y + BoxGuy1.height; // bottom side
	if (temp_y >= 0xf0)
		return;
	// y out of range

	coordinates = (temp_x >> 4) + (temp_y & 0xf0); // bottom right
	if (c_map[coordinates])
	{
		++collision_R;
		++collision_D;
	}

	temp_x = BoxGuy1.X; // left side

	coordinates = (temp_x >> 4) + (temp_y & 0xf0); // bottom left
	if (c_map[coordinates])
	{
		++collision_L;
		++collision_D;
	}
}

void level_up(void)
{
	++level;
	if (level >= 4)
		level = 0;
	game_mode = MODE_LEVEL_TITLE;
	init_level_text();
}

void init_level_text(void){
	BoxGuy1.X = level_player_x[level];
	BoxGuy1.Y = level_player_y[level];
	oam_clear();
	ppu_off();
	vram_adr(NAMETABLE_A);
	vram_fill(0, 0x1000);
	ppu_wait_nmi();

	multi_vram_buffer_horz("Level", 5, NTADR_A(3,7));
	// multi_vram_buffer_horz(, 2, NTADR_A(9,7));
	one_vram_buffer(49+level, NTADR_A(9,7));

	multi_vram_buffer_horz(level_text[level], level_text_length[level], NTADR_A(3,10));
	ppu_on_all();
}

void check_start(void)
{
	// if START is pressed, load another background
	if (pad1_new & PAD_START)
	{
		++level;
		if (level >= 4)
			level = 0;
		game_mode = MODE_LEVEL_TITLE;
		init_level_text();
	}
}

void set_direction(void){
	local_up = PAD_UP;
	local_down = PAD_DOWN;
	local_left = PAD_LEFT;
	local_right = PAD_RIGHT;

	if(level == 2){
		local_up = PAD_LEFT;
		local_down = PAD_RIGHT;
		local_left = PAD_DOWN;
		local_right = PAD_UP;
	}
}

void draw_player_sprite(void)
{
	switch (BoxGuy1.direction)
	{
    case LEFT:
		pointer2 = _perrystandleft_data;
		break;
    case RIGHT:
		pointer2 = _perrystandright_data;
		break;
    case UP:
		pointer2 = _perrywalkup0_data;
		break;
    case DOWN:
			pointer2 = _perrywalkdown0_data;
		break;
		default:
			pointer2 = _perrystandright_data;
		break;
	}
	oam_meta_spr(BoxGuy1.X, BoxGuy1.Y, pointer2);
}