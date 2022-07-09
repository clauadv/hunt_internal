#include <includes.h>

bool cry_engine::cry_renderer::world_to_screen(const cry_engine::math::vector& origin, cry_engine::math::vector& screen) {
	float x, y, z;

	cry_engine::cry_renderer::renderer->project_to_screen(origin.x, origin.y, origin.z, &x, &y, &z);

	screen.x = x * cry_engine::cry_renderer::screen.x * 0.01f;
	screen.y = y * cry_engine::cry_renderer::screen.y * 0.01f;
	screen.z = z * 1.0f;

	return (screen.z < 1.0f);
}