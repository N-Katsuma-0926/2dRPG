#pragma once

const int B_ALL_WINDOW_WID = 960;
const int B_ALL_WINDOW_HIG = 640;

const int B_WINDOW_WID = 300;
const int B_WINDOW_HIG = 300;

const int B_RAT_WID = 240;
const int B_RAT_HIG = 240;
const int RAT_HP = 10;

const int NIKUKYU_WID = 30;
const int NIKUKYU_HIG = 30;






//公開変数

//ボス
extern int B_RatPosX;
extern int B_RatPosY;
extern int B_RatImage;
extern bool B_RatFlg;



//プロトタイプ宣言
bool B_RatSysInitProc(void);
void B_RatInitProc(void);
void B_RatUpdateProc(void);
void B_RatDraw(void);
void B_RatView(void);



#include<DxLib.h>
#include<time.h>
#include<string.h>

#include"BattleStage.h"
#include"NPC.h"

//ボス
int B_RatPosX;
int B_RatPosY;
int B_RatImage;
bool B_RatFlg;

int RatHp;
int RatAttack;
bool RatAttackFlg;

//猫ちゃん
int CatHp;
int CatPunchDam;
bool CatPunchFlg;
int CatBiteDam;
bool CatBiteFlg;
int CatScratchDam;
bool CatScratchFlg;
int CatFoodRec;
bool CatFoodFlg;
int CatTulleRec;
bool CatTulleFlg;
int CatIntimidation;
bool CatIntimidationFlg;


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
int ButtleTurn;

int ButtleMessageProc;


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

	nikukyuImage = LoadGraph("Image2/Nikukyu_H.png");
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

	RatHp = 20;
	RatAttack = 2;

	//猫ちゃん
	CatHp = 10;
	CatPunchDam = 2;
	CatPunchFlg = false;
	CatBiteDam = 3;
	CatBiteFlg = false;
	CatScratchDam = 4;
	CatScratchFlg = false;
	CatFoodRec = 2;
	CatFoodFlg = false;
	CatTulleRec = 5;
	CatTulleFlg = false;
	CatIntimidation = 0;
	CatIntimidationFlg = false;


	//肉球
	nikukyuPosX = 10;
	nikukyuPosY = B_ALL_WINDOW_HIG - 280;
	nikukyuFlg = true;
	command_index = 0;

	ButtleTurn = 0;

	//キーの状態
	nowUpKey = prevUpKey = 0;
	nowDownKey = prevDownKey = 0;
	nowReturnKey = prevReturnKey = 0;

	//バトル中のメッセージ
	ButtleMessageProc = 0;
}

void B_RatUpdateProc(void)
{
	prevUpKey = nowUpKey;
	nowUpKey = CheckHitKey(KEY_INPUT_UP);

	prevDownKey = nowDownKey;
	nowDownKey = CheckHitKey(KEY_INPUT_DOWN);

	prevReturnKey = nowReturnKey;
	nowReturnKey = CheckHitKey(KEY_INPUT_RETURN);




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
	//バトルシーン詳細
	SetDrawBlendMode(DX_BLENDMODE_SUB, 150);	//表示画像の明るさの減算
	DrawBox(0, B_ALL_WINDOW_HIG / 2, B_ALL_WINDOW_WID, B_ALL_WINDOW_HIG, 0xffffff, true);	//コマンド&会話タブ
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);	//表示画像の明るさの減算をクリア



	static int command_index = 0;
	if (Battle_anim_frame < 200)
	{
		DrawString(100, 450, "悪いネズミめ！！この街の草原を返せ！", GetColor(255, 255, 255), true);


		Battle_anim_frame++;
	}
	else
	{
		DrawString(50, B_ALL_WINDOW_HIG - 270, "ねこパンチ", 0xffffff);
		DrawString(50, B_ALL_WINDOW_HIG - 240, "シャー（威嚇）", 0xffffff);
		DrawString(50, B_ALL_WINDOW_HIG - 210, "噛む", 0xffffff);
		DrawString(50, B_ALL_WINDOW_HIG - 180, "ひっかく", 0xffffff);
		DrawString(50, B_ALL_WINDOW_HIG - 150, "カリカリ", 0xffffff);
		DrawString(50, B_ALL_WINDOW_HIG - 120, "ちゅーる", 0xffffff);


		DrawLine(0, B_ALL_WINDOW_HIG - 300, B_ALL_WINDOW_WID, B_ALL_WINDOW_HIG - 300, 0xffffff, true);







		//コマンド選択時のポインタの移動処理

		if (nikukyuFlg == true)
		{
			DrawGraph(nikukyuPosX, nikukyuPosY + command_index * 30, nikukyuImage, true);


			if (nowDownKey == 1 && prevDownKey == 0)
			{
				command_index++;

				if (command_index > 5)
				{
					command_index = 0;
				}
			}
			if (nowUpKey == 1 && prevUpKey == 0)
			{
				command_index--;

				if (command_index < 0)
				{
					command_index = 5;
				}
			}



			if (command_index == 0)
			{
				ButtleMessageProc = 0;
			}
			else if (command_index == 2)
			{
				ButtleMessageProc = 1;
			}
			else if (command_index == 3)
			{
				ButtleMessageProc = 2;
			}
			else if (command_index == 4)
			{
				ButtleMessageProc = 3;
			}
			else if (command_index == 5)
			{
				ButtleMessageProc = 4;
			}

			if (command_index == 1 && nowReturnKey == 1 && prevReturnKey == 0)
			{
				CatIntimidationFlg;
			}



				switch (ButtleMessageProc) {
				case 0://猫パンチ
					if (command_index == 0 && nowReturnKey == 1 && prevReturnKey == 0)
					{
						CatPunchFlg = true;
						if (CatPunchFlg)
						{
							RatHp -= CatPunchDam;
						}
					}
					CatPunchFlg = false;
					break;

				case 1://噛みつく
					if (command_index == 2 && nowReturnKey == 1 && prevReturnKey == 0)
					{
						CatBiteFlg = true;
						if (CatBiteFlg)
						{
							RatHp -= CatBiteDam;
						}
					}
					CatBiteFlg = false;
					break;

				case 2://ひっかく
					if (command_index == 3 && nowReturnKey == 1 && prevReturnKey == 0)
					{
						CatScratchFlg = true;
						if (CatScratchFlg)
						{
							RatHp -= CatScratchDam;
						}
					}
					CatScratchFlg = false;
					break;

				case 3://カリカリ
					if (command_index == 4 && nowReturnKey == 1 && prevReturnKey == 0)
					{
						CatFoodFlg = true;
						if (CatFoodFlg)
						{
							CatHp += CatFoodRec;
						}
					}
					CatFoodFlg = false;
					break;

				case 4://チュール
					if (command_index == 5 && nowReturnKey == 1 && prevReturnKey == 0)
					{
						CatTulleFlg = true;
						if (CatTulleFlg)
						{
							CatHp += CatTulleRec;
						}
					}
					CatTulleFlg = false;
					break;
				}
			

		}

		DrawFormatString(0, 0, 0xffffff, "ボスの体力：%d", RatHp);
		DrawFormatString(50, B_ALL_WINDOW_HIG - 90, 0xffffff, "体力：%d", CatHp);
	}


	if (RatHp <= 0)
	{
		Scene = COURCE::GLASSMAP;
	}



}

void B_RatView(void)
{


























}









































