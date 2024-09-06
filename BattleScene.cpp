#include<DxLib.h>
#include<time.h>
#include<string.h>

#include"BattleStage.h"

//�{�X
int B_RatPosX;
int B_RatPosY;
int B_RatImage;
bool B_RatFlg;

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


//�L�[�̉������


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
	//�w�i
	B_HaikeiPosX = 0;
	B_HaikeiPosY = 0;
	B_HaikeiFlg = true;



	//�{�X
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
	SetDrawBlendMode(DX_BLENDMODE_SUB, 150);	//�\���摜�̖��邳�̌��Z
	DrawBox(0, B_ALL_WINDOW_HIG / 2, B_ALL_WINDOW_WID, B_ALL_WINDOW_HIG, 0xffffff, true);	//�R�}���h&��b�^�u
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);	//�\���摜�̖��邳�̌��Z���N���A

	if (Battle_anim_frame < 200) 
	{
		DrawString(100, 450, "�����l�Y�~�߁I�I���̊X�̑�����Ԃ��I", GetColor(0, 0, 0), true);


		Battle_anim_frame++;
	}
	else
	{
		DrawString(100, B_ALL_WINDOW_HIG - 200, "�˂��p���`", 0x000000);
		DrawString(100, B_ALL_WINDOW_HIG - 150, "�V���[�i�Њd�j", 0x000000);
		DrawString(100, B_ALL_WINDOW_HIG - 100, "����", 0x000000);
		DrawString(100, B_ALL_WINDOW_HIG - 50, "�Ђ�����", 0x000000);

		DrawGraph(60, B_ALL_WINDOW_HIG - 200, nikukyuImage, true);


	}
}


























