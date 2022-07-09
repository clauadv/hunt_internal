#pragma once

namespace cry_engine::cry_entity_system {
	class i_entity_it {
	public:
		bool is_end() {
			return cry_engine::sdk::call<3, bool>(this);
		}

		cry_engine::cry_entity_system::i_entity* next() {
			return cry_engine::sdk::call<4, cry_engine::cry_entity_system::i_entity*>(this);
		}

		void move_first() {
			return cry_engine::sdk::call<6, void>(this);
		}
	};

	class i_entity_system {
	public:
		void get_entity_iterator(cry_engine::cry_entity_system::i_entity_it** it) {
			return cry_engine::sdk::call<19, void>(this, it);
		}
	};

	inline cry_engine::cry_entity_system::i_entity_system* entity_system;
}