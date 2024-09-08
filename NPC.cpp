#include<DxLib.h>
#include<time.h>
#include<string>

#include"HeroCat.h"
#include"NPC.h"
//#include"KeyStatus.h"
//#include"Sub.h"


#define WINDOW_SIZE_WID 960
#define WINDOW_SIZE_HIG 640

//�l��
int HumanPosX;
int HumanPosY;
int HumanImage;
bool HumanFlg = false;
bool HumanTalkFlg = false;

//�l�Ԃ̉�b�p�����o��
int BubblePosX;
int BubblePosY;
int BubbleImage;
bool BubbleFlg;

//�L�[�̉������
int nowReturnKey;
int prevReturnKey;

//��b�̐i�s�x
int TalkProgress;


bool HumanSysInitProc(void)
{
	//�l�ԉ摜�̓ǂݍ���
	HumanImage = LoadGraph("Image2/Human.png");
	if (HumanImage == -1)
	{ 
		return -1; 
	}

	//��b�p�����o���摜�̓ǂݍ���
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
	//�l�Ԃ̕`��
	if (HumanFlg) 
	{
		DrawGraph(HumanPosX, HumanPosY, HumanImage, true);
	}
	//�����o���̕`��
	if (BubbleFlg == true)
	{
		DrawGraph(BubblePosX, BubblePosY, BubbleImage, true);
	}

	//�l�ԂƔL�̉�b�`��
	if (HumanTalkFlg == true)
	{
		SetDrawBlendMode(DX_BLENDMODE_SUB, 150);	//�\���摜�̖��邳�̌��Z
		DrawBox(30, WINDOW_SIZE_HIG - HUMAN_TALK_BOX_HIG , WINDOW_SIZE_WID - 30, WINDOW_SIZE_HIG -30, 0xffffff, true); //��b��\������E�B���h�E�̕`��
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);	//�\���摜�̖��邳�̌��Z���N���A


		switch (TalkProgress)
		{
		case 0:
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			DrawString(128, WINDOW_SIZE_HIG - HUMAN_TALK_BOX_HIG / 3 * 2, "����ɂ���", 0xffffff);
			if (nowReturnKey == 1 && prevReturnKey == 0) TalkProgress += 1;
			break;
		case 1:
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			DrawString(128, WINDOW_SIZE_HIG - HUMAN_TALK_BOX_HIG / 3 * 2, "�E�ҔL��B�B",0xffffff);
			if (nowReturnKey == 1 && prevReturnKey == 0) TalkProgress += 1;
			break;
		case 2:
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			DrawString(128, WINDOW_SIZE_HIG - HUMAN_TALK_BOX_HIG / 3 * 2, "���̊X���~���Ă���Ȃ����H�B�B", 0xffffff);
			if (nowReturnKey == 1 && prevReturnKey == 0) TalkProgress += 1;
			break;
		case 3:
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			DrawString(128, WINDOW_SIZE_HIG - HUMAN_TALK_BOX_HIG / 3 * 2, "���̑��͒��̓����ɋ���l�Y�~�ɂ����", 0xffffff);
			if (nowReturnKey == 1 && prevReturnKey == 0) TalkProgress += 1;
			break;
		case 4:
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			DrawString(128, WINDOW_SIZE_HIG - HUMAN_TALK_BOX_HIG / 3 * 2, "�����̗΂��D���Ă��܂����̂��B�B", 0xffffff);
			if (nowReturnKey == 1 && prevReturnKey == 0) TalkProgress += 1;
			break;
		case 5:
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			DrawString(128, WINDOW_SIZE_HIG - HUMAN_TALK_BOX_HIG / 3 * 2, "���|���Ă��̊X�̑��������߂��Ă���I", 0xffffff);
			if (nowReturnKey == 1 && prevReturnKey == 0) TalkProgress += 1;
			break;
		case 6:SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			DrawString(128, WINDOW_SIZE_HIG - HUMAN_TALK_BOX_HIG / 3 * 2, "���҂��Ă��邼�I�I", 0xffffff);
			if (nowReturnKey == 1 && prevReturnKey == 0)
			{
				TalkProgress = 0;
				HumanTalkFlg = false;


			}
			break;



		}











	}


}