// ----------------
// BaseProject
//  by Nakagami
// ----------------
// #pragma once

// 定義
#define SCREEN_SIZE_X 800
#define SCREEN_SIZE_Y 600
#define MAP_X 32
#define MAP_Y 32
#define CHIP_SIZE_X 32
#define CHIP_SIZE_Y 32
#define SCROLL_X_MIN 100
#define SCROLL_X_MAX 700
#define SCROLL_Y_MIN 100
#define SCROLL_Y_MAX 500

// シーン管理用
enum SCENE_ID {
	SCENE_ID_INIT,				// 初期化シーン
	SCENE_ID_TITLE,				// タイトルシーン
	SCENE_ID_GAME,				// ゲームシーン
	SCENE_ID_GAMEOVER			// ゲームオーバーシーン
};

struct XY {
	int x;
	int y;
};

// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
//---------------------
bool SystemInit(void);
// 初期化シーン
void InitScene(void);
// タイトルシーン
void TitleScene(void);
void TitleDraw(void);
// ゲームシーン
void GameMain(void);			// ｹﾞｰﾑﾒｲﾝ処理
void GameDraw(void);			// ｹﾞｰﾑ描画処理
// ゲームオーバーシーン
void GameOverScene(void);
void GameOverDraw(void);

