#pragma once
#include<DxLib.h>
#include"Scene.h"

int TitleImage;



class TITLE
{
public:
	void TitleInit(void)
	{
		TitleImage = LoadGraph("Image2/TitleHaikei.png");
	}






	void Draw()
	{
		DrawGraph(0, 0, TitleImage, true);


		DrawFormatStringToHandle(200, 160, Color.RED, Font.c[50], "2DÉjÉÉÅ[ÉãPG");
		//DrawFormatStringToHandle(120, 300, Color.BLUE, Font.c[50], "2D\nRPG");

		//DrawFormatStringToHandle(200, 152, Color.RED,  Font.c[16], "Press Enter to Start");
		//DrawFormatStringToHandle(180, 150, Color.WHITE, Font.c[16], "Press Enter to Start");

		if (CheckHitKey(KEY_INPUT_SPACE) == 1)
		{
			Scene = COURCE::SOILMAP;
		}
	}
private:
};

TITLE Title;