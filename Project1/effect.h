// ----------------
// effect.h
//  2019.10.01  by Nakagami
// ----------------
// #pragma once

// �ꎞ��~�����p
extern bool pauseFlag;				// ��ێ���~�@�\�p(true ; �ꎞ��~��)
extern int testCnt;
// �t�F�[�h�����p
extern bool fadeIn;					// �t�F�[�h�C��
extern bool fadeOut;				// �t�F�[�h�A�E�g

// �������ߐ錾
//---------------------
void EffectInit(void);					// �G�t�F�N�g�p����������

// �V�[���J�ڊ֐�
bool FadeInScreen(int fadeStep);		// �t�F�[�h�C���p
bool FadeOutScreen(int fadeStep);		// �t�F�[�h�A�E�g�p
