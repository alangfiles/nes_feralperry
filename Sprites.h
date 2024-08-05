// a 16x16 pixel metasprite

const unsigned char YellowSpr[]={
	  0,  0,0x00,0,
	  8,  0,0x00,0|OAM_FLIP_H,
	  0,  8,0x10,0,
	  8,  8,0x10,0|OAM_FLIP_H,
	128
};


const unsigned char BlueSpr[]={
	  0,  0,0x00,1,
	  8,  0,0x00,1|OAM_FLIP_H,
	  0,  8,0x10,1,
	  8,  8,0x10,1|OAM_FLIP_H,
	128
};

const unsigned char GoalFlag[]={
	  0,  0,0x02,0,
	  8,  0,0x03,0,
	  0,  8,0x12,0,  
	  8,  8,0x13,0,
	128
};




