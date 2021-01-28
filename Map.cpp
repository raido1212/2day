#include "Includes.h"

short FullMap[15][20];
int   mapBaseImage[20];

void Map::Load(int map_number) {
	if (mapBaseImage[0] != 0) {
		DeleteGraph(mapBaseImage[20]);
	}
	LoadDivGraph("image/map/ground.png", 20, 5, 4, 32, 32, mapBaseImage);
	static int  textLoad;
	char loadLine[60];
	int width = 0, height = 0;

	switch (map_number)
	{
	case 1:
		// 画像セット
		textLoad = FileRead_open("stage1.txt");
		if (textLoad == NULL) {
			MessageBox(NULL, TEXT("ステージ読み込みできませんでした"), TEXT("メッセージボックス"), MB_OK);
			break;
		}
		while (1)
		{
			for (int i = 0; i < 60; i++) {
				loadLine[i] = FileRead_getc(textLoad);
				if (loadLine[i] == ',') {
					loadLine[i] = '\0';
					FullMap[height][width] = atoi(loadLine);
					width++;
					loadLine[i];
					break;
				}
				else if (loadLine[i] == '\n') {
					i = -1;
					height++;
					width = 0;
				}
				if (loadLine[i] == EOF) {
					goto EXFILE;
				}
			}
		}
		break;
	case 2:
		// 画像セット
		textLoad = FileRead_open("stage2.txt");
		if (textLoad == NULL) {
			MessageBox(NULL, TEXT("ステージ読み込みできませんでした"), TEXT("メッセージボックス"), MB_OK);
			break;
		}
		while (1)
		{
			for (int i = 0; i < 60; i++) {
				loadLine[i] = FileRead_getc(textLoad);
				if (loadLine[i] == ',') {
					loadLine[i] = '\0';
					FullMap[height][width] = atoi(loadLine);
					width++;
					loadLine[i];
					break;
				}
				else if (loadLine[i] == '\n') {
					i = -1;
					height++;
					width = 0;
				}
				if (loadLine[i] == EOF) {
					goto EXFILE;
				}
			}
		}
		break;
	case 3:
		// 画像セット
		textLoad = FileRead_open("stage3.txt");
		if (textLoad == NULL) {
			MessageBox(NULL, TEXT("ステージ読み込みできませんでした"), TEXT("メッセージボックス"), MB_OK);
			break;
		}
		while (1)
		{
			for (int i = 0; i < 60; i++) {
				loadLine[i] = FileRead_getc(textLoad);
				if (loadLine[i] == ',') {
					loadLine[i] = '\0';
					FullMap[height][width] = atoi(loadLine);
					width++;
					loadLine[i];
					break;
				}
				else if (loadLine[i] == '\n') {
					i = -1;
					height++;
					width = 0;
				}
				if (loadLine[i] == EOF) {
					goto EXFILE;
				}
			}
		}
		break;
	}
EXFILE:
	FileRead_close(textLoad);
}

void Map::Draw(int map_number)
{
	switch (map_number)
	{
	case 1:
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 15; j++) {
				DrawGraph(i * 32, j * 32, mapBaseImage[0], TRUE);
			}
		}
		break;
	case 2:
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 15; j++) {
				DrawGraph(i * 32, j * 32, mapBaseImage[1], TRUE);
			}
		}
		break;
	case 3:
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 15; j++) {
				DrawGraph(i * 32, j * 32, mapBaseImage[8], TRUE);
			}
		}
		break;
	}
}