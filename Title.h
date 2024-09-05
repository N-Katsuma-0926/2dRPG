#pragma once
#include<DxLib.h>


class TITLE
{
public:

	void Draw()
	{
		DrawFormatStringToHandle(200, 340, Color.WHITE, Font.c[50], "2D\nRPG");
		//DrawFormatStringToHandle(120, 300, Color.BLUE, Font.c[50], "2D\nRPG");

		DrawFormatStringToHandle(200, 152, Color.RED,  Font.c[16], "Press Enter to Start");
		//DrawFormatStringToHandle(180, 150, Color.WHITE, Font.c[16], "Press Enter to Start");

		if (CheckHitKey(KEY_INPUT_SPACE) == 1)
		{
			Scene = COURCE::SOILMAP;
		}
	}
private:
};

TITLE Title;