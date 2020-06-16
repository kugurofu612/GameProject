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

// �\����
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

// ��������
enum DIR {
	DIR_UP,
	DIR_RIGHT,
	DIR_DOWN,
	DIR_LEFT,
	DIR_MAX
};

struct CHARACTER {
	int charType;			// �L�����N�^�̎��
	DIR moveDir;			// �L�����N�^�̌���
	XY pos;					// �L�����N�^�̒n�}��̍��W
	XY offsetSize;			// �L�����N�^�̃I�t�Z�b�g�T�C�Y
	XY size;				// �L�����N�^�摜�̃T�C�Y
	int moveSpeed;			// �L�����N�^�̈ړ��X�s�[�h
	int life;				// �L�����N�^�̗̑�
	int lifeMax;			// �L�����N�^�̗͍̑ő�l
	int animCnt;			// �L�����N�^�̃A�j���[�V�����J�E���^
	int point;				// �L�����N�^�̃|�C���g
	bool Flag;				// �L�����N�^�̃t���O
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

