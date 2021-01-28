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
		case 1:		// ç∂
			posX -= speed;
			break;
		case 2:		// è„
			posY -= speed;
			break;
		case 3:		// ç∂è„
			posX -= cos(speed * UNIT_R);
			break;
		case 4:		// â∫
			posY += speed;
			break;
		case 5:		// ç∂â∫

			break;
		case 8:		// âE
			posX += speed;
			break;
		case 10:	// âEè„

			break;
		case 12:	// âEâ∫

			break;
		}
	}
}

/*int PlayerBullet::HitBullet(Player *player)
{
	DrawCircle(posX, posY, 10, 0xfffff, true);
	return 0;
}*/
