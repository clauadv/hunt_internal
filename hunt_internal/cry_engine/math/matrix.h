#pragma once

namespace cry_engine::math {
	struct matrix {
		float m00, m01, m02, m03;
		float m10, m11, m12, m13;
		float m20, m21, m22, m23;

		matrix() {
			m00 = 1;
			m01 = 0;
			m02 = 0;
			m03 = 0;
			m10 = 0;
			m11 = 1;
			m12 = 0;
			m13 = 0;
			m20 = 0;
			m21 = 0;
			m22 = 1;
			m23 = 0;
		}

		matrix(const cry_engine::math::quat_t& q) {
			cry_engine::math::vector v2{};
			v2.x = (q.q.v.x) + (q.q.v.x);

			float xx = 1 - v2.x * q.q.v.x; 
			float yy = v2.y * q.q.v.y; 
			float xw = v2.x * q.q.w;
			float xy = v2.y * q.q.v.x;   
			float yz = v2.z * q.q.v.y; 
			float yw = v2.y * q.q.w;
			float xz = v2.z * q.q.v.x;   
			float zz = v2.z * q.q.v.z; 
			float zw = v2.z * q.q.w;

			m00 = float(1 - yy - zz);     
			m01 = float(xy - zw);     
			m02 = float(xz + yw);   
			m03 = float(q.t.x);
			m10 = float(xy + zw);      
			m11 = float(xx - zz);     
			m12 = float(yz - xw);   
			m13 = float(q.t.y);
			m20 = float(xz - yw);      
			m21 = float(yz + xw);     
			m22 = float(xx - yy);   
			m23 = float(q.t.z);
		}

		cry_engine::math::vector get_translation() {
			cry_engine::math::vector mf{};

			mf.x = m03; 
			mf.y = m13; 
			mf.z = m23; 
			
			return mf;
		}
	};

	inline cry_engine::math::matrix operator*(const cry_engine::math::matrix& l, const cry_engine::math::matrix& r) {
		cry_engine::math::matrix m;

		m.m00 = l.m00 * r.m00 + l.m01 * r.m10 + l.m02 * r.m20;
		m.m10 = l.m10 * r.m00 + l.m11 * r.m10 + l.m12 * r.m20;
		m.m20 = l.m20 * r.m00 + l.m21 * r.m10 + l.m22 * r.m20;
		m.m01 = l.m00 * r.m01 + l.m01 * r.m11 + l.m02 * r.m21;
		m.m11 = l.m10 * r.m01 + l.m11 * r.m11 + l.m12 * r.m21;
		m.m21 = l.m20 * r.m01 + l.m21 * r.m11 + l.m22 * r.m21;
		m.m02 = l.m00 * r.m02 + l.m01 * r.m12 + l.m02 * r.m22;
		m.m12 = l.m10 * r.m02 + l.m11 * r.m12 + l.m12 * r.m22;
		m.m22 = l.m20 * r.m02 + l.m21 * r.m12 + l.m22 * r.m22;
		m.m03 = l.m00 * r.m03 + l.m01 * r.m13 + l.m02 * r.m23 + l.m03;
		m.m13 = l.m10 * r.m03 + l.m11 * r.m13 + l.m12 * r.m23 + l.m13;
		m.m23 = l.m20 * r.m03 + l.m21 * r.m13 + l.m22 * r.m23 + l.m23;

		return m;
	}
}