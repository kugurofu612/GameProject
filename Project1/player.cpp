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
XY PlayerControl(void)
{
	bool moveFlag = false;					// true:移動する
	XY playerIndex;						// マップ配列の座標
	XY playerPosCopy = player1.pos;			// プレイヤーの座標のコピー
	XY playerPosOffset = playerPosCopy;

	// プレーヤーの向きの設定
	// ﾌﾟﾚｲﾔｰの操作
	if (player1.life > 0)
	{
		if (keyNew[KEY_ID_UP])
		{
			player1.moveDir = DIR_UP;
			moveFlag = true;
			if ((player1.pos.y - mapPos.y) < SCROLL_Y_MIN)
			{
				mapPos.y -= player1.moveSpeed;
				//player1.pos.y += player1.moveSpeed;
			}
		}
		if (keyNew[KEY_ID_DOWN])
		{
			player1.moveDir = DIR_DOWN;
			moveFlag = true;
			if ((-mapPos.y + player1.pos.y) > SCROLL_Y_MAX)
			{
				mapPos.y += player1.moveSpeed;
				//player1.pos.y -= player1.moveSpeed;
			}
		}
		if (keyNew[KEY_ID_LEFT])
		{
			player1.moveDir = DIR_LEFT;
			moveFlag = true;
			if ((player1.pos.x - mapPos.x) < (SCROLL_X_MIN))
			{
				mapPos.x -= player1.moveSpeed;
				//player1.pos.x += player1.moveSpeed;
			}
		}
		if (keyNew[KEY_ID_RIGHT])
		{
			player1.moveDir = DIR_RIGHT;
			moveFlag = true;
			if ((-mapPos.x + player1.pos.x) > (SCROLL_X_MAX))
			{
				mapPos.x += player1.moveSpeed;
				//player1.pos.x -= player1.moveSpeed;
			}
		}

		//// 弾を打つ
		//if (keyNew[KEY_ID_SHOT])
		//{
		//	CreateShot(player1.pos, player1.moveDir);
		//}

		////EnemyHitCheckP(player1.pos, player1.size.x, player1.size.y);

		//// プレイヤーのイベント処理(水中)
		//if (GetEvent(player1.pos) == EVENT_ID_SPEEDDOWN)
		//{
		//	player1.moveSpeed = DEF_SPEED_LOW;
		//}
		//else
		//{
		//	player1.moveSpeed = DEF_SPEED_NORMAL;
		//}
	}

	// プレイヤーの移動処理
	if (moveFlag)
	{
		switch (player1.moveDir)
		{
		case DIR_UP:
			playerPosCopy.y -= player1.moveSpeed;
			playerPosOffset.y = playerPosCopy.y - player1.offsetSize.y;
			if (IsPass(playerPosOffset))
			{
				// 通ってよし
				player1.pos.y = playerPosCopy.y;
			}
			break;
		case DIR_DOWN:
			playerPosCopy.y += player1.moveSpeed;
			playerPosOffset.y = playerPosCopy.y + player1.offsetSize.y;
			if (IsPass(playerPosOffset))
			{
				// 通ってよし
				player1.pos.y = playerPosCopy.y;
			}
			break;
		case DIR_LEFT:
			playerPosCopy.x -= player1.moveSpeed;
			playerPosOffset.x = playerPosCopy.x - player1.offsetSize.x;
			if (IsPass(playerPosOffset))
			{
				// 通ってよし
				player1.pos.x = playerPosCopy.x;
			}
			break;
		case DIR_RIGHT:
			playerPosCopy.x += player1.moveSpeed;
			playerPosOffset.x = playerPosCopy.x + player1.offsetSize.x;
			if (IsPass(playerPosOffset))
			{
				// 通ってよし
				player1.pos.x = playerPosCopy.x;
			}
			break;
		default:
			break;
		}
		player1.animCnt++;
	}

	//// 間隔ありでダメージ
	//if (damageTime <= 0)
	//{
	//	if (EnemyHitCheckP(player1.pos, player1.offsetSize.x, player1.offsetSize.y))
	//	{
	//		//player1.life -= 1;
	//		damageTime = 60;
	//	}
	//}
	//damageTime--;

	// マップ
	if (mapPos.x < 0)
	{
		mapPos.x = 0;
	}
	if (mapPos.y < 0)
	{
		mapPos.y = 0;
	}
	if (mapPos.x > MAP_X * CHIP_SIZE_X - SCREEN_SIZE_X)
	{
		mapPos.x = MAP_X * CHIP_SIZE_X - SCREEN_SIZE_X;
	}
	if (mapPos.y > MAP_Y * CHIP_SIZE_Y - SCREEN_SIZE_Y)
	{
		mapPos.y = MAP_Y * CHIP_SIZE_Y - SCREEN_SIZE_Y;
	}

	// 表示順にデータを格納
	AddCharaOrder(CHARACTER_PLAYER, 0, player1.pos.y + player1.size.y / 2);

	return player1.pos;
}

// プレイヤーの描画処理
void PlayerGameDraw(void)
{
	player1.animCnt++;

	XY index;
	index = PosToIndex(player1.pos);

	DrawFormatString(0, 32, GetColor(255, 255, 255), "Player: %d, %d", player1.pos.x, player1.pos.y);
	DrawFormatString(0, 48, GetColor(255, 255, 255), "   map: %d, %d", index.x, index.y);
	DrawFormatString(0, 64, GetColor(255, 255, 255), "Player.Life = %d", player1.life);

	DrawGraph(-mapPos.x + player1.pos.x - player1.offsetSize.x
		, -mapPos.y + player1.pos.y - player1.offsetSize.y
		, playerImage[player1.moveDir * 4 + (player1.animCnt / 30) % 4], true);
}

//// Y座標が小さいものから描画
//void PlayerDrawIndex(int index)
//{
//	player1.animCnt++;
//
//	DrawGraph(player1.pos.x - player1.offsetSize.x
//		, player1.pos.y - player1.offsetSize.y
//		, playerImage[player1.moveDir * 4 + (player1.animCnt / 30) % 4], true);
//}
//
//// ﾌﾟﾚｲﾔｰと敵の当たり判定
//bool EnemyHitCheckP(XY pPos, int pSizex, int pSizey)
//{
//	for (int en = 0; en < ENEMY_MAX; en++)
//	{
//		if (enemy[en].life > 0)
//		{
//			// 当たったら消す
//			if ((enemy[en].pos.x - enemy[en].size.x / 2 < pPos.x + pSizex) &&
//				(enemy[en].pos.x + enemy[en].size.x / 2 > pPos.x - pSizex) &&
//				(enemy[en].pos.y - enemy[en].size.y / 2 < pPos.y + pSizey) &&
//				(enemy[en].pos.y + enemy[en].size.y / 2 > pPos.y - pSizey))
//			{
//				//enemy[j].life = 1;
//				player1.life -= 1;
//				if (player1.life <= 0)
//				{
//					SCENE_ID_GAMEOVER;
//					fadeOut = true;
//					fadeIn = false;
//				}
//				return true;
//			}
//		}
//	}
//	return false;
//}
