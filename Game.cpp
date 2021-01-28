#include "Includes.h"

Game::Mode mode;

void Game::Init() {
	
}

void Game::Update() {	
	//static Player *player = new Player[5];
	static Player player[MAX_GAME_PLAYER];
	static int mapNumber = 1;
	static short looser = 0;
	static short soundCheck = 0;

	SetVolumeMusic(100);

	// 処理
	switch (mode)
	{
	case Game::Start:
		Init();
		for (int i = 0; i < MAX_GAME_PLAYER; i++) {
			player[i].Init(i);
		}
		Map::Load(mapNumber);
		looser = 0;
		mode = Stop;
		break;
	case Game::Stop:
		if (soundCheck == 0) {
			PlayMusic("music/Battle.mp3", DX_PLAYTYPE_BACK);
			soundCheck++;
		}
		if (CheckMusic() == 0)soundCheck = 0;
		Map::Draw(mapNumber);
		for (int i = 0; i < MAX_GAME_PLAYER; i++) {
			player[i].Update(i);
			player[i].Draw(i);
			if (player[i].GetHP() == 0) {
				looser = i;
				mode = Over;
				soundCheck = 0;
				StopMusic();
			}
		}
		break;
	case Game::Over:
		if (soundCheck == 0) {
			PlayMusic("music/Over.mp3", DX_PLAYTYPE_BACK);
			soundCheck++;
		}
		if (looser == 0)DrawFormatString(0, 0, 0xfffff, "2Pの勝ち！！");
		else DrawFormatString(0, 0, 0xfffff, "1Pの勝ち！！");
		for (int i = 0; i < MAX_GAME_PLAYER; i++) {
			if (pad[i][XINPUT_BUTTON_START] == 1) {
				mode = Start;
				StopMusic();
			}
		}
		break;
	case Game::Reload:
		break;
	case Game::Exit:
		break;
	default:
		break;
	}
}


