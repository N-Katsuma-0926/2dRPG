#include<DxLib.h>
#include<time.h>
#include<string>

#include"HeroCat.h"
#include"NPC.h"

#define WINDOW_SIZE_WID 960
#define WINDOW_SIZE_HIG 640

//人間
int HumanPosX;
int HumanPosY;
int HumanImage;
bool HumanFlg = false;
bool HumanTalkFlg = false;

//人間の会話用吹き出し
int BubblePosX;
int BubblePosY;
int BubbleImage;
bool BubbleFlg;

//会話の進行度
int TalkProgress;


bool HumanSysInitProc(void)
{
	//人間画像の読み込み
	HumanImage = LoadGraph("Image2/Human.png");
	if (HumanImage == -1)
	{ 
		return -1; 
	}

	BubbleImage = LoadGraph("Image2/Talk.png");
	if (BubbleImage == -1)
	{
		return -1;
	}


		return true;

}


void HumanInitProc(void)
{
	HumanPosX = 128;
	HumanPosY = 96;
	HumanFlg = true;
	HumanTalkFlg = false;


	BubblePosX = BubblePosY = 0;
	BubbleFlg = false;






}

void HumanUpdateProc(void)
{
	if (HumanPosX - 30 <= CatPosX && CatPosX + CAT_SIZE_WID <= HumanPosX + HUMAN_SIZE_WID + 30 && CatPosY <= HumanPosY + HUMAN_SIZE_HIG + 50 && CatPosY + CAT_SIZE_HIG >= HumanPosY)
	{
		BubbleFlg = true; 
		BubblePosX = HumanPosX;
		BubblePosY = HumanPosY - 32;
		if (CheckHitKey(KEY_INPUT_SPACE) == 1) 
		{
			HumanTalkFlg = true;
		}
		else 
		{
			BubbleFlg = false;
		}
	}
}





void HumanDraw(void) 
{
	//人間の描画
	if (HumanFlg) 
	{
		DrawGraph(HumanPosX, HumanPosY, HumanImage, true);
	}
	//吹き出しの描画
	if (BubbleFlg == true)
	{
		DrawGraph(BubblePosX, BubblePosY, BubbleImage, true);
	}

	//人間と猫の会話描画
	if (HumanTalkFlg == true)
	{
		SetDrawBlendMode(DX_BLENDMODE_SUB, 150);	//表示画像の明るさの減算
		DrawBox(30, WINDOW_SIZE_HIG / 4, WINDOW_SIZE_WID - 30, WINDOW_SIZE_HIG - 30, 0xffffff, true);

		switch (TalkProgress)
		{
		case 0:
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			DrawString(128, WINDOW_SIZE_HIG - HUMAN_TALK_BOX_HIG / 3 * 2, "こんにちは", 0x000000);
			if (CheckHitKey(KEY_INPUT_SPACE) == 1)TalkProgress += 1;
		}











	}


}