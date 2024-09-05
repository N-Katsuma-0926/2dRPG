#include<DxLib.h>
#include<time.h>
#include<string>


#include"BossRat.h"

#define WINDOW_SIZE_WID 960
#define WINDOW_SIZE_HIG 640

int RatPosX;
int RatPosY;
int RatImage;
bool RatFlg = false;

bool RatSysInitProc(void) {
	//âÊëúÇÃì«Ç›çûÇ›
	RatImage = LoadGraph("Image2/BossRat2.png");
		if (RatImage == -1)return -1;

		return true;

}


void RatInitProc(void) {
	RatPosX = WINDOW_SIZE_WID  - 114;
	RatPosY = WINDOW_SIZE_HIG / 2;
	RatFlg = true;



}






void RatDraw(void) {
	if (RatFlg) {
		DrawGraph(RatPosX, RatPosY, RatImage, true);
	}
	
}




