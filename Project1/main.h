// ----------------
// BaseProject
//  by Nakagami
// ----------------
// #pragma once

// ��`
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

// �V�[���Ǘ��p
enum SCENE_ID {
	SCENE_ID_INIT,				// �������V�[��
	SCENE_ID_TITLE,				// �^�C�g���V�[��
	SCENE_ID_GAME,				// �Q�[���V�[��
	SCENE_ID_GAMEOVER			// �Q�[���I�[�o�[�V�[��
};

struct XY {
	int x;
	int y;
};

// �������ߐ錾
//---------------------
bool SystemInit(void);
// �������V�[��
void InitScene(void);
// �^�C�g���V�[��
void TitleScene(void);
void TitleDraw(void);
// �Q�[���V�[��
void GameMain(void);			// �ް�Ҳݏ���
void GameDraw(void);			// �ްѕ`�揈��
// �Q�[���I�[�o�[�V�[��
void GameOverScene(void);
void GameOverDraw(void);

