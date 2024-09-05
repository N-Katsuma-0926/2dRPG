#include<DxLib.h>
#include<time.h>
#include<string.h>

#include"BattleStage.h"

int B_RatPosX;
int B_RatPosY;
int B_RatImage;
bool B_RatFlg;


bool B_RatSysInitProc(void)
{
	B_RatImage = LoadGraph("Image2/B_Rat.png");
	if (B_RatImage == -1)
	{
		return -1;
	}

	return true;

}



void B_RatInitProc(void)
{
	B_RatPosX = 180;
	B_RatPosY = 30;
	B_RatFlg = true;
}


void B_RatDraw(void)
{
	if (B_RatFlg)
	{
		DrawGraph(B_RatPosX, B_RatPosY, B_RatImage, true);
		DrawBox(0, B_WINDOW_HIG / 2, B_WINDOW_WID, B_WINDOW_HIG, 0xffffff, true);
	}
}



























