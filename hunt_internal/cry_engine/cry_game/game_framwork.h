#pragma once

namespace cry_engine::cry_entity_system {
	class i_entity;
}

namespace cry_engine::cry_game {
	class i_game_framework {
	public:
		cry_engine::cry_entity_system::i_entity* get_client_entity() {
			return cry_engine::sdk::call<71, cry_engine::cry_entity_system::i_entity*>(this);
		}
	};

	inline cry_engine::cry_game::i_game_framework* game_framework;
}