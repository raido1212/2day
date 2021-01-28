#pragma once

typedef struct {
	double x, y;
	double rad;
	bool flag;
}PBullet_t;

class Player{
	float posX, posY;
	float width, height;
	float moveSpeed;
	short level;
	bool  move;
	int	  playerImage[12];
	short imageChange;
	short imageCount;
	bool  jumpOn;
	float speedX;
	float speedY;
	short HP;
	short moveDirection;
	int	  HP_UI;
	int   HP_UIposX;
	int	  HP_UIposY;
public:
	Player() {
		LoadDivGraph("image/vehicle/vehicle1.png", 12, 3, 4, 32, 32, playerImage);
	}
	void Init(int maxPlayer);
	void Update(int maxPlayer);
	void Draw(int maxPlayer);
	short GetDir() { return moveDirection; }
	float GetPosX() { return posX; }
	float GetPosY() { return posY; }
	int	  GetHP() { return HP; }
};