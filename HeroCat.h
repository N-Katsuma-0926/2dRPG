#pragma once

const int CAT_SIZE_WID = 32;
const int CAT_SIZE_HIG = 32;
const int CAT_MOVE_SPEED = 2;

//���J����ϐ�
extern int CatPosX;
extern int CatPosY;
extern int CatImage;
extern bool CatFlg;


//�v���g�^�C�v�錾
bool CatSysInitProc(void);
void CatInitProc(void);
void CatMoveProc(void);
void CatDraw(void);