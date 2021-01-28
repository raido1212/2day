#include "Includes.h"

short key[256];
short pad[2][16];
short mouse[3];

int MouseInput() {

	return 0;
}

int KeyInput() {
	char nowKey[256];
	GetHitKeyStateAll(nowKey);
	for (int i = 0; i < 256; i++) {
		if (nowKey[i] != 0) {
			if (key[i] < 60) {
				key[i]++;
			}
		}
		else {
			key[i] = 0;
		}
	}
	return 0;
}

int PadInput() {
	static XINPUT_STATE xinput[2];
	GetJoypadXInputState(DX_INPUT_PAD1, &xinput[0]);
	GetJoypadXInputState(DX_INPUT_PAD2, &xinput[1]);
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 16; i++) {
			if (xinput[j].Buttons[i] != 0) {
				if (pad[j][i] != 60) {
					pad[j][i]++;
				}
			}
			else {
				pad[j][i] = 0;
			}
		}
	}
	return 0;
}