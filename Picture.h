#pragma once
/* Picture.h */
class PICTURE
{
public:
	int Map[9];
	

	void Load()
	{
		LoadDivGraph("Image2/GreenMap.png", 9, 3, 3, 32, 32, Map); //マップ読み込み	
	};

private:

};

PICTURE Picture;