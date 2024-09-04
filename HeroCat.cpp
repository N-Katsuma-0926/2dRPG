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

//îLÇÃãNìÆéûÇÃèâä˙âªèàóù
bool CatSysInitProc(void) {

	CatImage = LoadGraph("Image2/HeroCat.png");
	if (CatImage == -1) return -1;

	return true;
}

//îLÇÃèâä˙èÓïÒ
void CatInitProc(void) {
	CatPosX = WINDOW_SIZE_WID / 3;
	CatPosY = WINDOW_SIZE_HIG / 2;
	CatFlg = true;
}

void CatMoveProc(void) {
	if (CatFlg) {
		//îLÇÃà⁄ìÆ
		//âE
		if (CheckHitKey(KEY_INPUT_D) == 1) {
			CatPosX += CAT_MOVE_SPEED;
		}
		//ç∂
		if (CheckHitKey(KEY_INPUT_A) == 1) {
			CatPosX -= CAT_MOVE_SPEED;
		}
		//è„
		if (CheckHitKey(KEY_INPUT_W) == 1) {
			CatPosY -= CAT_MOVE_SPEED;
		}
		//â∫
		if (CheckHitKey(KEY_INPUT_S) == 1) {
			CatPosY += CAT_MOVE_SPEED;
		}

		//îLÇÃà⁄ìÆêßå¿

		//âEí[
		if (CatPosX > WINDOW_SIZE_WID - CAT_SIZE_WID - 32)CatPosX = WINDOW_SIZE_WID - CAT_SIZE_WID - 32;
		//ç∂í[
		if (CatPosX < 32)CatPosX = 32;
		//è„í[
		if (CatPosY > WINDOW_SIZE_HIG - CAT_SIZE_HIG - 32)CatPosY = WINDOW_SIZE_HIG - CAT_SIZE_HIG - 32;
		//â∫í[
		if (CatPosY < 32) CatPosY = 32;

	}

}

void CatDraw(void) {
	if (CatFlg == true) {
		DrawGraph(CatPosX, CatPosY, CatImage, true);
	}
	
}
