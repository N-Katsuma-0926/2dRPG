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






//���J�ϐ�

//�{�X
extern int B_RatPosX;
extern int B_RatPosY;
extern int B_RatImage;
extern bool B_RatFlg;



//�v���g�^�C�v�錾
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

//�{�X
int B_RatPosX;
int B_RatPosY;
int B_RatImage;
bool B_RatFlg;

int RatHp;
int RatAttack;
bool RatAttackFlg;
bool EnemyTurnFlg;

//�L�����
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


//�w�i
int B_HaikeiPosX;
int B_HaikeiPosY;
int B_HaikeiImage;
bool B_HaikeiFlg = true;

//����
int nikukyuPosX;
int nikukyuPosY;
int nikukyuImage;
bool nikukyuFlg;


//�o�g��
int Battle_anim_frame;
int command_index;
int ButtleTurn;

int BattleMessageProc;
int AttacPattern;

int BPunchProc;
int BBiteProc;
int BScratchProc;
int BFoodProc;
int BTulleProc;
int InBattlePframe;
int InBattleBframe;
int InBattleSframe;
int InBattleFframe;
int InBattleTframe;



//�L�[�̉������
int nowUpKey;
int prevUpKey;

int nowDownKey;
int prevDownKey;

int nowSpaceKey;
int prevSpaceKey;




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


//������
void B_RatInitProc(void)
{
	//�w�i
	B_HaikeiPosX = 0;
	B_HaikeiPosY = 0;
	B_HaikeiFlg = true;

	//�{�X
	B_RatPosX = 360;
	B_RatPosY = 30;
	B_RatFlg = true;

	RatHp = 20;
	RatAttack = 2;

	RatAttackFlg = false;
	EnemyTurnFlg = false;

	//�L�����
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


	//����
	nikukyuPosX = 10;
	nikukyuPosY = B_ALL_WINDOW_HIG - 280;
	nikukyuFlg = true;
	command_index = 0;

	ButtleTurn = 0;

	//�L�[�̏��
	nowUpKey = prevUpKey = 0;
	nowDownKey = prevDownKey = 0;
	nowReturnKey = prevReturnKey = 0;
	nowSpaceKey = prevSpaceKey = 0;

	//�o�g�����̃��b�Z�[�W
	BattleMessageProc = 0;
	BPunchProc = 0;
	BBiteProc = 0;
	BScratchProc = 0;
	BFoodProc = 0;
	BTulleProc = 0;

	AttacPattern = 0;
	InBattlePframe = 0;
	InBattleBframe = 0;
	InBattleSframe = 0;
	InBattleFframe = 0;
	InBattleTframe = 0;




}

void B_RatUpdateProc(void)
{
	prevUpKey = nowUpKey;
	nowUpKey = CheckHitKey(KEY_INPUT_UP);

	prevDownKey = nowDownKey;
	nowDownKey = CheckHitKey(KEY_INPUT_DOWN);

	prevReturnKey = nowReturnKey;
	nowReturnKey = CheckHitKey(KEY_INPUT_RETURN);

	prevSpaceKey = nowSpaceKey;
	nowSpaceKey = CheckHitKey(KEY_INPUT_SPACE);

	if (RatAttackFlg == false) {
		InBattlePframe = 0;
		InBattleBframe = 0;
		InBattleSframe = 0;
		InBattleFframe = 0;
		InBattleTframe = 0;
	}
	


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
	//�o�g���V�[���ڍ�
	SetDrawBlendMode(DX_BLENDMODE_SUB, 150);	//�\���摜�̖��邳�̌��Z
	DrawBox(0, B_ALL_WINDOW_HIG / 2, B_ALL_WINDOW_WID, B_ALL_WINDOW_HIG, 0xffffff, true);	//�R�}���h&��b�^�u
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);	//�\���摜�̖��邳�̌��Z���N���A



	static int command_index = 0;
	if (Battle_anim_frame < 200)
	{
		DrawString(100, 450, "�����l�Y�~�߁I�I���̊X�̑�����Ԃ��I", GetColor(255, 255, 255), true);


		Battle_anim_frame++;
	}
	else
	{
		DrawString(50, B_ALL_WINDOW_HIG - 270, "�˂��p���`", 0xffffff);
		DrawString(50, B_ALL_WINDOW_HIG - 240, "����", 0xffffff);
		DrawString(50, B_ALL_WINDOW_HIG - 210, "�Ђ�����", 0xffffff);
		DrawString(50, B_ALL_WINDOW_HIG - 180, "�J���J��", 0xffffff);
		DrawString(50, B_ALL_WINDOW_HIG - 150, "����[��", 0xffffff);


		DrawLine(0, B_ALL_WINDOW_HIG - 300, B_ALL_WINDOW_WID, B_ALL_WINDOW_HIG - 300, 0xffffff, true);







		//�R�}���h�I�����̃|�C���^�̈ړ�����

		if (nikukyuFlg == true)
		{
			DrawGraph(nikukyuPosX, nikukyuPosY + command_index * 30, nikukyuImage, true);


			if (nowDownKey == 1 && prevDownKey == 0)
			{
				command_index++;

				if (command_index > 4)
				{
					command_index = 0;
				}
			}
			if (nowUpKey == 1 && prevUpKey == 0)
			{
				command_index--;

				if (command_index < 0)
				{
					command_index = 4;
				}
			}

			

			if (command_index == 0)
			{
				BattleMessageProc = 0;
				DrawFormatString(200, B_ALL_WINDOW_HIG - 270, 0xffffff, "�{�X�l�Y�~��%d�̃_���[�W��^����", CatPunchDam);
			}
			else if (command_index == 1)
			{
				BattleMessageProc = 1;
				DrawFormatString(200, B_ALL_WINDOW_HIG - 240, 0xffffff, "�{�X�l�Y�~��%d�̃_���[�W��^����", CatBiteDam);
			}
			else if (command_index == 2)
			{
				BattleMessageProc = 2;
				DrawFormatString(200, B_ALL_WINDOW_HIG - 210, 0xffffff, "�{�X�l�Y�~��%d�̃_���[�W��^����", CatScratchDam);
			}
			else if (command_index == 3)
			{
				BattleMessageProc = 3;
				DrawFormatString(200, B_ALL_WINDOW_HIG - 180, 0xffffff, "�L���b�g�t�[�h(�J���J��)��H�ׂĎ��g�̗̑͂�%d��", CatFoodRec);
			}
			else if (command_index == 4)
			{
				BattleMessageProc = 4;
				DrawFormatString(200, B_ALL_WINDOW_HIG - 150, 0xffffff, "�`���[����H�ׂĎ��g�̗̑͂�%d��", CatTulleRec);
			}

			switch (BattleMessageProc) {
				case 0://�L�p���`
					if (command_index == 0 && nowReturnKey == 1 && prevReturnKey == 0)
					{
						CatPunchFlg = true;
						if (CatPunchFlg)
						{
							RatHp -= CatPunchDam;
						}
						CatPunchFlg = false;
						RatAttackFlg = true;
						AttacPattern = 1;
					}
										
					break;
					 
				case 1://���݂�
					if (command_index == 1 && nowReturnKey == 1 && prevReturnKey == 0)
					{
						CatBiteFlg = true;
						if (CatBiteFlg)
						{
							RatHp -= CatBiteDam;
						}
						CatBiteFlg = false;
						RatAttackFlg = true;
						AttacPattern = 2;
					}
					
					break;

				case 2://�Ђ�����
					if (command_index == 2 && nowReturnKey == 1 && prevReturnKey == 0)
					{
						CatScratchFlg = true;
						if (CatScratchFlg)
						{
							RatHp -= CatScratchDam;
						}
						CatScratchFlg = false;
						RatAttackFlg = true;
						AttacPattern = 3;
					}
					
					break;

				case 3://�J���J��
					if (command_index == 3 && nowReturnKey == 1 && prevReturnKey == 0)
					{
						CatFoodFlg = true;
						if (CatFoodFlg)
						{
							CatHp += CatFoodRec;
						}
						CatFoodFlg = false;
						RatAttackFlg = true;
						AttacPattern = 4;
					}
					
					break;

				case 4://�`���[��
					if (command_index == 4 && nowReturnKey == 1 && prevReturnKey == 0)
					{
						CatTulleFlg = true;
						if (CatTulleFlg)
						{
							CatHp += CatTulleRec;
						}
						CatTulleFlg = false;
						RatAttackFlg = true;
						AttacPattern = 5;
					}
					
					break;
			}
			
			if (RatAttackFlg == true)
			{
				
				switch (AttacPattern) {
				case 1:
					
					DrawString(100, B_ALL_WINDOW_HIG - 320, "�E�ҔL�̔L�p���`�I�I", 0xffffff);
					DrawFormatString(300, B_ALL_WINDOW_HIG - 320, 0xffffff, "�{�X��%d�^�����I�I", CatPunchDam);
					InBattlePframe == 0;
					if (InBattlePframe <= 360) {

						DrawFormatString(100, B_ALL_WINDOW_HIG - 290, 0xffffff, "�{�X�̍U���ɂ����%d��������I�I", RatAttack);

						InBattlePframe++;
					}
					else
					{
						CatHp -= RatAttack;
						RatAttackFlg = false;
					}
					break;


				case 2:
					DrawString(100, B_ALL_WINDOW_HIG - 320, "�E�ҔL�̊��݂��I�I", 0xffffff);
					DrawFormatString(300, B_ALL_WINDOW_HIG - 320, 0xffffff, "�{�X��%d�^�����I�I", CatBiteDam);
					InBattleBframe == 0;
					if (InBattleBframe <= 360) {

						DrawFormatString(100, B_ALL_WINDOW_HIG - 290, 0xffffff, "�{�X�̍U���ɂ����%d��������I�I", RatAttack);

						InBattleBframe++;
					}
					else
					{
						CatHp -= RatAttack;
						RatAttackFlg = false;
					}
					
					break;
				case 3:
					DrawString(100, B_ALL_WINDOW_HIG - 320, "�E�ҔL�̂Ђ������I�I", 0xffffff);
					DrawFormatString(300, B_ALL_WINDOW_HIG - 320, 0xffffff, "�{�X��%d�^�����I�I", CatScratchDam);
					InBattleSframe == 0;
					if (InBattleSframe <= 360) {

						DrawFormatString(100, B_ALL_WINDOW_HIG - 290, 0xffffff, "�{�X�̍U���ɂ����%d��������I�I", RatAttack);

						InBattleSframe++;
					}
					else
					{
						CatHp -= RatAttack;
						RatAttackFlg = false;
					}
					break;
				case 4:
					DrawString(100, B_ALL_WINDOW_HIG - 320, "�E�ҔL�̓J���J����H�ׂ��I�I", 0xffffff);
					DrawFormatString(300, B_ALL_WINDOW_HIG - 320, 0xffffff, "�̗͂�%d�񕜂����I�I", CatFoodRec);
					InBattleFframe == 0;
					if (InBattleFframe <= 360) {

						DrawFormatString(100, B_ALL_WINDOW_HIG - 290, 0xffffff, "�{�X�̍U���ɂ����%d��������I�I", RatAttack);

						InBattleFframe++;
					}
					else
					{
						CatHp -= RatAttack;
						RatAttackFlg = false;
					}
					break;
				case 5:
					DrawString(100, B_ALL_WINDOW_HIG - 320, "�E�ҔL�̓`���[����H�ׂ��I�I", 0xffffff);
					DrawFormatString(400, B_ALL_WINDOW_HIG - 320, 0xffffff, "�̗͂�%d�񕜂����I�I", CatTulleRec);
					InBattleTframe == 0;
					if (InBattleTframe <= 360) {

						DrawFormatString(100, B_ALL_WINDOW_HIG - 290, 0xffffff, "�{�X�̍U���ɂ����%d��������I�I", RatAttack);

						InBattleTframe++;
					}
					else
					{
						CatHp -= RatAttack;
						RatAttackFlg = false;
					}
					break;

				}
			}

		

		}














		DrawFormatString(0, 0, 0xffffff, "�{�X�̗̑́F%d", RatHp);
		DrawFormatString(50, B_ALL_WINDOW_HIG - 90, 0xffffff, "�̗́F%d", CatHp);
	}


	if (RatHp <= 0)
	{

		B_RatFlg = false;
		DrawBox(0, B_ALL_WINDOW_HIG / 2, B_ALL_WINDOW_WID, B_ALL_WINDOW_HIG, 0xffffff, true);
		DrawString(100, B_ALL_WINDOW_HIG - 160, "�{�X�l�Y�~��|�����I���ɗ΂����ǂ����I�I", 0x000000);
		if (CheckHitKey(KEY_INPUT_SPACE) == 1) {
			Scene = COURCE::GLASSMAP;
		}
	}



}

void B_RatView(void)
{


























}









































