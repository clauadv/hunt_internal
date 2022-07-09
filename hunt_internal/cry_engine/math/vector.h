#pragma once

namespace cry_engine::math {
	class vector {
	public:
		float x, y, z;

		inline cry_engine::math::vector operator+(const cry_engine::math::vector& a) const {
			return { x + a.x, y + a.y, z + a.z };
		}

		inline void operator+=(const cry_engine::math::vector& a) {
			x += a.x, y += a.y, z += a.z;
		}

		inline cry_engine::math::vector operator-(const cry_engine::math::vector& a) const {
			return { x - a.x, y - a.y, z - a.z };
		}

		inline void operator-=(const cry_engine::math::vector& a) {
			x -= a.x, y -= a.y, z -= a.z;
		}

		inline cry_engine::math::vector operator*(const cry_engine::math::vector& a) const {
			return { x * a.x, y * a.y, z * a.z };
		}

		inline void operator*=(const cry_engine::math::vector& a) {
			x *= a.x, y *= a.y, z *= a.z;
		}

		inline cry_engine::math::vector operator/(const cry_engine::math::vector& a) const {
			return { x / a.x, y / a.y, z / a.z };
		}

		inline void operator/=(const cry_engine::math::vector& a) {
			x /= a.x, y /= a.y, z /= a.z;
		}

		inline cry_engine::math::vector operator+(const float a) const {
			return { x + a, y + a, z + a };
		}

		inline void operator+=(const float a) {
			x += a, y += a, z += a;
		}

		inline cry_engine::math::vector operator-(const float a) const {
			return { x - a, y - a, z - a };
		}

		inline void operator-=(const float a) {
			x -= a, y -= a, z -= a;
		}

		inline cry_engine::math::vector operator*(const float a) const {
			return { x * a, y * a, z * a };
		}

		inline void operator*=(const float a) {
			x *= a, y *= a, z *= a;
		}

		inline cry_engine::math::vector operator/(const float a) const {
			return { x / a, y / a, z / a };
		}

		inline void operator/=(const float a) {
			x /= a, y /= a, z /= a;
		}

		inline float distance_to(cry_engine::math::vector entity) {
			cry_engine::math::vector delta{};

			delta.x = this->x - entity.x;
			delta.y = this->y - entity.y;
			delta.z = this->z - entity.z;

			return std::sqrt(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z);
		}
	};
}