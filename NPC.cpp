#include<DxLib.h>
#include<time.h>
#include<string>

#include"HeroCat.h"
#include"NPC.h"
//#include"KeyStatus.h"
//#include"Sub.h"


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

//キーの押下状態
int nowReturnKey;
int prevReturnKey;

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

	//会話用吹き出し画像の読み込み
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

	nowReturnKey = prevReturnKey = 0;

	TalkProgress = 0;

}

void HumanUpdateProc(void)
{

	prevReturnKey = nowReturnKey;
	nowReturnKey = CheckHitKey(KEY_INPUT_RETURN);

	if (HumanPosX - 30 <= CatPosX && CatPosX + CAT_SIZE_WID <= HumanPosX + HUMAN_SIZE_WID + 30 && CatPosY <= HumanPosY + HUMAN_SIZE_HIG + 50 && CatPosY + CAT_SIZE_HIG >= HumanPosY + 50)
	{
		BubbleFlg = true; 
		BubblePosX = HumanPosX;
		BubblePosY = HumanPosY - 32;
		if (CheckHitKey(KEY_INPUT_SPACE) == 1) 
		{
			HumanTalkFlg = true;
		}
		
	}
	else
	{
		BubbleFlg = false;
		BubblePosX = BubblePosY = 0;
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
		DrawBox(30, WINDOW_SIZE_HIG - HUMAN_TALK_BOX_HIG , WINDOW_SIZE_WID - 30, WINDOW_SIZE_HIG -30, 0xffffff, true); //会話を表示するウィンドウの描画
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);	//表示画像の明るさの減算をクリア


		switch (TalkProgress)
		{
		case 0:
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			DrawString(128, WINDOW_SIZE_HIG - HUMAN_TALK_BOX_HIG / 3 * 2, "こんにちは", 0xffffff);
			if (nowReturnKey == 1 && prevReturnKey == 0) TalkProgress += 1;
			break;
		case 1:
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			DrawString(128, WINDOW_SIZE_HIG - HUMAN_TALK_BOX_HIG / 3 * 2, "勇者猫よ。。",0xffffff);
			if (nowReturnKey == 1 && prevReturnKey == 0) TalkProgress += 1;
			break;
		case 2:
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			DrawString(128, WINDOW_SIZE_HIG - HUMAN_TALK_BOX_HIG / 3 * 2, "この街を救ってくれないか？。。", 0xffffff);
			if (nowReturnKey == 1 && prevReturnKey == 0) TalkProgress += 1;
			break;
		case 3:
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			DrawString(128, WINDOW_SIZE_HIG - HUMAN_TALK_BOX_HIG / 3 * 2, "この村は町の東側に居るネズミによって", 0xffffff);
			if (nowReturnKey == 1 && prevReturnKey == 0) TalkProgress += 1;
			break;
		case 4:
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			DrawString(128, WINDOW_SIZE_HIG - HUMAN_TALK_BOX_HIG / 3 * 2, "草原の緑が奪われてしまったのだ。。", 0xffffff);
			if (nowReturnKey == 1 && prevReturnKey == 0) TalkProgress += 1;
			break;
		case 5:
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			DrawString(128, WINDOW_SIZE_HIG - HUMAN_TALK_BOX_HIG / 3 * 2, "やつを倒してこの街の草原を取り戻してくれ！", 0xffffff);
			if (nowReturnKey == 1 && prevReturnKey == 0) TalkProgress += 1;
			break;
		case 6:SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			DrawString(128, WINDOW_SIZE_HIG - HUMAN_TALK_BOX_HIG / 3 * 2, "期待しているぞ！！", 0xffffff);
			if (nowReturnKey == 1 && prevReturnKey == 0)
			{
				TalkProgress = 0;
				HumanTalkFlg = false;


			}
			break;



		}











	}


}