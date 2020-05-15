// ----------------
// effect.cpp
//  2019.10.01  by Nakagami
// ----------------

#include "DxLib.h"		//DxLibײ���؂��g�p����
#include "effect.h"

// �ꎞ��~�����p
bool pauseFlag;				// ��ێ���~�@�\�p(true ; �ꎞ��~��)
int testCnt;
// �t�F�[�h�����p
bool fadeIn;				// �t�F�[�h�C��
bool fadeOut;				// �t�F�[�h�A�E�g
int fadeCnt;				// �t�F�[�h�J�E���^

// �G�t�F�N�g�p����������
void EffectInit(void)
{
	// �ꎞ��~�����p
	pauseFlag = false;
	// �t�F�[�h�Ǘ��p
	fadeIn = true;
	fadeOut = false;
	fadeCnt = 0;
}

// �V�[���J�ڊ֐�
// �t�F�[�h�C���p
bool FadeInScreen(int fadeStep)
{
	if (fadeCnt < 255)
	{
		SetDrawBright(fadeCnt, fadeCnt, fadeCnt);
		fadeCnt += fadeStep;
		return true;
	}
	else
	{
		SetDrawBright(255, 255, 255);
		fadeIn = false;
		fadeCnt = 0;
		return false;
	}
}

// �t�F�[�h�A�E�g�p
bool FadeOutScreen(int fadeStep)
{
	if (fadeCnt <= 255)
	{
		SetDrawBright(255 - fadeCnt, 255 - fadeCnt, 255 - fadeCnt);
		fadeCnt += fadeStep;
		return true;
	}

	if (fadeCnt >= 255)
	{
		SetDrawBright(0, 0, 0);
		fadeOut = false;
		fadeCnt = 0;
		return false;
	}
}
