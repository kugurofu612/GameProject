// ----------------
// BaseProject
//  by Nakagami
// ----------------

#include "DxLib.h"		//DxLibײ���؂��g�p����
#include "main.h"
#include "keycheck.h"
#include "effect.h"
#include "player.h"
#include "stage.h"

// �ϐ�
int sceneCounter;
SCENE_ID sceneID;
SCENE_ID sceneIDpre;
XY playerPos;		// �v���C���[���W
XY mapPos;			// �}�b�v���W


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	if (!SystemInit())
	{
		return 0;
	}

	// -------- �ް�ٰ��
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		if (sceneID != sceneIDpre)
		{
			sceneIDpre = sceneID;
			sceneCounter = 0;
		}

		KeyCheck();

		ClsDrawScreen(); // ��ʏ���

		switch (sceneID)
		{
		case SCENE_ID_INIT:
			InitScene();
			sceneID = SCENE_ID_TITLE;
			break;

		case SCENE_ID_TITLE:
			if (fadeIn)
			{
				if (FadeInScreen(5))
				{
					// �t�F�[�h�C�����I�������Ƃ��̂̏���
				}
			}
			if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{
					// �t�F�[�h�A�E�g������ɍs��������`��
					fadeIn = true;
					sceneID = SCENE_ID_GAME;
				}
			}

			TitleScene();
			break;

		case SCENE_ID_GAME:
			if (fadeIn)
			{
				if (FadeInScreen(5))
				{
					// �t�F�[�h�C�����I�������Ƃ��̂̏���
				}
			}
			if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{
					// �t�F�[�h�A�E�g������ɍs��������`��
					fadeIn = true;
					sceneID = SCENE_ID_GAMEOVER;
				}
			}

			GameMain();
			break;

		case SCENE_ID_GAMEOVER:
			if (fadeIn)
			{
				if (FadeInScreen(5))
				{
					// �t�F�[�h�C�����I�������Ƃ��̂̏���
				}
			}
			if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{
					// �t�F�[�h�A�E�g������ɍs��������`��
					fadeIn = true;
					sceneID = SCENE_ID_INIT;
				}
			}

			GameOverScene();
			break;

		default:
			break;
		}
		// Ҳݏ���

		ScreenFlip();	 // ����ʂ�\��ʂɏu�Ժ�߰
	}
	DxLib_End();
	return 0;
}

// �V�X�e��������
bool SystemInit(void)
{
	// --------���я���
	SetWindowText("BaseProject");

	// ���я���
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16); // 640�~480�ޯ�65536�FӰ�ނɐݒ�
	ChangeWindowMode(true);							// true:window  false:�ٽ�ذ�
	if (DxLib_Init() == -1) return -1;				// DXײ���؏���������
	SetDrawScreen(DX_SCREEN_BACK);					// �ЂƂ܂��ޯ��ޯ̧�ɕ`��

	KeyInit();

	// --------���̨���̓o�^--------


	// --------�ϐ�������--------
	// �V�[���Ǘ��p
	sceneCounter = 0;
	sceneID = SCENE_ID_INIT;
	sceneIDpre = SCENE_ID_GAMEOVER;
	playerPos.x = SCREEN_SIZE_X / 2;
	playerPos.y = SCREEN_SIZE_Y / 2;
	mapPos.x = 0;
	mapPos.y = 0;

	EffectInit();			// �G�t�F�N�g�p����������

	return true;
}

// �������V�[��
void InitScene(void)
{
	//sceneID = SCENE_ID_TITLE;
}

// �^�C�g���V�[��
void TitleScene(void)
{
	if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
		//sceneID = SCENE_ID_GAME;
	}

	TitleDraw();
}
void TitleDraw(void)
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "TitleCounter = %d", sceneCounter++);  //gameCounter�͹ް�ٰ�ߒ��Ŷ��Ă����Ă�OK
	DrawBox(100, 100, 700, 500, GetColor(0, 255, 0), true);

}

// �ް�Ҳݏ���
void GameMain(void)
{
	if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
		//sceneID = SCENE_ID_GAMEOVER;
	}

	if ((keyDownTrigger[KEY_ID_PAUSE]) && (!pauseFlag))
	{
		pauseFlag = true;
	}
	else if ((keyDownTrigger[KEY_ID_PAUSE]) && (pauseFlag))
	{
		pauseFlag = false;
	}
	else
	{

	}

	// �v���C���[����	
	if (CheckHitKey(KEY_INPUT_UP))
	{
		playerPos.y -= 4;
		if ((mapPos.y + playerPos.y) < (SCROLL_Y_MIN))
		{
			mapPos.y += 4;
		}
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		playerPos.y += 4;
		if ((mapPos.y + playerPos.y) > (SCROLL_Y_MAX))
		{
			mapPos.y -= 4;
		}
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		playerPos.x -= 4;
		if ((mapPos.x + playerPos.x) < (SCROLL_X_MIN))
		{
			mapPos.x += 4;
		}
	}
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		playerPos.x += 4;
		if ((mapPos.x + playerPos.x) > (SCROLL_X_MAX))
		{
			mapPos.x -= 4;
		}
	}

	// �v���C���[�̈ړ�����
	if (playerPos.x > CHIP_SIZE_X * MAP_X) playerPos.x = CHIP_SIZE_X * MAP_X;
	if (playerPos.x < 0) playerPos.x = 0;
	if (playerPos.y > CHIP_SIZE_Y * MAP_Y) playerPos.y = CHIP_SIZE_Y * MAP_Y;
	if (playerPos.y < 0) playerPos.y = 0;

	// �}�b�v����
	if (CheckHitKey(KEY_INPUT_W)) mapPos.y += 4;
	if (CheckHitKey(KEY_INPUT_S)) mapPos.y -= 4;
	if (CheckHitKey(KEY_INPUT_A)) mapPos.x += 4;
	if (CheckHitKey(KEY_INPUT_D)) mapPos.x -= 4;

	// �}�b�v�̈ړ�����
	if (mapPos.x < SCREEN_SIZE_X - CHIP_SIZE_X * MAP_X) mapPos.x = SCREEN_SIZE_X - CHIP_SIZE_X * MAP_X;
	if (mapPos.x > 0) mapPos.x = 0;
	if (mapPos.y < SCREEN_SIZE_Y - CHIP_SIZE_Y * MAP_Y) mapPos.y = SCREEN_SIZE_Y - CHIP_SIZE_Y * MAP_Y;
	if (mapPos.y > 0) mapPos.y = 0;

	testCnt++;

	GameDraw();
}

// �ްѕ`�揈��
void GameDraw(void)
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "GameCounter = %d", sceneCounter++);  //gameCounter�͹ް�ٰ�ߒ��Ŷ��Ă����Ă�OK
	DrawFormatString(50, 50, GetColor(255, 255, 255), "Test = %d", testCnt);

	DrawFormatString(20, 20, GetColor(255, 255, 255), "playerPos = %d : %d", playerPos.x, playerPos.y);

	//DrawBox(100, 100, 700, 500, GetColor(255, 0, 0), true);
	for (int x = 0; x < MAP_X; x++)
	{
		for (int y = 0; y < MAP_Y; y++)
		{
			DrawBox(CHIP_SIZE_X * x + mapPos.x, CHIP_SIZE_Y * y + mapPos.y,
				CHIP_SIZE_X * (x + 1) + mapPos.x, CHIP_SIZE_Y * (y + 1) + mapPos.y,
				GetColor(128, 128, 128), false);

			// ��ʂɃ}�X�̔ԍ���\������
			DrawFormatString(CHIP_SIZE_X * x + mapPos.x, CHIP_SIZE_Y * y + mapPos.y,
				GetColor(0, 128, 0), "%03X", x + y * MAP_X);				// %��X�̊Ԃ�0�ƌ���������Ƃ��̌����ɍ��킹�邽�߂ɐ����̓���0���ǉ������
		}
	}

	DrawCircle(playerPos.x + mapPos.x, playerPos.y + mapPos.y, 16, GetColor(255, 255, 255), true);
	DrawBox(100, 100, 700, 500, GetColor(255, 255, 255), false);

	if (pauseFlag == true)
	{
		SetDrawBright(100, 100, 100);
		DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(255, 255, 255), "�o�`�t�r�d");
		testCnt--;
	}
	if (!pauseFlag)
	{
		SetDrawBright(255, 255, 255);
	}
	else
	{

	}
}

// �Q�[���I�[�o�[�V�[��
void GameOverScene(void)
{
	if (keyDownTrigger[KEY_ID_SPACE])
	{
		fadeOut = true;
		//sceneID = SCENE_ID_INIT;
	}

	GameOverDraw();
}
void GameOverDraw(void)
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "GameOverCounter = %d", sceneCounter++);  //gameCounter�͹ް�ٰ�ߒ��Ŷ��Ă����Ă�OK
	DrawBox(100, 100, 700, 500, GetColor(0, 0, 255), true);

}