#pragma once



const int RAT_SIZE_WID = 50;
const int RAT_SIZE_HIG = 50;


//���J����ϐ�
extern int RatPosX;
extern int RatPosY;
extern int RatImage;
extern bool RatFlg;


//�v���g�^�C�v�錾
bool RatSysInitProc(void);
void RatInitProc(void);
void RatDraw(void);





