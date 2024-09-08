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
int command_index;


//キーの押下状態
int nowUpKey;
int prevUpKey;

int nowDownKey;
int prevDownKey;



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


//初期化
void B_RatInitProc(void)
{
	//背景
	B_HaikeiPosX = 0;
	B_HaikeiPosY = 0;
	B_HaikeiFlg = true;

	//ボス
	B_RatPosX = 360;
	B_RatPosY = 30;
	B_RatFlg = true;

	//肉球
	nikukyuPosX = 160;
	nikukyuPosY = B_ALL_WINDOW_HIG - 240;
	nikukyuFlg = true;
	command_index = 0;

	//キーの状態
	//nowUpKey = prevUpKey = 0;
	//nowDownKey = prevDownKey = 0;

}


void B_RatUpdateProc(void)
{
	//キーの取得状態
	prevUpKey = nowUpKey;
	CheckHitKey(KEY_INPUT_UP);
	prevDownKey = nowDownKey;
	CheckHitKey(KEY_INPUT_DOWN);



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


	

	//バトルシーン詳細
	SetDrawBlendMode(DX_BLENDMODE_SUB, 150);	//表示画像の明るさの減算
	DrawBox(0, B_ALL_WINDOW_HIG / 2, B_ALL_WINDOW_WID, B_ALL_WINDOW_HIG, 0xffffff, true);	//コマンド&会話タブ
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);	//表示画像の明るさの減算をクリア

	if (Battle_anim_frame < 200) 
	{
		DrawString(100, 450, "悪いネズミめ！！この街の草原を返せ！", GetColor(255, 255, 255), true);


		Battle_anim_frame++;
	}
	else
	{
		DrawString(200, B_ALL_WINDOW_HIG - 240, "ねこパンチ", 0xffffff);
		DrawString(200, B_ALL_WINDOW_HIG - 180, "シャー（威嚇）", 0xffffff);
		DrawString(200, B_ALL_WINDOW_HIG - 120, "噛む", 0xffffff);
		DrawString(200, B_ALL_WINDOW_HIG - 60, "ひっかく", 0xffffff);

		DrawLine(0, B_ALL_WINDOW_HIG - 300, B_ALL_WINDOW_WID, B_ALL_WINDOW_HIG - 300, 0xffffff, true);
		
		

		

		

		//コマンド選択時のポインタの移動処理
		
		if (nikukyuFlg == true)
		{
			DrawGraph(nikukyuPosX, nikukyuPosY, nikukyuImage, true);
			if (nowUpKey == 1 && prevUpKey == 0)
			{
				nikukyuPosY -= 60;
			}
			
			if (nowDownKey == 1 && prevDownKey == 0)
			{
				nikukyuPosY += 60;
			}








		}






	}
}


























