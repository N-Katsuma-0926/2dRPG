#include<DxLib.h>
#include<time.h>
#include<string>

#include"HeroCat.h"

#define WINDOW_SIZE_WID 960
#define WINDOW_SIZE_HIG 640

int CatPosX;
int CatPosY;
int CatImage;
bool CatFlg;

//�L�̋N�����̏���������
bool CatSysInitProc(void) {

	CatImage = LoadGraph("Image2/HeroCat.png");
	if (CatImage == -1) return -1;

	return true;
}

//�L�̏������
void CatInitProc(void) {
	CatPosX = WINDOW_SIZE_WID / 3;
	CatPosY = WINDOW_SIZE_HIG / 2;
	CatFlg = true;
}

void CatMoveProc(void) {
	if (CatFlg) {
		//�L�̈ړ�
		//�E
		if (CheckHitKey(KEY_INPUT_D) == 1) {
			CatPosX += CAT_MOVE_SPEED;
		}
		//��
		if (CheckHitKey(KEY_INPUT_A) == 1) {
			CatPosX -= CAT_MOVE_SPEED;
		}
		//��
		if (CheckHitKey(KEY_INPUT_W) == 1) {
			CatPosY -= CAT_MOVE_SPEED;
		}
		//��
		if (CheckHitKey(KEY_INPUT_S) == 1) {
			CatPosY += CAT_MOVE_SPEED;
		}

		//�L�̈ړ�����

		//�E�[
		if (CatPosX > WINDOW_SIZE_WID - CAT_SIZE_WID - 32)CatPosX = WINDOW_SIZE_WID - CAT_SIZE_WID - 32;
		//���[
		if (CatPosX < 32)CatPosX = 32;
		//��[
		if (CatPosY > WINDOW_SIZE_HIG - CAT_SIZE_HIG - 32)CatPosY = WINDOW_SIZE_HIG - CAT_SIZE_HIG - 32;
		//���[
		if (CatPosY < 32) CatPosY = 32;

	}

}

void CatDraw(void) {
	if (CatFlg == true) {
		DrawGraph(CatPosX, CatPosY, CatImage, true);
	}
	
}
