#pragma once

const int CAT_SIZE_WID = 32;
const int CAT_SIZE_HIG = 32;
const int CAT_MOVE_SPEED = 2;

//公開する変数
extern int CatPosX;
extern int CatPosY;
extern int CatImage;
extern bool CatFlg;


//プロトタイプ宣言
bool CatSysInitProc(void);
void CatInitProc(void);
void CatMoveProc(void);
void CatDraw(void);