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
		LoadDivGraph("Image2/GreenMap.png", 9, 3, 3, 32, 32, GlassMap); //�}�b�v�ǂݍ���
		LoadDivGraph("Image2/SoilMap.png", 14, 4, 4, 32, 32, SoilMap);	//�y�}�b�v�̓ǂݍ���
		LoadDivGraph("Image2/TranceMap.png", 9, 3, 3, 32, 32, TranceMap);//���F�}�b�v�̓ǂݍ���

		
	};

private:

};

PICTURE Picture;