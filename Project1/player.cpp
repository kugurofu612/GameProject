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
XY PlayerControl(void)
{
	bool moveFlag = false;					// true:�ړ�����
	XY playerIndex;						// �}�b�v�z��̍��W
	XY playerPosCopy = player1.pos;			// �v���C���[�̍��W�̃R�s�[
	XY playerPosOffset = playerPosCopy;

	// �v���[���[�̌����̐ݒ�
	// ��ڲ԰�̑���
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

		//// �e��ł�
		//if (keyNew[KEY_ID_SHOT])
		//{
		//	CreateShot(player1.pos, player1.moveDir);
		//}

		////EnemyHitCheckP(player1.pos, player1.size.x, player1.size.y);

		//// �v���C���[�̃C�x���g����(����)
		//if (GetEvent(player1.pos) == EVENT_ID_SPEEDDOWN)
		//{
		//	player1.moveSpeed = DEF_SPEED_LOW;
		//}
		//else
		//{
		//	player1.moveSpeed = DEF_SPEED_NORMAL;
		//}
	}

	// �v���C���[�̈ړ�����
	if (moveFlag)
	{
		switch (player1.moveDir)
		{
		case DIR_UP:
			playerPosCopy.y -= player1.moveSpeed;
			playerPosOffset.y = playerPosCopy.y - player1.offsetSize.y;
			if (IsPass(playerPosOffset))
			{
				// �ʂ��Ă悵
				player1.pos.y = playerPosCopy.y;
			}
			break;
		case DIR_DOWN:
			playerPosCopy.y += player1.moveSpeed;
			playerPosOffset.y = playerPosCopy.y + player1.offsetSize.y;
			if (IsPass(playerPosOffset))
			{
				// �ʂ��Ă悵
				player1.pos.y = playerPosCopy.y;
			}
			break;
		case DIR_LEFT:
			playerPosCopy.x -= player1.moveSpeed;
			playerPosOffset.x = playerPosCopy.x - player1.offsetSize.x;
			if (IsPass(playerPosOffset))
			{
				// �ʂ��Ă悵
				player1.pos.x = playerPosCopy.x;
			}
			break;
		case DIR_RIGHT:
			playerPosCopy.x += player1.moveSpeed;
			playerPosOffset.x = playerPosCopy.x + player1.offsetSize.x;
			if (IsPass(playerPosOffset))
			{
				// �ʂ��Ă悵
				player1.pos.x = playerPosCopy.x;
			}
			break;
		default:
			break;
		}
		player1.animCnt++;
	}

	//// �Ԋu����Ń_���[�W
	//if (damageTime <= 0)
	//{
	//	if (EnemyHitCheckP(player1.pos, player1.offsetSize.x, player1.offsetSize.y))
	//	{
	//		//player1.life -= 1;
	//		damageTime = 60;
	//	}
	//}
	//damageTime--;

	// �}�b�v
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

	// �\�����Ƀf�[�^���i�[
	AddCharaOrder(CHARACTER_PLAYER, 0, player1.pos.y + player1.size.y / 2);

	return player1.pos;
}

// �v���C���[�̕`�揈��
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

//// Y���W�����������̂���`��
//void PlayerDrawIndex(int index)
//{
//	player1.animCnt++;
//
//	DrawGraph(player1.pos.x - player1.offsetSize.x
//		, player1.pos.y - player1.offsetSize.y
//		, playerImage[player1.moveDir * 4 + (player1.animCnt / 30) % 4], true);
//}
//
//// ��ڲ԰�ƓG�̓����蔻��
//bool EnemyHitCheckP(XY pPos, int pSizex, int pSizey)
//{
//	for (int en = 0; en < ENEMY_MAX; en++)
//	{
//		if (enemy[en].life > 0)
//		{
//			// �������������
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
