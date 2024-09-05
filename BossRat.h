#pragma once



const int RAT_SIZE_WID = 50;
const int RAT_SIZE_HIG = 50;


//公開する変数
extern int RatPosX;
extern int RatPosY;
extern int RatImage;
extern bool RatFlg;


//プロトタイプ宣言
bool RatSysInitProc(void);
void RatInitProc(void);
void RatDraw(void);





