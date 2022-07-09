#pragma once

namespace cry_engine::cry_renderer {
	class i_renderer {
	public:
		bool project_to_screen(float ptx, float pty, float ptz, float* sx, float* sy, float* sz) {
			return cry_engine::sdk::call<65, bool>(this, ptx, pty, ptz, sx, sy, sz);
		}
	};

	inline cry_engine::math::vector_2d screen{ 0.f, 0.f };
	bool world_to_screen(const cry_engine::math::vector& origin, cry_engine::math::vector& screen);

	inline cry_engine::cry_renderer::i_renderer* renderer;
}