#pragma once

namespace cry_engine::math {
	class quat {
	public:
		cry_engine::math::vector v;
		float w;

		friend float operator|(const cry_engine::math::quat& q, const cry_engine::math::quat& p) {
			return (q.v.x * p.v.x + q.v.y * p.v.y + q.v.z * p.v.z + q.w * p.w);
		}

		friend cry_engine::math::quat operator-(const cry_engine::math::quat& q, const cry_engine::math::quat& p) {
			cry_engine::math::quat ret{};
			ret.w = q.w - p.w;

			ret.v.x = q.v.x - p.v.x;
			ret.v.y = q.v.y - p.v.y;
			ret.v.z = q.v.z - p.v.z;

			return ret;
		}
	};

	class quat_t {
	public:
		cry_engine::math::quat q;
		cry_engine::math::vector t;
	};
}