#pragma once
//�l�ԃT�C�Y
const int HUMAN_SIZE_WID = 32;
const int HUMAN_SIZE_HIG = 32;
//�����o���T�C�Y
const int BUBBLE_SIZE_WID = 32;
const int BUBBLE_SIZE_HIG = 32;



//��b�E�B���h�E
const int HUMAN_TALK_BOX_WID = 900;
const int HUMAN_TALK_BOX_HIG = 250;

//���J�ϐ�
extern int HumanPosX;
extern int HumanPosY;
extern int HumanImage;
extern bool HumanFlg;
extern bool HumanTalkFlg;
//�L�[�̏�Ԏ擾
extern int nowReturnKey;
extern int prevReturnKey;


//�v���g�^�C�v�錾
bool HumanSysInitProc(void);
void HumanInitProc(void);
void HumanDraw();
void HumanUpdateProc(void);




