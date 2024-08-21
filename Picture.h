#pragma once
/* Picture.h */
class PICTURE
{
public:
	int Map[16];
	int Grace_River[4];
	int Grace_River2[4];
	int Fill_Grace[4];
	int Player[12];
	int Slime[2];
	int SlimeBeth[2];

	void Load()
	{
		LoadDivGraph("Picture/MapChip-2.png", 16, 4, 4, 16, 16, Map); //É}ÉbÉvì«Ç›çûÇ›
		LoadDivGraph("Picture/grass_near_river.png", 4, 2, 2, 16, 16, Grace_River);
		LoadDivGraph("Picture/grass_near_river2.png", 4, 2, 2, 16, 16, Grace_River2);
		LoadDivGraph("Picture/Fill_grass.png", 4, 2, 2, 16, 16, Fill_Grace);
		LoadDivGraph("Picture/Player.png", 12, 1, 12, 16, 16, Player);
		LoadDivGraph("Picture/Slime.png", 2, 2, 1, 16, 16, Slime);
		LoadDivGraph("Picture/SlimeBeth.png", 2, 2, 1, 16, 16, SlimeBeth);
	};

private:

};

PICTURE Picture;