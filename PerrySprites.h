const unsigned char _perrystandright_data[]={

	  7,- 6,0x40,0,
	  0,- 8,0x50,1,
	  8,- 8,0x51,1,
	  0,  0,0x60,1,

	  8,  0,0x61,1,
	0x80

};

const unsigned char _perrystandleft_data[]={

	  1,- 6,0x40,0|OAM_FLIP_H,
	  8,- 8,0x50,1|OAM_FLIP_H,
	  0,- 8,0x51,1|OAM_FLIP_H,
	  8,  0,0x60,1|OAM_FLIP_H,

	  0,  0,0x61,1|OAM_FLIP_H,
	0x80

};

const unsigned char _perrywalkright0_data[]={

	  7,- 6,0x40,0,
	  0,- 8,0x50,1,
	  8,- 8,0x51,1,
	  0,  0,0x66,1,

	  8,  0,0x67,1,
	0x80

};

const unsigned char _perrywalkright1_data[]={

	  7,- 6,0x40,0,
	  0,- 8,0x50,1,
	  8,- 8,0x51,1,
	  0,  0,0x62,1,

	  8,  0,0x63,1,
	0x80

};

const unsigned char _perrywalkright2_data[]={

	  7,- 6,0x40,0,
	  0,- 8,0x50,1,
	  8,- 8,0x51,1,
	  0,  0,0x64,1,

	  8,  0,0x65,1,
	0x80

};

const unsigned char _perrywalkleft0_data[]={

	  1,- 6,0x40,0|OAM_FLIP_H,
	  8,- 8,0x50,1|OAM_FLIP_H,
	  0,- 8,0x51,1|OAM_FLIP_H,
	  8,  0,0x66,1|OAM_FLIP_H,

	  0,  0,0x67,1|OAM_FLIP_H,
	0x80

};

const unsigned char _perrywalkleft1_data[]={

	  1,- 6,0x40,0|OAM_FLIP_H,
	  8,- 8,0x50,1|OAM_FLIP_H,
	  0,- 8,0x51,1|OAM_FLIP_H,
	  8,  0,0x62,1|OAM_FLIP_H,

	  0,  0,0x63,1|OAM_FLIP_H,
	0x80

};

const unsigned char _perrywalkleft2_data[]={

	  1,- 6,0x40,0|OAM_FLIP_H,
	  8,- 8,0x50,1|OAM_FLIP_H,
	  0,- 8,0x51,1|OAM_FLIP_H,
	  8,  0,0x64,1|OAM_FLIP_H,

	  0,  0,0x65,1|OAM_FLIP_H,
	0x80

};

const unsigned char _perrywalkdown0_data[]={

	  2,- 6,0x41,0,
	  0,- 8,0x72,1,
	  8,- 8,0x73,1,
	  0,  0,0x82,1,

	  8,  0,0x83,1,
	0x80

};

const unsigned char _perrywalkdown1_data[]={

	  2,- 6,0x41,0,
	  0,- 8,0x70,1,
	  8,- 8,0x71,1,
	  0,  0,0x80,1,

	  8,  0,0x81,1,
	0x80

};

const unsigned char _perrywalkdown2_data[]={

	  2,- 6,0x41,0,
	  0,- 8,0x74,1,
	  8,- 8,0x75,1,
	  0,  0,0x84,1,

	  8,  0,0x85,1,
	0x80

};

const unsigned char _perrywalkup0_data[]={

	  0,- 8,0x92,1,
	  8,- 8,0x93,1,
	  0,  0,0xa2,1,
	  8,  0,0xa3,1,
	0x80

};

const unsigned char _perrywalkup1_data[]={

	  0,- 8,0x90,1,
	  8,- 8,0x91,1,
	  0,  0,0xa0,1,
	  8,  0,0xa1,1,
	0x80

};

const unsigned char _perrywalkup2_data[]={

	  0,- 8,0x94,1,
	  8,- 8,0x95,1,
	  0,  0,0xa4,1,
	  8,  0,0xa5,1,
	0x80

};

const unsigned char* const _list[]={

	_perrystandright_data,
	_perrystandleft_data,
	_perrywalright0_data,
	_perrywalkright1_data,
	_perrywalkright2_data,
	_perrywalkleft0_data,
	_perrywalkleft1_data,
	_perrywalkleft2_data,
	_perrywalkdown0_data,
	_perrywalkdown1_data,
	_perrywalkdown2_data,
	_perrywalkup0_data,
	_perrywalkup1_data,
	_perrywalkup2_data

};

