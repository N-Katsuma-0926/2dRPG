#pragma once
#include<DxLib.h>


int EndPosX;
int EndPosY;
int EndImage;
bool EndFlg;

void EndSysInit(void)
{
	EndPosX = 130;
	EndPosY = 0;
	EndImage = LoadGraph("Image2/End.png");

}

void EndUpdate(void)
{
	EndPosX = 130;
	EndPosY += 5;
	if (EndPosY <= 245)
	{
		EndPosY = 245;
	}

}


void EndDraw(void)
{
	if (EndFlg)
	{
		DrawGraph(EndPosX, EndPosY, EndImage, true);
	}
}

