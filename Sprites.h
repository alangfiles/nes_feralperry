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

const unsigned char titletailwag0_data[]={

	  0,  0,0x15,1,
	0x80

};

const unsigned char titletailwag1_data[]={

	  0,  0,0x17,1,
	0x80

};

const unsigned char titletailwag2_data[]={

	  0,  0,0x16,1,
	0x80

};

const unsigned char GoalFlag[]={
	  0,  0,0x02,0,
	  8,  0,0x03,0,
	  0,  8,0x12,0,  
	  8,  8,0x13,0,
	128
};
