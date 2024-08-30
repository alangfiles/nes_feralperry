
enum
{
	MODE_TITLE,
	MODE_GAME,
	MODE_PAUSE,
	MODE_SWITCH,
	MODE_END,
	MODE_LEVEL_TITLE,
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

	const unsigned char metatiles[]={
	0, 0, 0, 0,  1,
	30, 30, 31, 30,  3,
	30, 0, 0, 0,  3,
	0, 30, 0, 0,  3,
	0, 0, 30, 0,  3,
	0, 0, 0, 30,  3,
	31, 0, 0, 0,  3,
	0, 0, 31, 0,  3,
	0, 31, 0, 0,  3,
	0, 0, 0, 31,  3,
	30, 0, 0, 31,  3,
	0, 0, 0, 0,  0,
	14, 14, 14, 14,  3,
	15, 15, 15, 15,  3,
	14, 14, 0, 14,  3,
	14, 14, 14, 0,  3,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  3,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 28,  0,
	0, 29, 0, 0,  0,
	0, 0, 14, 0,  3,
	0, 0, 0, 15,  3,
	0, 15, 15, 15,  3,
	14, 0, 14, 14,  3,
	0, 0, 0, 0,  0,
	141, 157, 0, 0,  3,
	156, 141, 0, 0,  3,
	0, 0, 124, 125,  3,
	0, 0, 125, 126,  3,
	157, 0, 156, 0,  3,
	0, 141, 0, 126,  3,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	28, 0, 0, 0,  2,
	0, 0, 0, 29,  2,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	164, 165, 180, 181,  2,
	166, 167, 182, 183,  2,
	168, 169, 184, 185,  2,
	200, 201, 216, 217,  2,
	196, 197, 212, 213,  2,
	198, 199, 214, 215,  2,
	228, 229, 244, 245,  2,
	230, 231, 246, 247,  2,
	232, 233, 248, 249,  2,
	142, 143, 158, 159,  3,
	158, 159, 142, 143,  3,
	172, 173, 188, 189,  3,
	132, 133, 148, 149,  2,
	134, 135, 150, 151,  2,
	136, 137, 152, 153,  2,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	226, 227, 242, 243,  0,
	0, 0, 16, 18,  2,
	0, 0, 18, 17,  2,
	0, 0, 18, 18,  2,
	174, 175, 190, 191,  0,
	194, 195, 210, 211,  3,
	192, 193, 208, 209,  2,
	138, 139, 154, 155,  2,
	140, 0, 140, 0,  2,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 171, 0, 171,  2,
	204, 205, 220, 238,  2,
	206, 206, 238, 238,  2,
	207, 205, 238, 221,  2,
	204, 206, 220, 2,  1,
	207, 206, 222, 223,  1,
	207, 205, 222, 255,  1,
	220, 221, 254, 255,  1,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  2,
	0, 0, 0, 0,  2,
	0, 0, 0, 0,  2,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  1,
	220, 238, 236, 238,  2,
	238, 238, 238, 238,  2,
	238, 237, 238, 221,  2,
	236, 221, 254, 237,  1,
	0, 0, 0, 0,  0,
	220, 237, 220, 221,  1,
	254, 237, 236, 221,  1,
	0, 0, 0, 0,  3,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  2,
	0, 0, 0, 0,  2,
	0, 0, 0, 0,  2,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  0,
	220, 238, 252, 222,  2,
	238, 238, 223, 222,  2,
	238, 221, 223, 253,  2,
	236, 221, 252, 222,  1,
	239, 207, 223, 222,  1,
	239, 237, 222, 253,  1,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  2,
	0, 0, 0, 0,  2,
	0, 0, 0, 0,  2,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	2, 2, 2, 2,  0,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  0,
	0, 0, 0, 4,  1,
	0, 0, 18, 18,  1,
	0, 0, 5, 0,  1,
	0, 0, 4, 18,  1,
	0, 0, 17, 0,  1,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  0,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  1,
	0, 0, 0, 0,  1,
	4, 20, 22, 20,  1,
	0, 0, 7, 7,  0,
	20, 5, 20, 22,  1,
	20, 0, 20, 0,  1,
	0, 0, 18, 5,  1,
	24, 21, 6, 5,  1,
	0, 0, 23, 0,  1,
	0, 0, 0, 23,  1,
	0, 45, 0, 0,  0,
	80, 82, 0, 0,  0,
	69, 83, 0, 0,  0,
	83, 0, 0, 0,  0,
	0, 83, 0, 0,  0,
	84, 65, 0, 0,  0,
	82, 84, 0, 0,  0,
	45, 0, 0, 0,  0,
	0, 20, 0, 19,  1,
	250, 0, 18, 26,  1,
	20, 0, 21, 0,  1,
	19, 18, 20, 0,  1,
	17, 0, 0, 0,  1,
	0, 19, 0, 20,  1,
	18, 24, 0, 6,  1,
	21, 0, 5, 0,  1,
	6, 18, 0, 0,  1,
	0, 0, 80, 85,  0,
	0, 0, 90, 90,  0,
	0, 0, 76, 69,  0,
	0, 0, 0, 81,  0,
	0, 0, 85, 69,  0,
	0, 0, 83, 84,  0,
	0, 0, 39, 0,  0,
	0, 20, 0, 22,  1,
	8, 0, 0, 0,  0,
	20, 0, 6, 18,  1,
	20, 0, 22, 0,  1,
	0, 20, 0, 20,  1,
	20, 0, 20, 0,  1,
	10, 0, 6, 18,  1,
	0, 20, 18, 21,  1,
	18, 25, 0, 20,  1,
	0, 0, 70, 101,  0,
	0, 0, 82, 97,  0,
	0, 0, 76, 0,  0,
	127, 0, 0, 0,  0,
	65, 108, 66, 114,  0,
	97, 110, 105, 97,  0,
	0, 38, 110, 0,  0};




// PROTOTYPES
void draw_bg(void);
void draw_sprites(void);
void movement(void);	
void bg_collision(void);
void check_start(void);
void sprite_collision(void);
void level_up(void);
void init_level_text(void);
void set_direction(void);
void draw_player_sprite(void);
void init_mode_title(void);
void title_cutscene(void);