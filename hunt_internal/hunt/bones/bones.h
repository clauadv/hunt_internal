#pragma once

namespace hunt::bones {
	std::vector<std::pair<cry_engine::math::vector, cry_engine::math::vector>> get_array(cry_engine::cry_entity_system::i_entity* entity);
}