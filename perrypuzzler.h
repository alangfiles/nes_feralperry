
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

unsigned char local_left;
unsigned char local_right;
unsigned char local_up;
unsigned char local_down;
const unsigned char * pointer2;

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

const unsigned char * const Level_List[] = {Level1_0,Level2_0,Level3_0,Level4_0};

const unsigned char * const level_text[] = {
	"Easy Peasy",
	"Not so simple",
	"90 Degrees",
	"Two Player Game"
};

//cant dynamically calcualte this somehow
const unsigned char level_text_length[] = {
	11,
	13,
	11,
	16,
};


const unsigned char level_player_x[] = {
	64,
	60,
	120,
	120,
};

const unsigned char level_player_y[] = {
	60,
	60,
	120,
	120,
};


const unsigned char level_goal_x[] = {
	180,
	225,
	180,
	180,
};

const unsigned char level_goal_y[] = {
	160,
	30,
	160,
	160,
};




const unsigned char palette_perrypuzzlesprites_a[16]={ 0x1a,0x30,0x0f,0x15,0x1a,0x11,0x21,0x20,0x1a,0x38,0x17,0x07,0x1a,0x0f,0x2d,0x3d };
const unsigned char palette_perrytileset_a[16]={ 0x1a,0x30,0x0f,0x15,0x1a,0x21,0x11,0x30,0x1a,0x38,0x17,0x07,0x1a,0x17,0x2a,0x0f };
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
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
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