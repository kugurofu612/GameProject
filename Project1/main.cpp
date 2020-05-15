// ----------------
// TestProject
//  by Nakagami
// ----------------

#include "DxLib.h"		//DxLibײ���؂��g�p����

#define SCREEN_SIZE_X 800
#define SCREEN_SIZE_Y 600

// �ϐ�
int gameCounter;

// �������ߐ錾
void GameMain(void);
void GameDraw(void);

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// --------���я���
	SetWindowText("TestProject");
	// ���я���
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16); // 640�~480�ޯ�65536�FӰ�ނɐݒ�
	ChangeWindowMode(true);							// true:window  false:�ٽ�ذ�
	if (DxLib_Init() == -1) return -1;				// DXײ���؏���������
	SetDrawScreen(DX_SCREEN_BACK);					// �ЂƂ܂��ޯ��ޯ̧�ɕ`��

	// --------���̨���̓o�^--------


	// --------�ϐ�������--------
	gameCounter = 0;

	// -------- �ް�ٰ��
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen(); // ��ʏ���

		// Ҳݏ���
		GameMain();

		ScreenFlip();	 // ����ʂ�\��ʂɏu�Ժ�߰
	}
	DxLib_End();
	return 0;
}

// �ް�Ҳݏ���
void GameMain(void)
{
	GameDraw();
}

// �ްѕ`�揈��
void GameDraw(void)
{
	int countColor = GetColor(255, 255, 255);
	DrawFormatString(0, 0, countColor, "GameCounter = %d", gameCounter++);  //gameCounter�͹ް�ٰ�ߒ��Ŷ��Ă����Ă�OK

}