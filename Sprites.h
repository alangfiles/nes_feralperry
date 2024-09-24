const unsigned char perrystandright_data[]={

	  7,  2,0x30,0,
	  0,  0,0x40,1,
	  8,  0,0x41,1,
	  0,  8,0x50,1,

	  8,  8,0x51,1,
	0x80

};

const unsigned char perrystandleft_data[]={

	  1,  2,0x30,0|OAM_FLIP_H,
	  0,  0,0x41,1|OAM_FLIP_H,
	  8,  0,0x40,1|OAM_FLIP_H,
	  8,  8,0x50,1|OAM_FLIP_H,

	  0,  8,0x51,1|OAM_FLIP_H,
	0x80

};

const unsigned char perrywalkright0_data[]={

	  7,  2,0x30,0,
	  0,  0,0x40,1,
	  8,  0,0x41,1,
	  0,  8,0x54,1,

	  8,  8,0x55,1,
	0x80

};

const unsigned char perrywalkright1_data[]={

	  7,  2,0x30,0,
	  0,  0,0x40,1,
	  8,  0,0x41,1,
	  0,  8,0x52,1,

	  8,  8,0x53,1,
	0x80

};

const unsigned char perrywalkright2_data[]={

	  7,  2,0x30,0,
	  0,  0,0x40,1,
	  8,  0,0x41,1,
	  0,  8,0x56,1,

	  8,  8,0x57,1,
	0x80

};

const unsigned char perrywalkleft0_data[]={

	  1,  2,0x30,0|OAM_FLIP_H,
	  8,  0,0x40,1|OAM_FLIP_H,
	  0,  0,0x41,1|OAM_FLIP_H,
	  8,  8,0x54,1|OAM_FLIP_H,

	  0,  8,0x55,1|OAM_FLIP_H,
	0x80

};

const unsigned char perrywalkleft1_data[]={

	  1,  2,0x30,0|OAM_FLIP_H,
	  8,  0,0x40,1|OAM_FLIP_H,
	  0,  0,0x41,1|OAM_FLIP_H,
	  8,  8,0x52,1|OAM_FLIP_H,

	  0,  8,0x53,1|OAM_FLIP_H,
	0x80

};

const unsigned char perrywalkleft2_data[]={

	  1,  2,0x30,0|OAM_FLIP_H,
	  8,  0,0x40,1|OAM_FLIP_H,
	  0,  0,0x41,1|OAM_FLIP_H,
	  8,  8,0x56,1|OAM_FLIP_H,

	  0,  8,0x57,1|OAM_FLIP_H,
	0x80

};

const unsigned char perrywalkdown0_data[]={

	  2,  2,0x31,0,
	  0,  0,0x60,1,
	  8,  0,0x61,1,
	  0,  8,0x72,1,

	  8,  8,0x73,1,
	0x80

};

const unsigned char perrywalkdown1_data[]={

	  2,  2,0x31,0,
	  0,  0,0x60,1,
	  8,  0,0x61,1,
	  0,  8,0x70,1,

	  8,  8,0x71,1,
	0x80

};

const unsigned char perrywalkdown2_data[]={

	  2,  2,0x31,0,
	  0,  0,0x60,1,
	  8,  0,0x61,1,
	  0,  8,0x74,1,

	  8,  8,0x75,1,
	0x80

};

const unsigned char perrywalkup0_data[]={

	  0,  0,0x80,1,
	  8,  0,0x81,1,
	  0,  8,0x90,1,
	  8,  8,0x93,1,
	0x80

};

const unsigned char perrywalkup1_data[]={

	  0,  0,0x80,1,
	  8,  0,0x81,1,
	  0,  8,0x90,1,
	  8,  8,0x91,1,
	0x80

};

const unsigned char perrywalkup2_data[]={

	  0,  0,0x80,1,
	  8,  0,0x81,1,
	  0,  8,0x92,1,
	  8,  8,0x91,1,
	0x80

};

const unsigned char nudeman_data[]={

	  8,  0,0x0d,1,
	 16,  0,0x0e,1,
	 16,  0,0x0f,1,
	  8,  8,0x1d,1,

	 16,  8,0x1e,1,
	 16,  8,0x1f,1,
	 16, 16,0x2e,1,
	 24, 16,0x2f,1,

	 16, 24,0x3e,1,
	 16, 24,0x3f,1,
	 16, 32,0x4e,1,
	 24, 32,0x4f,1,

	 24, 24,0x3f,1,
	  8, 16,0x2d,1,
	  0, 16,0x2c,1,
	  0,  8,0x1c,1,

	  0,  0,0x0c,1,
	  8, 24,0x3d,1,
	  8, 32,0x4d,1,
	  8, 40,0x5d,1,

	 16, 40,0x5e,1,
	  8, 48,0x6d,1,
	 16, 48,0x6e,1,
	 24, 48,0x6f,1,

	 24, 56,0x7f,1,
	 16, 56,0x7e,1,
	  8, 56,0x7d,1,
	  0, 56,0x7c,1,

	  0, 48,0x6c,1,
	0x80

};

const unsigned char Duck_data[]={

	  8,  0,0xbd,1,
	 16,  0,0xbe,1,
	  8,  8,0xcd,1,
	 16,  8,0xce,1,

	 24,  8,0xcf,1,
	 24, 16,0xdf,1,
	 16, 16,0xde,1,
	  8, 16,0xdd,1,

	  0, 16,0xdc,1,
	  0,  8,0xcc,1,
	  0, 24,0xec,1,
	  8, 24,0xed,1,

	 16, 24,0xee,1,
	 24, 24,0xef,1,
	 24, 32,0xff,1,
	 16, 32,0xfe,1,

	  8, 32,0xfd,1,
	  0, 32,0xfc,1,
	0x80

};

const unsigned char switchleft_data[]={

	  0,  0,0xc0,0,
	  0,  8,0xd0,0,
	  8,  8,0xd1,0,
	0x80

};

const unsigned char switchright_data[]={

	  8,  0,0xc0,0|OAM_FLIP_H,
	  8,  8,0xd0,0|OAM_FLIP_H,
	  0,  8,0xd1,0|OAM_FLIP_H,
	0x80

};

const unsigned char lighton_data[]={

	  0,  0,0xa2,0,
	  8,  0,0xa3,0,
	  0,  8,0xb2,0,
	  8,  8,0xb3,0,
	0x80

};

const unsigned char lightoff_data[]={

	  0,  0,0xc2,0,
	  8,  0,0xc3,0,
	  0,  8,0xd2,0,
	  8,  8,0xd3,0,
	0x80

};

const unsigned char rock_data[]={

	  0,  0,0xe0,2,
	  8,  0,0xe1,2,
	  0,  8,0xf0,2,
	  8,  8,0xf1,2,
	0x80

};

const unsigned char perryflag0_data[]={

	  0,  0,0x04,0,
	0x80

};

const unsigned char perryflag1_data[]={

	  0,  0,0x05,0,
	0x80

};

const unsigned char perryflag2_data[]={

	  0,  0,0x06,0,
	0x80

};

const unsigned char blankflag0_data[]={

	  0,  0,0x07,0,
	0x80

};

const unsigned char blankflag1_data[]={

	  0,  0,0x08,0,
	0x80

};

const unsigned char blankflag2_data[]={

	  0,  0,0x09,0,
	0x80

};

const unsigned char flagpole_data[]={

	  3,  0,0x14,0,
	0x80

};

const unsigned char tailwag0_data[]={

	  0,  0,0x15,1,
	0x80

};

const unsigned char tailwag1_data[]={

	  0,  0,0x16,1,
	0x80

};

const unsigned char tailwag2_data[]={

	  0,  0,0x15,1|OAM_FLIP_H,
	0x80

};

const unsigned char tonguewag0_data[]={

	  0,  0,0x11,0,
	0x80

};

const unsigned char tonguewag1_data[]={

	  0,  0,0x12,0,
	0x80

};

const unsigned char tonguewag2_data[]={

	  0,  0,0x13,0,
	0x80

};

const unsigned char eyewag0_data[]={

	  0,  0,0x20,0,
	  8,  0,0x20,0,
	0x80

};

const unsigned char eyewag1_data[]={

	  0,  0,0x23,1,
	  8,  0,0x23,1,
	  0,  0,0x20,0,
	  8,  0,0x20,0,
	0x80

};

const unsigned char eyewag2_data[]={

	  0,  0,0x22,1,
	  8,  0,0x22,1,
	  0,  0,0x20,0,
	  8,  0,0x20,0,
	0x80

};

const unsigned char eyewag3_data[]={

	  0,  0,0x21,1,
	  8,  0,0x21,1,
	0x80

};

const unsigned char perryshrink0_data[]={

	  4,  2,0x32,1,
	  4, 10,0x42,1,
	0x80

};

const unsigned char perryshrink1_data[]={

	  6,  4,0x33,1,
	0x80

};

const unsigned char perryshrink2_data[]={

	  6,  4,0x34,1,
	0x80

};

const unsigned char floateyes0_data[]={

	- 1,  0,0x35,0,
	  0,  0,0x43,1,
	0x80

};

const unsigned char floateyes1_data[]={

	- 1,  0,0x35,0,
	  0,  0,0x44,1,
	0x80

};

const unsigned char floateyes2_data[]={

	- 1,  0,0x35,0,
	  0,  0,0x45,1,
	0x80

};

const unsigned char bigdoor0_data[]={

	  0,  0,0xa4,0,
	0x80

};

const unsigned char bigdoor1_data[]={

	- 1,- 6,0x94,0,
	  7,- 6,0x95,0,
	- 1,  2,0x02,0,
	  7,  2,0xa5,0,
	0x80

};

const unsigned char bigdoor2_data[]={

	- 4,- 4,0x96,0,
	  4,- 4,0x96,0|OAM_FLIP_H,
	- 2,  4,0x02,0,
	  2,  4,0x02,0,
	0x80

};

const unsigned char bigdoor3_data[]={

	- 4,  6,0x02,0,
	  4,  6,0x02,0,
	- 4,- 2,0x02,0,
	  4,- 2,0x02,0,

	- 4,-10,0xa6,0,
	  4,-10,0xa6,0|OAM_FLIP_H,
	0x80

};

const unsigned char bigdoor4_data[]={

	- 6,  8,0x02,0,
	  6,  8,0x02,0,
	- 6,  0,0x02,0,
	  6,  0,0x02,0,

	- 3,-12,0xa6,0,
	  4,-11,0x96,0|OAM_FLIP_H,
	  0,  8,0x02,0,
	  1,  0,0x02,0,

	- 7,-11,0x96,0,
	  7,-11,0x96,0|OAM_FLIP_H,
	  0,- 8,0x02,0,
	- 6,- 4,0x02,0,

	  6,- 4,0x02,0,
	- 2,-17,0x94,0,
	  6,-12,0xa5,0,
	  8,-17,0x95,0,
	0x80

};

const unsigned char bigdoor5_data[]={

	- 8, 10,0x02,0,
	  8, 10,0x02,0,
	- 8,  2,0x02,0,
	  8,  2,0x02,0,

	  0, 10,0x02,0,
	  0,  2,0x02,0,
	  0,- 4,0x02,0,
	- 8,- 4,0x02,0,

	  8,- 4,0x02,0,
	- 1,-11,0x02,0,
	- 9,-12,0x96,0,
	  9,-12,0x96,0|OAM_FLIP_H,

	  3,-11,0x02,0,
	- 5,-16,0xa6,0,
	  5,-16,0xa6,0|OAM_FLIP_H,
	  0,-14,0x02,0,
	0x80

};

const unsigned char bigdoor6_data[]={

	-10, 12,0x02,0,
	 10, 12,0x02,0,
	-10,  4,0x02,0,
	 10,  4,0x02,0,

	- 3, 12,0x02,0,
	  3,- 4,0x02,0,
	- 3,  4,0x02,0,
	- 2,- 4,0x02,0,

	-10,- 4,0x02,0,
	  4,-12,0x02,0,
	 10,- 4,0x02,0,
	 11,-12,0x96,0|OAM_FLIP_H,

	- 3,-12,0x02,0,
	-11,-12,0x96,0,
	- 9,-16,0x96,0,
	  9,-16,0x96,0|OAM_FLIP_H,

	- 2,-16,0x02,0,
	  3, 12,0x02,0,
	  4,  4,0x02,0,
	  2,-16,0x02,0,
	0x80

};

const unsigned char bigdoor7_data[]={

	-12, 14,0x02,0,
	 12, 14,0x02,0,
	-12,  6,0x02,0,
	 12,  6,0x02,0,

	- 4, 14,0x02,0,
	- 4,  6,0x02,0,
	- 4,- 2,0x02,0,
	-12,- 2,0x02,0,

	 12,- 2,0x02,0,
	  4,- 2,0x02,0,
	 11,- 6,0x02,0,
	- 9,-18,0x96,0,

	  9,-18,0x96,0|OAM_FLIP_H,
	- 2,-18,0x02,0,
	 12,-14,0x96,0|OAM_FLIP_H,
	  4, 14,0x02,0,

	  4,  6,0x02,0,
	-11,- 6,0x02,0,
	  2,-18,0x02,0,
	-12,-14,0x96,0,

	- 4,-10,0x02,0,
	  4,-10,0x02,0,
	0x80

};

const unsigned char gamepad_data[]={

	  0,  0,0xf4,3,
	  8,  0,0xf9,0,
	  8,  0,0xf5,3,
	0x80

};

const unsigned char advantage_data[]={

	  7,  0,0xf8,0,
	  0,  0,0xf6,3,
	  8,  0,0xf7,3,
	  8,- 8,0xe7,3,

	  0,- 8,0xe6,3,
	0x80

};

const unsigned char powerpad_data[]={

	  1,  6,0xe5,0,
	  8,  6,0xe5,0,
	  0,  0,0xd4,3,
	  8,  0,0xd4,3|OAM_FLIP_H,

	  0,  8,0xe4,3,
	  8,  8,0xe4,3|OAM_FLIP_H,
	0x80

};

const unsigned char zapper_data[]={

	  8,  0,0xf2,0,
	  0,  0,0xe2,3,
	  8,  0,0xe3,3,
	  8,  8,0xf3,3,
	0x80

};

const unsigned char arrowdown0_data[]={

	  0,  8,0x19,0|OAM_FLIP_V,
	  0,  0,0x2a,0|OAM_FLIP_V,
	  8,  8,0x19,0|OAM_FLIP_H|OAM_FLIP_V,
	  8,  0,0x2a,0|OAM_FLIP_H|OAM_FLIP_V,

	  0,  8,0x28,0,
	  8,  8,0x28,0|OAM_FLIP_H,
	0x80

};

const unsigned char arrowdown1_data[]={

	  0,  9,0x19,0|OAM_FLIP_V,
	  0,  1,0x2a,0|OAM_FLIP_V,
	  8,  9,0x19,0|OAM_FLIP_H|OAM_FLIP_V,
	  8,  1,0x2a,0|OAM_FLIP_H|OAM_FLIP_V,

	  0,  8,0x28,0,
	  8,  8,0x28,0|OAM_FLIP_H,
	0x80

};

const unsigned char arrowup0_data[]={

	  0,  0,0x19,0,
	  0,  8,0x29,0,
	  8,  0,0x19,0|OAM_FLIP_H,
	  8,  8,0x29,0|OAM_FLIP_H,
	0x80

};

const unsigned char arrowup1_data[]={

	  0,  1,0x19,0,
	  0,  8,0x2a,0,
	  8,  1,0x19,0|OAM_FLIP_H,
	  8,  8,0x2a,0|OAM_FLIP_H,
	0x80

};

const unsigned char arrowright0_data[]={

	  8,  8,0x19,0|OAM_FLIP_H|OAM_FLIP_V,
	  8,  0,0x19,0|OAM_FLIP_H,
	  0,  9,0x18,0|OAM_FLIP_H,
	  0,  1,0x17,0|OAM_FLIP_H|OAM_FLIP_V,

	  8,  8,0x28,0|OAM_FLIP_H,
	0x80

};

const unsigned char arrowright1_data[]={

	  8,  9,0x19,0|OAM_FLIP_H|OAM_FLIP_V,
	  8,  1,0x19,0|OAM_FLIP_H,
	  0,  9,0x17,0|OAM_FLIP_H,
	  0,  2,0x17,0|OAM_FLIP_H|OAM_FLIP_V,
	0x80

};

const unsigned char arrowleft_data[]={

	  0,  8,0x19,0|OAM_FLIP_V,
	  0,  0,0x19,0,
	  8,  8,0x18,0,
	  8,  0,0x17,0|OAM_FLIP_V,

	  0,  8,0x28,0,
	0x80

};

const unsigned char arrowleft1_data[]={

	  0,  9,0x19,0|OAM_FLIP_V,
	  0,  1,0x19,0,
	  8,  9,0x17,0,
	  8,  1,0x17,0|OAM_FLIP_V,
	0x80

};

const unsigned char button0_data[]={

	  0,  0,0x0a,0,
	  8,  0,0x0a,0|OAM_FLIP_H,
	  0,  8,0x1a,0,
	  8,  8,0x1a,0|OAM_FLIP_H,
	0x80

};

const unsigned char button1_data[]={

	  0,  2,0x0a,0,
	  8,  2,0x0a,0|OAM_FLIP_H,
	  0,  8,0x0a,0|OAM_FLIP_V,
	  8,  8,0x0a,0|OAM_FLIP_H|OAM_FLIP_V,
	0x80

};

const unsigned char widebutton0_data[]={

	  4,  2,0x18,0|OAM_FLIP_H,
	- 1,  2,0x18,0|OAM_FLIP_H,
	  0,  1,0x17,0,
	  5,  1,0x17,0,
	0x80

};

const unsigned char widebutton0__1_data[]={

	  0,  2,0x17,0,
	  5,  2,0x17,0,
	0x80

};

const unsigned char mower0_data[]={

	  0,  8,0x46,0,
	  8,  8,0x47,0,
	  8,  0,0x37,0,
	0x80

};

const unsigned char mower1_data[]={

	  0,  8,0x48,0,
	  8,  8,0x49,0,
	  7,  0,0x37,0,
	0x80

};

const unsigned char Metasprite55_data[]={

	  2,  6,0x9d,1,
	  0,  0,0x8e,0,
	  8,  0,0x8f,0,
	  0,  8,0x9e,0,

	  8,  8,0x9f,0,
	  0, 16,0xae,0,
	  8, 16,0xaf,0,
	0x80

};

const unsigned char Metasprite55__1_data[]={

	  2,  6,0x9d,1,
	  0,  0,0x8e,0,
	  8,  0,0x8f,0,
	  0,  8,0x9e,0,

	  8,  8,0x9f,0,
	  0, 16,0xac,0,
	  8, 16,0xad,0,
	0x80

};
