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
		case 1:		// 左
			posX -= speed;
			break;
		case 2:		// 上
			posY -= speed;
			break;
		case 3:		// 左上
			posX -= cos(speed * UNIT_R);
			break;
		case 4:		// 下
			posY += speed;
			break;
		case 5:		// 左下

			break;
		case 8:		// 右
			posX += speed;
			break;
		case 10:	// 右上

			break;
		case 12:	// 右下

			break;
		}
	}
}

/*int PlayerBullet::HitBullet(Player *player)
{
	DrawCircle(posX, posY, 10, 0xfffff, true);
	return 0;
}*/
