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
extern int B_RatPosX;
extern int B_RatPosY;
extern int B_RatImage;
extern bool B_RatFlg;



//プロトタイプ宣言
bool B_RatSysInitProc(void);
void B_RatInitProc(void);
void B_RatDraw(void);
void B_RatView(void);














