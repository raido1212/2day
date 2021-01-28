#pragma once

class PlayerBullet {
	int posX, posY;
	bool judge;
	short maxLength;
	short count;
	short speed;

public:
	PlayerBullet() {
		speed = 30;
		judge = true;
		maxLength = 100;
		count = 0;
	}
	void ShotBullet(Player *player);
};

