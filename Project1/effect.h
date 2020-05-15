// ----------------
// effect.h
//  2019.10.01  by Nakagami
// ----------------
// #pragma once

// 一時停止処理用
extern bool pauseFlag;				// 一維持停止機能用(true ; 一時停止中)
extern int testCnt;
// フェード処理用
extern bool fadeIn;					// フェードイン
extern bool fadeOut;				// フェードアウト

// ﾌﾟﾛﾄﾀｲﾌﾟ宣言
//---------------------
void EffectInit(void);					// エフェクト用初期化処理

// シーン遷移関数
bool FadeInScreen(int fadeStep);		// フェードイン用
bool FadeOutScreen(int fadeStep);		// フェードアウト用
