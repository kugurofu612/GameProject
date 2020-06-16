#include "DxLib.h"
#include "main.h"
#include "player.h"
#include "keycheck.h"
#include "stage.h"

// �ϐ�
XY index;

CHARACTER player1;			// �v���C���[�̏��Ǘ��p
int playerImage[16];		// �v���C���[�̉摜���i�[�̈�
int damageTime;

// �v���C���[���̏�����
void PlayerSystemInit(void)
{
	// �O���t�B�b�N�X�̓o�^
	//SetTransColor(255, 0, 255);
	LoadDivGraph("image/player.png", 12, 3, 4, 24, 33, playerImage);

	// �ϐ��̏�����
	//player1.charType = 1;									// �L�����N�^�̎��
	player1.moveDir = DIR_DOWN;								// �L�����N�^�̌���
	player1.pos.x = SCREEN_SIZE_X / 2;				// �L�����N�^�̒n�}��̍��W
	player1.pos.y = SCREEN_SIZE_Y / 2;
	player1.size.x = 24;							// �L�����N�^�摜�̃T�C�Y
	player1.size.y = 32;
	player1.offsetSize.x = player1.size.x / 2;		// �L�����N�^�̃I�t�Z�b�g�T�C�Y
	player1.offsetSize.y = player1.size.y / 2;
	player1.moveSpeed = 3;							// �L�����N�^�̈ړ��X�s�[�h
	player1.lifeMax = 20;							// �L�����N�^�̗͍̑ő�l
	player1.life = player1.lifeMax;					// �L�����N�^�̗̑�
	player1.animCnt = 0;							// �L�����N�^�̃A�j���[�V�����J�E���^
	player1.Flag = false;
}

void PlayerGameInit(void)
{

}

// �v���C���[�̑��쏈��
