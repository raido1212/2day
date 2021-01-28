#pragma once

namespace Game {
	enum Mode {
		Start,
		Stop,
		Over,
		Reload,
		Load,
		Menu,
		Exit,
	};

	void Init();
	void Update();
	void Draw();
}