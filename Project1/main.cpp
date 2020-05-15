// ----------------
// BaseProject
//  by Nakagami
// ----------------

#include "DxLib.h"		//DxLibﾗｲﾌﾞﾗﾘを使用する
#include "main.h"
#include "keycheck.h"
#include "effect.h"

// 変数
int sceneCounter;
SCENE_ID sceneID;
SCENE_ID sceneIDpre;
XY playerPos;		// プレイヤー座標
XY mapPos;			// マップ座標


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	if (!SystemInit())
	{
		return 0;
	}

	// -------- ｹﾞｰﾑﾙｰﾌﾟ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		if (sceneID != sceneIDpre)
		{
			sceneIDpre = sceneID;
			sceneCounter = 0;
		}

		KeyCheck();

		ClsDrawScreen(); // 画面消去

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
					// フェードインが終了したときのの処理
				}
			}
			if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{
					// フェードアウトした後に行う処理を描く
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
					// フェードインが終了したときのの処理
				}
			}
			if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{
					// フェードアウトした後に行う処理を描く
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
					// フェードインが終了したときのの処理
				}
			}
			if (fadeOut)
			{
				if (!FadeOutScreen(5))
				{
					// フェードアウトした後に行う処理を描く
					fadeIn = true;
					sceneID = SCENE_ID_INIT;
				}
			}

			GameOverScene();
			break;

		default:
			break;
		}
		// ﾒｲﾝ処理

		ScreenFlip();	 // 裏画面を表画面に瞬間ｺﾋﾟｰ
	}
	DxLib_End();
	return 0;
}

// システム初期化
bool SystemInit(void)
{
	// --------ｼｽﾃﾑ処理
	SetWindowText("BaseProject");

	// ｼｽﾃﾑ処理
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16); // 640×480ﾄﾞｯﾄ65536色ﾓｰﾄﾞに設定
	ChangeWindowMode(true);							// true:window  false:ﾌﾙｽｸﾘｰﾝ
	if (DxLib_Init() == -1) return -1;				// DXﾗｲﾌﾞﾗﾘ初期化処理
	SetDrawScreen(DX_SCREEN_BACK);					// ひとまずﾊﾞｯｸﾊﾞｯﾌｧに描画

	KeyInit();

	// --------ｸﾞﾗﾌｨｯｸの登録--------


	// --------変数初期化--------
	// シーン管理用
	sceneCounter = 0;
	sceneID = SCENE_ID_INIT;
	sceneIDpre = SCENE_ID_GAMEOVER;
	playerPos.x = SCREEN_SIZE_X / 2;
	playerPos.y = SCREEN_SIZE_Y / 2;
	mapPos.x = 0;
	mapPos.y = 0;

	EffectInit();			// エフェクト用初期化処理

	return true;
}

// 初期化シーン
void InitScene(void)
{
	//sceneID = SCENE_ID_TITLE;
}

// タイトルシーン
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
	DrawFormatString(0, 0, GetColor(255, 255, 255), "TitleCounter = %d", sceneCounter++);  //gameCounterはｹﾞｰﾑﾙｰﾌﾟ中でｶｳﾝﾄさせてもOK
	DrawBox(100, 100, 700, 500, GetColor(0, 255, 0), true);

}

// ｹﾞｰﾑﾒｲﾝ処理
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

	// プレイヤー操作	
	if (CheckHitKey(KEY_INPUT_UP))
	{
		playerPos.y -= 4;
		//if ((mapPos.y + playerPos.y) < (SCROLL_Y_MIN))
		//{
		//	mapPos.y += 4;
		//}
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		playerPos.y += 4;
	/*	if ((mapPos.y + playerPos.y) > (SCROLL_Y_MAX))
		{
			mapPos.y -= 4;
		}*/
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		playerPos.x -= 4;
	/*	if ((mapPos.x + playerPos.x) < (SCROLL_X_MIN))
		{
			mapPos.x += 4;
		}*/
	}
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		playerPos.x += 4;
	/*	if ((mapPos.x + playerPos.x) > (SCROLL_X_MAX))
		{
			mapPos.x -= 4;
		}*/
	}


	testCnt++;

	GameDraw();
}

// ｹﾞｰﾑ描画処理
void GameDraw(void)
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "GameCounter = %d", sceneCounter++);  //gameCounterはｹﾞｰﾑﾙｰﾌﾟ中でｶｳﾝﾄさせてもOK
	DrawFormatString(50, 50, GetColor(255, 255, 255), "Test = %d", testCnt);
	DrawFormatString(20, 20, GetColor(255, 255, 255), "playerPos = %d : %d", playerPos.x, playerPos.y);

	DrawBox(100, 100, 700, 500, GetColor(255, 0, 0), true);

	DrawCircle(playerPos.x, playerPos.y, 16, GetColor(255, 255, 255), true);

	if (pauseFlag == true)
	{
		SetDrawBright(100, 100, 100);
		DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2, GetColor(255, 255, 255), "ＰＡＵＳＥ");
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

// ゲームオーバーシーン
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
	DrawFormatString(0, 0, GetColor(255, 255, 255), "GameOverCounter = %d", sceneCounter++);  //gameCounterはｹﾞｰﾑﾙｰﾌﾟ中でｶｳﾝﾄさせてもOK
	DrawBox(100, 100, 700, 500, GetColor(0, 0, 255), true);

}