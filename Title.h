#pragma once
#include<DxLib.h>


class TITLE
{
public:

	void Draw()
	{
		DrawFormatStringToHandle(22, 34, Color.WHITE, Font.c[50], "2D\nRPG");
		DrawFormatStringToHandle(18, 30, Color.BLUE, Font.c[50], "2D\nRPG");

		DrawFormatStringToHandle(20, 152, Color.RED,  Font.c[16], "Press Enter to Start");
		DrawFormatStringToHandle(18, 150, Color.WHITE, Font.c[16], "Press Enter to Start");

		if (CheckHitKey(KEY_INPUT_RETURN) == 1)
		{
			Scene = COURCE::WORLD;
		}
	}
private:
};

TITLE Title;