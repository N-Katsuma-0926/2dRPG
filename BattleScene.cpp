#include<DxLib.h>
#include<time.h>
#include<string.h>

#include"BattleStage.h"

//ボス
int B_RatPosX;
int B_RatPosY;
int B_RatImage;
bool B_RatFlg;

//背景
int B_HaikeiPosX;
int B_HaikeiPosY;
int B_HaikeiImage;
bool B_HaikeiFlg = true;

//肉球
int nikukyuPosX;
int nikukyuPosY;
int nikukyuImage;
bool nikukyuFlg;

//バトル
int Battle_anim_frame;


//キーの押下状態


bool B_RatSysInitProc(void)
{
	B_HaikeiImage = LoadGraph("Image2/B_Haikei.png");
	if (B_HaikeiImage == -1)
	{
		return -1;
	}


	B_RatImage = LoadGraph("Image2/B_Rat.png");
	if (B_RatImage == -1)
	{
		return -1;
	}

	nikukyuImage = LoadGraph("Image2/NikukyuW.png");
	if (nikukyuImage == -1)
	{
		return -1;
	}


	return true;

}



void B_RatInitProc(void)
{
	//背景
	B_HaikeiPosX = 0;
	B_HaikeiPosY = 0;
	B_HaikeiFlg = true;



	//ボス
	B_RatPosX = 180;
	B_RatPosY = 30;
	B_RatFlg = true;



}


void B_RatDraw(void)
{
	if (B_HaikeiFlg)
	{
		DrawGraph(B_HaikeiPosX, B_HaikeiPosY, B_HaikeiImage, true);

	}

	if (B_RatFlg)
	{
		DrawGraph(B_RatPosX, B_RatPosY, B_RatImage, true);

	}	
}

void B_RatView(void)
{
	SetDrawBlendMode(DX_BLENDMODE_SUB, 150);	//表示画像の明るさの減算
	DrawBox(0, B_ALL_WINDOW_HIG / 2, B_ALL_WINDOW_WID, B_ALL_WINDOW_HIG, 0xffffff, true);	//コマンド&会話タブ
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);	//表示画像の明るさの減算をクリア

	if (Battle_anim_frame < 200) 
	{
		DrawString(100, 450, "悪いネズミめ！！この街の草原を返せ！", GetColor(0, 0, 0), true);


		Battle_anim_frame++;
	}
	else
	{
		DrawString(100, B_ALL_WINDOW_HIG - 200, "ねこパンチ", 0x000000);
		DrawString(100, B_ALL_WINDOW_HIG - 150, "シャー（威嚇）", 0x000000);
		DrawString(100, B_ALL_WINDOW_HIG - 100, "噛む", 0x000000);
		DrawString(100, B_ALL_WINDOW_HIG - 50, "ひっかく", 0x000000);

		DrawGraph(60, B_ALL_WINDOW_HIG - 200, nikukyuImage, true);


	}
}


























