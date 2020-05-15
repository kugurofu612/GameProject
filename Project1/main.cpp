// ----------------
// TestProject
//  by Nakagami
// ----------------

#include "DxLib.h"		//DxLib×²ÌŞ×Ø‚ğg—p‚·‚é

#define SCREEN_SIZE_X 800
#define SCREEN_SIZE_Y 600

// •Ï”
int gameCounter;

// ÌßÛÄÀ²ÌßéŒ¾
void GameMain(void);
void GameDraw(void);

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// --------¼½ÃÑˆ—
	SetWindowText("TestProject");
	// ¼½ÃÑˆ—
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16); // 640~480ÄŞ¯Ä65536FÓ°ÄŞ‚Éİ’è
	ChangeWindowMode(true);							// true:window  false:ÌÙ½¸Ø°İ
	if (DxLib_Init() == -1) return -1;				// DX×²ÌŞ×Ø‰Šú‰»ˆ—
	SetDrawScreen(DX_SCREEN_BACK);					// ‚Ğ‚Æ‚Ü‚¸ÊŞ¯¸ÊŞ¯Ì§‚É•`‰æ

	// --------¸Ş×Ì¨¯¸‚Ì“o˜^--------


	// --------•Ï”‰Šú‰»--------
	gameCounter = 0;

	// -------- ¹Ş°ÑÙ°Ìß
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen(); // ‰æ–ÊÁ‹

		// Ò²İˆ—
		GameMain();

		ScreenFlip();	 // — ‰æ–Ê‚ğ•\‰æ–Ê‚ÉuŠÔºËß°
	}
	DxLib_End();
	return 0;
}

// ¹Ş°ÑÒ²İˆ—
void GameMain(void)
{
	GameDraw();
}

// ¹Ş°Ñ•`‰æˆ—
void GameDraw(void)
{
	int countColor = GetColor(255, 255, 255);
	DrawFormatString(0, 0, countColor, "GameCounter = %d", gameCounter++);  //gameCounter‚Í¹Ş°ÑÙ°Ìß’†‚Å¶³İÄ‚³‚¹‚Ä‚àOK

}