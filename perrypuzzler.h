
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

unsigned char local_left;
unsigned char local_right;
unsigned char local_up;
unsigned char local_down;

#pragma bss-name(push, "BSS")

unsigned char c_map[240];
// collision map 


struct BoxGuy {
	unsigned char X;
	unsigned char Y;
	unsigned char width;
	unsigned char height;
};

struct BoxGuy BoxGuy1 = {64,80,15,14};








// these are the 4 backgrounds
// collision data, made by exporting csv from Tiled, and slight modification by CSV2C.py
#include "CSV/c1.c" // called c1
#include "CSV/c2.c" // called c2
#include "CSV/c3.c" // called c3
#include "CSV/c4.c" // called c4

const unsigned char * const All_Collision_Maps[] = {c1,c2,c3,c4};

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





const unsigned char palette_bg[]={
0x0f, 0x00, 0x10, 0x30, // black, gray, lt gray, white
0,0,0,0,
0,0,0,0,
0,0,0,0
}; 

const unsigned char palette_sp[]={
	0x28, 0x16, 0x13, 0x1c, // black, gray, lt gray, white
	0x30, 0x12, 0x0f, 0x28, // black, black, yellow
0,0,0,0,
0,0,0,0
}; 



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