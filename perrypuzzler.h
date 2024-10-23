
enum
{
	MODE_TITLE,
  MODE_INTRO_CUTSCENE,
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

//SOME VARIABLES HOLDING SPACE FOR THE RESET LEVEL
// should be $0000 to $0040
unsigned char last_level1;
unsigned char last_level2;
unsigned char last_level3;
unsigned char last_level4;
unsigned char last_level5;
unsigned char last_level6;
unsigned char last_level7;
unsigned char last_level8;

unsigned char game_genie_code;

// GLOBAL VARIABLES
//zapper
unsigned char pad2_zapper;
unsigned char zapper_ready; //wait till it's 0
unsigned char hit_detected;
unsigned char player_moving;

//powerpad
unsigned int powerpad_cur;
unsigned int powerpad_old; //don't use this
unsigned int powerpad_new;
unsigned int powerpad_old_button;


unsigned char amount_to_move;
unsigned char nametable_to_use;
unsigned char user_input_new;
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
unsigned int scroll_x;
unsigned char a_entering;
unsigned char b_entering;
unsigned char a_flag;
unsigned char b_flag;

unsigned char flag_a_pos;
unsigned char flag_b_pos;
unsigned char flag_a;
unsigned char flag_b;
unsigned char turbo_a_rate;
unsigned char turbo_b_rate;
unsigned char last_turbo_a_rate;
unsigned char last_turbo_b_rate;

unsigned char local_left;
unsigned char local_right;
unsigned char local_up;
unsigned char local_down;
const unsigned char * pointer2;

unsigned int player_x;
unsigned int player_y;

unsigned char fade_on;

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

#define TURBO_LOCK_X 112
#define TURBO_LOCK_Y 113
#define TURBO_FLAG_A_MAX 73
#define TURBO_FLAG_A_MIN 63
#define TURBO_FLAG_B_MAX 96
#define TURBO_FLAG_B_MIN 86

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

enum {
  MUSIC_VERNAL_TRIANGLE,
  MUSIC_EH_TRAIN,
  MUSIC_ALWAYS
};

struct BoxGuy BoxGuy1 = {64,80,12,12, LEFT};








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
#include "MAPS/levels/level18.c"

#include "MAPS/levels/bigperry.c"
#include "MAPS/levels/perrygetout.c"
#include "MAPS/levels/perryshouse.c"




/**
 * Level List
Level 1 - Wide open, get to the house (no gimmick)
Level 2 - Maze to the house (no gimmick)
Level 3 - Wrap Around (no gimmick)
Level 4 - Road in middle, (2nd controller)
Level 6 - Maze (90 degree gimmick)

Level 5 - For the duck hunt statue (zapper gimmick (need zapper plus sprite blocking)
Level 13 - gumshoe one - Zapper plus controller Shoot him and he'll move where he's facing. 
Level 7 - Nametable 2 screen scroll gimmick (turbo)
Level 8 - Flagpole Advantage Knob Turner (nes advantage turbo gimmick)
Level 14 - Powerpad directional controls.  It's designed to look a little like a track and field event.  
-- move power pad levels? lights out side A? lights out zapper side B?
Level 16 - I imagined this for the game genie one.  It is really just a black box where you can put in some text.  
Level 17 - (need to test) Reset the game - Top half of the screen is a grass area with a fenced in house.  Bottom half is a crude picture of the front of an NES.  

--unused
--Level 9 - Destroy the sprite barrier by putting sprites in a row
--Level 10 - Powerpad Jehovah Indiana Jones.  The cones can look much better with a pallette tweak specifically for this level.  But that can be done later.  Level divided into 12 sectors.
--Level 11 - For the lights out scenarios.  This would give you a 4x3 grid.  Any morand we might have to deal with changing the lights from sprites to BG.
--Level 12 - All there is is a house behind a fence.  I imagined it as a no input level.  But if you want something to do, I could imagine the little lawnmower mowing all the grass here.  
--Level 15 - Just something I'm fiddling with.  I imagine using the buttons icons to move multiple characters.  I dunno.  
 */

#define GIMMICK_TWO_PLAYER 3
#define GIMMICK_NINETY_DEGREE 4
#define GIMMICK_DUCK_HUNT 5
#define GIMMICK_GUMSHOE 6
#define GIMMICK_SCREEN_SCROLL 7
#define GIMMICK_TURBO_FLAGS 8
#define GIMMICK_TRACK_AND_FIELD 9
#define GIMMICK_GAME_GENIE 10
#define GIMMICK_RESET 11
#define GIMMICK_NES 12

#define LAST_LEVEL 12
#define PERRY_GET_OUT 14
#define PERRY_HOUSE 15


// 1.  A ringer that I imagine using when you get something right
// 2. See above.
// 3. See above.
// 4.  A victory chime for ending a level
// 5. A footstep to be alternated with number 6.  
// 6. See above
// 7.  A falling noise.  Intended to go with #9.  A fall and ten a crash, to be followed up with "PERRY!  GET OUT"
// 8.  "Perry!"
// 9. THe crash.  See 7 above. 
// 10. an opening door noise if you wanted to try to use the expanding door animation to end the level.
// 11. A closing door noise for the same. 
// 12 "Get out"  
enum {
  SFX_RINGER1,
  SFX_RINGER2,
  SFX_RINGER3,
  SFX_VICTORY,
  SFX_STEP1,
  SFX_STEP2,
  SFX_FALL,
  SFX_PERRY,
  SFX_CRASH,
  SFX_DOOROPEN,
  SFX_DOORCLOSE,
  SFX_GETOUT  
};

const unsigned char * const Level_List[] = {
	level1_0, level2_0, level3_0, level4_0, level6_0,  //5
	level5_0, level13_0, level7_0, level8_0, level14_0, //10
	level16_0, level17_0, level18_0, bigperry_0, perrygetout_0, //14
  perryshouse_0,
	};

  //8 and 9 are levels 16 and 17

	const unsigned char * const level_text[] = {
  "Easy Peasy",
  "A-maze-ing",
  "That's a wrap",
  "Two Player Game",
  "Tilt your head",  //5
  "Art Critic",
  "Gumshoe",
  "Perry Fighter Two': Turbo",
  "Turbo Advantage",
  "Track and Field", //10
  "ULSPESNX",
  "Have you tried reseting?",
  "A ROM with a view"
};

//cant dynamically calcualte this somehow
const unsigned char level_text_length[] = {
  10,
  10,
  13,
  15,
  14,  //5
  10,
  7,
  25,
  15,
  15, //10
  8,
  24,
  17,
};


const unsigned char level_player_x[] = {
  32,
  32,
  16,
  16,
  224,//5
  11,
  32,
  112,
  128,
  96, //10
  32,
  128,
  32,
  16,//14 last level
  68, //perry get out
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
  164, //perry get out
  1,
  80,
};



//Main (most levels) Pallette:
const unsigned char palette_perrytileset_a[16]={ 0x1a,0x30,0x0f,0x00,0x1a,0x21,0x11,0x30,0x1a,0x38,0x17,0x07,0x1a,0x17,0x2a,0x0f };

//Nintendo Levels (Levels 15 and Level 17)
const unsigned char palette_perrytilesetnintendocolors_a[16]={ 0x1a,0x10,0x0f,0x00,0x1a,0x15,0x10,0x30,0x1a,0x38,0x17,0x07,0x1a,0x17,0x2a,0x0f };

//Perrygetout (cutscene) Pallette:
const unsigned char palette_perrytilesetcutscenecolors_a[16]={ 
  0x21,0x30,0x0f,0x00,
0x21,0x0f,0x30,0x00, //old 0x21,0x0f,0x20,0x00,
0x21,0x38,0x17,0x07,
0x21,0x17,0x2a,0x1a };

//Title Screen Pallette:
const unsigned char title_bg_palette[16]={ 0x0f,0x30,0x1a,0x15,0x0f,0x21,0x11,0x1a,0x0f,0x38,0x17,0x07,0x0f,0x17,0x2a,0x1a };


// sprite palette
const unsigned char palette_perrypuzzlesprites_a[16]={ 
  0x1a,0x30,0x0f,0x15,
  0x1a,0x11,0x21,0x30,
  0x1a,0x38,0x17,0x07,
  0x1a,0x0f,0x2d,0x3d };


#define COL_ALL 1
#define GOAL_FLAG 2

const unsigned char metatile_colision_map[] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL,
		0, 0, 0, 0, 0, 0, COL_ALL, COL_ALL, 0, 0, 0, GOAL_FLAG, COL_ALL, 0, COL_ALL, COL_ALL,
		COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, 0, 0, 0, 0, 0, 0, COL_ALL,
		0, 0, 0, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, COL_ALL, 0, COL_ALL, COL_ALL, COL_ALL, COL_ALL, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, COL_ALL, 0, 0, 0, COL_ALL, 0, 0, 0,
		0, 0, COL_ALL, COL_ALL, 0, COL_ALL, 0, COL_ALL, COL_ALL, 0, 0, 0, 0, 0, 0, 0,
		COL_ALL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		COL_ALL, COL_ALL, COL_ALL, COL_ALL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		COL_ALL, COL_ALL, COL_ALL, COL_ALL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
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
void process_powerpad(void);
void movement_user_direction(void);
void movement_user_forward(void);
void init_mode_game(void);
void init_mode_introcutscene(void);
void intro_cutscene_one(void);
void intro_cutscene_two(void);
