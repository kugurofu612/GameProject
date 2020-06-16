#include "DxLib.h"
#include "main.h"
#include "player.h"
#include "keycheck.h"
#include "stage.h"

// 変数
XY index;

CHARACTER player1;			// プレイヤーの情報管理用
int playerImage[16];		// プレイヤーの画像情報格納領域
int damageTime;

// プレイヤー情報の初期化
void PlayerSystemInit(void)
{
	// グラフィックスの登録
	//SetTransColor(255, 0, 255);
	LoadDivGraph("image/player.png", 12, 3, 4, 24, 33, playerImage);

	// 変数の初期化
	//player1.charType = 1;									// キャラクタの種類
	player1.moveDir = DIR_DOWN;								// キャラクタの向き
	player1.pos.x = SCREEN_SIZE_X / 2;				// キャラクタの地図上の座標
	player1.pos.y = SCREEN_SIZE_Y / 2;
	player1.size.x = 24;							// キャラクタ画像のサイズ
	player1.size.y = 32;
	player1.offsetSize.x = player1.size.x / 2;		// キャラクタのオフセットサイズ
	player1.offsetSize.y = player1.size.y / 2;
	player1.moveSpeed = 3;							// キャラクタの移動スピード
	player1.lifeMax = 20;							// キャラクタの体力最大値
	player1.life = player1.lifeMax;					// キャラクタの体力
	player1.animCnt = 0;							// キャラクタのアニメーションカウンタ
	player1.Flag = false;
}

void PlayerGameInit(void)
{

}

// プレイヤーの操作処理
