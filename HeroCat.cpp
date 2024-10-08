#include<DxLib.h>
#include<time.h>
#include<string>

#include"HeroCat.h"

#define WINDOW_SIZE_WID 960
#define WINDOW_SIZE_HIG 640

int CatPosX;
int CatPosY;
int CatImage;
bool CatFlg = false;

//猫の起動時の初期化処理
bool CatSysInitProc(void) {

	CatImage = LoadGraph("Image2/HeroCat3.png");
	if (CatImage == -1) return -1;

	return true;
}

//猫の初期情報
void CatInitProc(void) {
	CatPosX = WINDOW_SIZE_WID / 3;
	CatPosY = WINDOW_SIZE_HIG / 2;
	CatFlg = true;
}

void CatMoveProc(void) {
	if (CatFlg) {
		//猫の移動
		//右
		if (CheckHitKey(KEY_INPUT_D) == 1) {
			CatPosX += CAT_MOVE_SPEED;
		}
		//左
		if (CheckHitKey(KEY_INPUT_A) == 1) {
			CatPosX -= CAT_MOVE_SPEED;
		}
		//上
		if (CheckHitKey(KEY_INPUT_W) == 1) {
			CatPosY -= CAT_MOVE_SPEED;
		}
		//下
		if (CheckHitKey(KEY_INPUT_S) == 1) {
			CatPosY += CAT_MOVE_SPEED;
		}

		//猫の移動制限

		//右端
		if (CatPosX > WINDOW_SIZE_WID - CAT_SIZE_WID - 32)CatPosX = WINDOW_SIZE_WID - CAT_SIZE_WID - 32;
		//左端
		if (CatPosX < 32)CatPosX = 32;
		//上端
		if (CatPosY > WINDOW_SIZE_HIG - CAT_SIZE_HIG - 32)CatPosY = WINDOW_SIZE_HIG - CAT_SIZE_HIG - 32;
		//下端
		if (CatPosY < 32) CatPosY = 32;

	}

}

void CatDraw(void) {
	if (CatFlg) {
		DrawGraph(CatPosX, CatPosY, CatImage, true);
	}
}

	
