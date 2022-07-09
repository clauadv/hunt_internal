#pragma once

namespace features {
	void run();
}

namespace features::esp {
	void draw(cry_engine::cry_entity_system::i_entity* local_entity, cry_engine::cry_entity_system::i_entity* entity, cry_engine::cry_entity_system::i_entity_class* entity_class);
}