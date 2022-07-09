#pragma once

namespace cry_engine::cry_animation {
	class i_skeleton_pose {
	public:
		cry_engine::math::quat_t& get_abs_joint_by_id(std::uint32_t joint_id) {
			return cry_engine::sdk::call<24, cry_engine::math::quat_t&>(this, joint_id);
		}

		cry_engine::math::quat_t& get_rel_joint_by_id(std::uint32_t joint_id) {
			return cry_engine::sdk::call<25, cry_engine::math::quat_t&>(this, joint_id);
		}
	};

	class i_default_skeleton {
	public:
		std::uint32_t get_joint_count() {
			return cry_engine::sdk::call<1, std::uint32_t>(this);
		}

		const char* get_joint_name_by_id(std::int32_t id) {
			return cry_engine::sdk::call<8, const char*>(this, id);
		}

		std::int32_t get_joint_id_by_name(const char* name) {
			return cry_engine::sdk::call<9, std::int32_t>(this, name);
		}
	};

	class i_character_instance {
	public:
		cry_engine::cry_animation::i_skeleton_pose* get_skeleton_pose() {
			return cry_engine::sdk::call<16, cry_engine::cry_animation::i_skeleton_pose*>(this);
		}

		cry_engine::cry_animation::i_default_skeleton& get_default_skeleton() {
			return cry_engine::sdk::call<20, cry_engine::cry_animation::i_default_skeleton&>(this);
		}
	};
}