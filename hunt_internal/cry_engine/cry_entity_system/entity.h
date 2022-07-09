#pragma once

namespace cry_engine::cry_entity_system {
	class i_entity_class {
	public:
		const char* get_name() {
			return cry_engine::sdk::call<2, const char*>(this);
		}

		std::tuple<std::string, ImColor, float> get_entity_name(std::string distance);
	};

	class i_entity {
	public:
		cry_engine::cry_entity_system::i_entity_class* get_class() {
			return cry_engine::sdk::call<3, cry_engine::cry_entity_system::i_entity_class*>(this);
		}

		const char* get_name() {
			return cry_engine::sdk::call<16, const char*>(this);
		}

		cry_engine::math::matrix& get_world_tm() {
			return cry_engine::sdk::call<31, cry_engine::math::matrix&>(this);
		}

		cry_engine::math::vector& get_position() {
			return cry_engine::sdk::call<38, cry_engine::math::vector&>(this);
		}
		
		cry_engine::cry_animation::i_character_instance* get_character(int slot = 0) {
			return cry_engine::sdk::call<122, cry_engine::cry_animation::i_character_instance*>(this, slot);
		}

		float get_distance_to(cry_engine::cry_entity_system::i_entity* entity);
		std::string get_distance_to_string(cry_engine::cry_entity_system::i_entity* entity);
		cry_engine::math::vector get_bone_position(std::int64_t bone_id);
		cry_engine::math::vector get_bone_position(const char* bone_name);
		void dump_bones();
	};
}