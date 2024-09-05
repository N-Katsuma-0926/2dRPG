#pragma once
//人間サイズ
const int HUMAN_SIZE_WID = 32;
const int HUMAN_SIZE_HIG = 32;
//吹き出しサイズ
const int BUBBLE_SIZE_WID = 32;
const int BUBBLE_SIZE_HIG = 32;



//会話ウィンドウ
const int HUMAN_TALK_BOX_WID = 900;
const int HUMAN_TALK_BOX_HIG = 128;

//公開変数
extern int HumanPosX;
extern int HumanPosY;
extern int HumanImage;
extern bool HumanFlg;
extern bool HumanTalkFlg;
//extern bool HumantalkWindowFlg;

//プロトタイプ宣言
bool HumanSysInitProc(void);
void HumanInitProc(void);
void HumanDraw();
void HumanUpdateProc(void);




