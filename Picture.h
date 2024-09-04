#pragma once
/* Picture.h */
class PICTURE
{
public:
	int GlassMap[9];
	int SoilMap[14];
	int TranceMap[9];

	

	void Load()
	{
		LoadDivGraph("Image2/GreenMap.png", 9, 3, 3, 32, 32, GlassMap); //マップ読み込み
		LoadDivGraph("Image2/SoilMap.png", 14, 4, 4, 32, 32, SoilMap);	//土マップの読み込み
		LoadDivGraph("Image2/TranceMap.png", 9, 3, 3, 32, 32, TranceMap);//無色マップの読み込み

		
	};

private:

};

PICTURE Picture;