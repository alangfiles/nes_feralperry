
enum
{
	MODE_TITLE,
	MODE_GAME,
	MODE_PAUSE,
	MODE_SWITCH,
	MODE_END,
	MODE_LEVEL_TITLE,
	MODE_LEVEL_END,
	MODE_LEVEL_SELECT,
	MODE_GAME_OVER,
	MODE_RESET
};

#pragma bss-name(push, "ZEROPAGE")

// GLOBAL VARIABLES
unsigned char pad2_zapper;
unsigned char zapper_ready; //wait till it's 0
unsigned char hit_detected;
unsigned char pad1;
unsigned char pad1_new;
unsigned char pad2;
unsigned char pad2_new;
unsigned char collision;
unsigned char collision_L;
unsigned char collision_R;
unsigned char collision_U;
unsigned char collision_D;
unsigned char collision2;
unsigned char level;
const unsigned char * p_maps;
unsigned char coordinates;
unsigned char temp1;
unsigned char temp2;
unsigned char temp3;
unsigned char temp4;
unsigned char temp_x;
unsigned char temp_y;
unsigned char game_mode;
unsigned char show_text;
unsigned char has_moved;
unsigned char is_moving;
unsigned char player_moved_frames;
unsigned char frame_count;
unsigned char frame_count2;
unsigned char frame_count3;
unsigned char frame_count4;
unsigned char duck_exists;

unsigned char local_left;
unsigned char local_right;
unsigned char local_up;
unsigned char local_down;
const unsigned char * pointer2;

struct Base {
	unsigned char x;
	unsigned char y;
	unsigned char width;
	unsigned char height;
};

struct Base Generic; 
struct Base Generic2;

// room loader code
int address;
unsigned char x; 
unsigned char y;
unsigned char index = 0;
unsigned char index2;

#pragma bss-name(push, "BSS")

unsigned char c_map[240];
// collision map 


enum {
	LEFT,
	RIGHT,
	UP,
	DOWN
};

struct BoxGuy {
	unsigned char X;
	unsigned char Y;
	unsigned char width;
	unsigned char height;
	unsigned char direction;
};


struct BoxGuy BoxGuy1 = {64,80,13,14, LEFT};








// these are the 4 backgrounds
// collision data, made by exporting csv from Tiled, and slight modification by CSV2C.py
#include "MAPS/levels/level1.c"
#include "MAPS/levels/level2.c"
#include "MAPS/levels/level3.c"
#include "MAPS/levels/level4.c"
#include "MAPS/levels/level5.c"
#include "MAPS/levels/level6.c"
#include "MAPS/levels/level7.c"
#include "MAPS/levels/level8.c"
#include "MAPS/levels/level9.c"
#include "MAPS/levels/level10.c"
#include "MAPS/levels/level11.c"
#include "MAPS/levels/level12.c"
#include "MAPS/levels/level13.c"
#include "MAPS/levels/level14.c"
#include "MAPS/levels/level15.c"
#include "MAPS/levels/level16.c"
#include "MAPS/levels/level17.c"

#include "MAPS/levels/bigperry.c"


#define GIMMICK_TWO_PLAYER 3
#define GIMMICK_DUCK_HUNT 5
#define GIMMICK_NINETY_DEGREE 4
#define GIMMICK_SCREEN_SCROLL 6

#define LAST_LEVEL 17

/**
 * Level List
Level 1 - Wide open, get to the house (no gimmick)
Level 2 - Maze to the house (no gimmick)
Level 3 - Wrap Around (no gimmick)
Level 4 - Road in middle, (2nd controller)
Level 6 - Maze (90 degree gimmick)
Level 5 - For the duck hunt statue (zapper gimmick (need zapper plus sprite blocking)
Level 7 - Nametable 2 screen scroll gimmick (turbo)
Level 8 - Flagpole Advantage Knob Turner (nes advantage turbo gimmick)
--Level 9 - Destroy the sprite barrier by putting sprites in a row
--Level 10 - Powerpad Jehovah Indiana Jones.  The cones can look much better with a pallette tweak specifically for this level.  But that can be done later.  Level divided into 12 sectors.
--Level 11 - For the lights out scenarios.  This would give you a 4x3 grid.  Any morand we might have to deal with changing the lights from sprites to BG.
--Level 12 - All there is is a house behind a fence.  I imagined it as a no input level.  But if you want something to do, I could imagine the little lawnmower mowing all the grass here.  
Level 13 - I think this is what you wanted for the gumshoe one - point him in direction, shoot him, and he'll zip as far as he can go in that direction.  I intend Perry to start two sqaures above the house. 
Level 14 - Powerpad directional controls.  It's designed to look a little like a track and field event.  
Level 15 - Just something I'm fiddling with.  I imagine using the buttons icons to move multiple characters.  I dunno.  
Level 16 - I imagined this for the game genie one.  It is really just a black box where you can put in some text.  
Level 17 - Reset the game - Top half of the screen is a grass area with a fenced in house.  Bottom half is a crude picture of the front of an NES.  
 */


const unsigned char * const Level_List[] = {
	level1_0, level2_0, level3_0, level4_0, level6_0, 
	level5_0, level7_0, level8_0, 
  // level9_0, level10_0, 
	// level11_0, level12_0, level13_0, level14_0, level15_0, 
	// level16_0, level17_0, 
  bigperry_0
	};

  //8 and 9 are levels 16 and 17

	const unsigned char * const level_text[] = {
  "Easy Peasy",
  "Not so simple",
  "A bridge too far",
  "Two Player Game",
  "Art Critic",  //5
  "Two Player Game",
  "Get to the end",
  "Sync and Spin",
  "Push it to the limit",
  "Fancy footwork", //10
  "Lights out",
  "Anarchy",
  "Point and shoot",
  "Work it out",
  "Push it", //15
  "Cheat the system",
  "Leap of faith",
};

//cant dynamically calcualte this somehow
const unsigned char level_text_length[] = {
  10,
  13,
  16,
  10,
  10,  //5
  15,
  14,
  13,
  20,
  13, //10
  10,
  7,
  15,
  11,
  7, //15
  16, 
  13,
};


const unsigned char level_player_x[] = {
  32,
  32,
  16,
  16,
  224,
  11,
  32,
  112,
  128,
  96,
  32,
  128,
  32,
  16,
  16,
  16,
  32,
};

const unsigned char level_player_y[] = {
  64,
  64,
  48,
  48,
  64,
  32,
  48,
  176,
  80,
  32,
  176,
  176,
  80,
  32,
  128,
  144,
  80,
};





const unsigned char palette_perrypuzzlesprites_a[16]={ 
  0x1a,0x30,0x0f,0x15,
  0x1a,0x11,0x21,0x20,
  0x1a,0x38,0x17,0x07,
  0x1a,0x0f,0x2d,0x3d };
const unsigned char palette_perrytileset_a[16]={ 0x1a,0x30,0x0f,0x00,0x1a,0x21,0x11,0x30,0x1a,0x38,0x17,0x07,0x1a,0x17,0x2a,0x0f };
const unsigned char title_bg_palette[16]={ 0x0f,0x30,0x1a,0x15,0x0f,0x21,0x11,0x1a,0x0f,0x38,0x17,0x07,0x0f,0x17,0x2a,0x1a };

#define COL_ALL 1
#define GOAL_FLAG 2

const unsigned char metatile_colision_map[] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, GOAL_FLAG, COL_ALL, 0, COL_ALL, COL_ALL,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, COL_ALL,
		0, 0, 0, COL_ALL, COL_ALL, COL_ALL, COL_ALL, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, COL_ALL, 0, COL_ALL, COL_ALL, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, COL_ALL, COL_ALL, COL_ALL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		COL_ALL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


// PROTOTYPES
void draw_bg(void);
void draw_sprites(void);
void movement(void);	
void bg_collision(void);
void sprite_collision(void);
void level_up(void);
void init_level(void);
void set_direction(void);
void draw_player_sprite(void);
void init_mode_title(void);
void title_cutscene(void);
void init_mode_level_end(void);
void init_game_over(void);
void draw_shootable_box(void);