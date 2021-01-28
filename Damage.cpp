#include "Includes.h"

void PlayerBullet::ShotBullet(Player *player)
{
	const short dir = player->GetDir();
	if (count == 0) {
		posX = player->GetPosX();
		posY = player->GetPosY();
	}
	count++;
	if (judge) {
		switch (dir)
		{
		case 1:		// ��
			posX -= speed;
			break;
		case 2:		// ��
			posY -= speed;
			break;
		case 3:		// ����
			posX -= cos(speed * UNIT_R);
			break;
		case 4:		// ��
			posY += speed;
			break;
		case 5:		// ����

			break;
		case 8:		// �E
			posX += speed;
			break;
		case 10:	// �E��

			break;
		case 12:	// �E��

			break;
		}
	}
}

/*int PlayerBullet::HitBullet(Player *player)
{
	DrawCircle(posX, posY, 10, 0xfffff, true);
	return 0;
}*/
