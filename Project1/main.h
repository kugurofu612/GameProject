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

// 構造体
//-----------------------
struct XY {
	int x;
	int y;
};

enum CHARACTER_TYPE {
	CHARACTER_PLAYER,
	CHARACTER_ENEMY,
	CHARACTER_SHOT,
	CHARACTER_MAX
};

// 方向制御
enum DIR {
	DIR_UP,
	DIR_RIGHT,
	DIR_DOWN,
	DIR_LEFT,
	DIR_MAX
};

struct CHARACTER {
	int charType;			// キャラクタの種類
	DIR moveDir;			// キャラクタの向き
	XY pos;					// キャラクタの地図上の座標
	XY offsetSize;			// キャラクタのオフセットサイズ
	XY size;				// キャラクタ画像のサイズ
	int moveSpeed;			// キャラクタの移動スピード
	int life;				// キャラクタの体力
	int lifeMax;			// キャラクタの体力最大値
	int animCnt;			// キャラクタのアニメーションカウンタ
	int point;				// キャラクタのポイント
	bool Flag;				// キャラクタのフラグ
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

