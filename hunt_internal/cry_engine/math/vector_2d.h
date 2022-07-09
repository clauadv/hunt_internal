#pragma once

namespace cry_engine::math {
	class vector_2d {
	public:
		float x, y;

		inline cry_engine::math::vector_2d operator+(const cry_engine::math::vector_2d& a) const {
			return { x + a.x, y + a.y };
		}

		inline void operator+=(const cry_engine::math::vector_2d& a) {
			x += a.x, y += a.y;
		}

		inline cry_engine::math::vector_2d operator-(const cry_engine::math::vector_2d& a) const {
			return { x - a.x, y - a.y };
		}

		inline void operator-=(const cry_engine::math::vector_2d& a) {
			x -= a.x, y -= a.y;
		}

		inline cry_engine::math::vector_2d operator*(const cry_engine::math::vector_2d& a) const {
			return { x * a.x, y * a.y };
		}

		inline void operator*=(const cry_engine::math::vector_2d& a) {
			x *= a.x, y *= a.y;
		}

		inline cry_engine::math::vector_2d operator/(const cry_engine::math::vector_2d& a) const {
			return { x / a.x, y / a.y };
		}

		inline void operator/=(const cry_engine::math::vector_2d& a) {
			x /= a.x, y /= a.y;
		}

		inline cry_engine::math::vector_2d operator+(const float a) const {
			return { x + a, y + a };
		}

		inline void operator+=(const float a) {
			x += a, y += a;
		}

		inline cry_engine::math::vector_2d operator-(const float a) const {
			return { x - a, y - a };
		}

		inline void operator-=(const float a) {
			x -= a, y -= a;
		}

		inline cry_engine::math::vector_2d operator*(const float a) const {
			return { x * a, y * a };
		}

		inline void operator*=(const float a) {
			x *= a, y *= a;
		}

		inline cry_engine::math::vector_2d operator/(const float a) const {
			return { x / a, y / a };
		}

		inline void operator/=(const float a) {
			x /= a, y /= a;
		}

		bool is_zero() const {
			if (x == 0.f && y == 0.f) return true;

			return false;
		}
	};
}