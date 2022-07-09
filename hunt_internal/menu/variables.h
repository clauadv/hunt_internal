#pragma once

namespace variables::menu {
	inline bool opened{ true };
}

namespace variables::entities {
	inline bool hunter{ false };
	inline float hunter_color[4]{ 1.f, 0.f, 0.f, 1.f };

	inline bool zombie{ false };
	inline float zombie_color[4]{ 0.2f, 0.5f, 0.9f, 1.f };

	inline bool boss_zombie{ false };
	inline float boss_zombie_color[4]{ 0.2f, 0.5f, 0.9f, 1.f };

	inline bool clue{ false };
	inline float clue_color[4]{ 0.2f, 0.5f, 0.9f, 1.f };

	inline bool extraction{ false };
	inline float extraction_color[4]{ 0.2f, 0.5f, 0.9f, 1.f };

	inline float max_distance{ 100.f };
}