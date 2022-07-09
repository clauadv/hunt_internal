#include <includes.h>

void features::run() {
	const auto game_framework = cry_engine::cry_game::game_framework;
	if (!game_framework) return;

	const auto local_entity = game_framework->get_client_entity();
	if (!local_entity) return;

	const auto entity_system = cry_engine::cry_entity_system::entity_system;
	if (!entity_system) return;

	cry_engine::cry_entity_system::i_entity_it* entity_iterator{};
	entity_system->get_entity_iterator(&entity_iterator);
	if (!entity_iterator) return;

	entity_iterator->move_first();

	cry_engine::cry_entity_system::i_entity* entity = nullptr;
	while (!entity_iterator->is_end()) {
		entity = entity_iterator->next();
		if (entity == local_entity) continue;

		auto entity_class = entity->get_class();
		if (!entity_class) continue;

		const auto entity_class_name = entity_class->get_name();
		if (!entity_class_name) continue;

		features::esp::draw(local_entity, entity, entity_class);
	}
}