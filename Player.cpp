#include "Includes.h"

PBullet_t bullet[2][1];
int bulletNumber = 0;

void Player::Init(int maxPlayer) {
	HP = 5;
	width = 32.f;
	height = 32.f;
	moveSpeed = 0.f;
	imageChange = 0;
	imageCount = 0;
	jumpOn = false;
	moveDirection = 0;
	speedX = 0;
	speedY = 0;
	if (maxPlayer == 0) {
		if (HP_UI == NULL) HP_UI = LoadGraph("image/ui/1P.png");
		HP_UIposX = 0;
		HP_UIposY = 0;
		posX = 64.f;
		posY = 64.f;
	}
	if (maxPlayer == 1) {
		if (HP_UI == NULL) HP_UI = LoadGraph("image/ui/2P.png");
		HP_UIposX = WINDOW_SIXE_X - 48;
		HP_UIposY = 0;
		posX = WINDOW_SIXE_X - 64.f;
		posY = WINDOW_SIXE_Y - 64.f;
	}
}

void Player::Update(int maxPlayer) {
	// 変数
	static int bulletCount = 0;
	static float gravity = 0.f;
	static short jumpCount = 0;
	

	// 画像変化
	imageCount++;
	if (imageCount % 14 == 0) {
		imageCount = 0;
	}
	//count++;
	
	// キーボード操作
	// 移動
	if (key[KEY_INPUT_LEFT] != 0)moveDirection += 1;
	if (key[KEY_INPUT_UP] != 0)moveDirection += 2;
	if (key[KEY_INPUT_DOWN] != 0)moveDirection += 4;
	if (key[KEY_INPUT_RIGHT] != 0) moveDirection += 8;

	if (pad[maxPlayer][XINPUT_BUTTON_DPAD_LEFT] != 0)moveDirection += 1;
	if (pad[maxPlayer][XINPUT_BUTTON_DPAD_UP] != 0)moveDirection += 2;
	if (pad[maxPlayer][XINPUT_BUTTON_DPAD_DOWN] != 0)moveDirection += 4;
	if (pad[maxPlayer][XINPUT_BUTTON_DPAD_RIGHT] != 0)moveDirection += 8;

	if (moveDirection == 1) {
		bullet[maxPlayer][bulletNumber].rad = 180;
		imageChange = 3;
	}
	else if (moveDirection == 2) {
		bullet[maxPlayer][bulletNumber].rad = -90;
		imageChange = 9;
	}
	else if (moveDirection == 4) {
		bullet[maxPlayer][bulletNumber].rad = 90;
		imageChange = 0;
	}
	else if (moveDirection == 8) {
		bullet[maxPlayer][bulletNumber].rad = 0;
		imageChange = 6;
	}
	
	// 移動制限処理

	if (posX > WINDOW_SIXE_X) {
		posX = WINDOW_SIXE_X - 1;
		speedX *= -1;
	}
	if (posY > WINDOW_SIXE_Y ) {
		posY = WINDOW_SIXE_Y - 1;
		speedY *= -1;
	}
	if (posX < 0) {
		posX = 0 + 1;
		speedX *= -1;
	}
	if (posY < 0) {
		posY = 0 + 1;
		speedY *= -1;
	}

	if (speedX >= 5) speedX = 5;
	if (speedX <= -5) speedX = -5;
	if (speedY >= 5) speedY = 5;
	if (speedY <= -5) speedY = -5;

	posX += speedX;
	posY += speedY;

		// X座標
	if (pad[maxPlayer][XINPUT_BUTTON_DPAD_LEFT] != 0) {
		speedX -= (float)0.1;
	}
	else if (pad[maxPlayer][XINPUT_BUTTON_DPAD_RIGHT] != 0) {
		speedX += (float)0.1;
	}

	// Y座標
	if (pad[maxPlayer][XINPUT_BUTTON_DPAD_UP] != 0) {
		speedY -= (float)0.1;
	}
	else if (pad[maxPlayer][XINPUT_BUTTON_DPAD_DOWN] != 0) {
		speedY += (float)0.1;
	}

	// 弾発射
	
	const int bulletSpeed = 10;

	if (pad[maxPlayer][XINPUT_BUTTON_A] == 1) {
		bullet[maxPlayer][bulletNumber].flag = true;
		bullet[maxPlayer][bulletNumber].x = posX + width / 2 + (bulletSpeed * 2) * cos(bullet[maxPlayer][bulletNumber].rad * UNIT_R);
		bullet[maxPlayer][bulletNumber].y = posY + height / 2 + (bulletSpeed * 2) * sin(bullet[maxPlayer][bulletNumber].rad * UNIT_R);
	}
	if (bullet[maxPlayer][bulletNumber].flag == true) {
		bullet[maxPlayer][bulletNumber].x += bulletSpeed * cos(bullet[maxPlayer][bulletNumber].rad * UNIT_R);
		bullet[maxPlayer][bulletNumber].y += bulletSpeed * sin(bullet[maxPlayer][bulletNumber].rad * UNIT_R);
	}
	else {
		bullet[maxPlayer][bulletNumber].x = -100;
		bullet[maxPlayer][bulletNumber].y = -100;
	}

	// 弾判定
	for (int i = 0; i < MAX_GAME_PLAYER; i++) {
		if (bullet[i][bulletNumber].x > posX &&
			bullet[i][bulletNumber].x < posX + width &&
			bullet[i][bulletNumber].y > posY &&
			bullet[i][bulletNumber].y < posY + width)
		{
			HP--;
			bullet[i][bulletNumber].flag = false;
		}
	}
	
	// パッド初期化処理
	moveDirection = 0;
}

void Player::Draw(int maxPlayer) {
	DrawGraph((int)posX, (int)posY,playerImage[imageChange + (imageCount / 5)],true);
	if (bullet[maxPlayer][bulletNumber].flag) {
		DrawCircle((int)bullet[maxPlayer][bulletNumber].x,
				   (int)bullet[maxPlayer][bulletNumber].y,
				   10,0xfffff,true);
	}
	//DrawGraph((int)HP_UIposX, (int)HP_UIposY, HP_UI, true);
	DrawModiGraph((int)posX ,(int)posY - (int)width / 2,
		(int)posX + HP * ((int)width / 5), (int)posY - (int)width / 2,
		(int)posX + HP * ((int)width / 5), (int)posY - (int)height / 4,
		(int)posX , (int)posY - (int)width / 4,
		HP_UI, TRUE);
}

