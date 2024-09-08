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
int command_index;


//�L�[�̉������
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

	//����
	nikukyuPosX = 160;
	nikukyuPosY = B_ALL_WINDOW_HIG - 240;
	nikukyuFlg = true;
	command_index = 0;

	//�L�[�̏��
	//nowUpKey = prevUpKey = 0;
	//nowDownKey = prevDownKey = 0;

}


void B_RatUpdateProc(void)
{
	//�L�[�̎擾���
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


	

	//�o�g���V�[���ڍ�
	SetDrawBlendMode(DX_BLENDMODE_SUB, 150);	//�\���摜�̖��邳�̌��Z
	DrawBox(0, B_ALL_WINDOW_HIG / 2, B_ALL_WINDOW_WID, B_ALL_WINDOW_HIG, 0xffffff, true);	//�R�}���h&��b�^�u
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);	//�\���摜�̖��邳�̌��Z���N���A

	if (Battle_anim_frame < 200) 
	{
		DrawString(100, 450, "�����l�Y�~�߁I�I���̊X�̑�����Ԃ��I", GetColor(255, 255, 255), true);


		Battle_anim_frame++;
	}
	else
	{
		DrawString(200, B_ALL_WINDOW_HIG - 240, "�˂��p���`", 0xffffff);
		DrawString(200, B_ALL_WINDOW_HIG - 180, "�V���[�i�Њd�j", 0xffffff);
		DrawString(200, B_ALL_WINDOW_HIG - 120, "����", 0xffffff);
		DrawString(200, B_ALL_WINDOW_HIG - 60, "�Ђ�����", 0xffffff);

		DrawLine(0, B_ALL_WINDOW_HIG - 300, B_ALL_WINDOW_WID, B_ALL_WINDOW_HIG - 300, 0xffffff, true);
		
		

		

		

		//�R�}���h�I�����̃|�C���^�̈ړ�����
		
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


























