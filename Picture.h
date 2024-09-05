#pragma once
/* Picture.h */
class PICTURE
{
public:
	int GlassMap[42];
	int SoilMap[42];
	int TranceMap[9];

	

	void Load()
	{
		LoadDivGraph("Image2/GlassMap.png", 42, 6, 7, 32, 32, GlassMap); //マップ読み込み
		LoadDivGraph("Image2/SoilMap.png", 42, 6, 7, 32, 32, SoilMap);	//土マップの読み込み
		LoadDivGraph("Image2/TranceMap.png", 9, 3, 3, 32, 32, TranceMap);//無色マップの読み込み

		
	};

private:

};

PICTURE Picture;