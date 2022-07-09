#include <includes.h>

float cry_engine::cry_entity_system::i_entity::get_distance_to(cry_engine::cry_entity_system::i_entity* entity) {
	auto local_position = this->get_position();
	const auto& entity_position = entity->get_position();

	return local_position.distance_to(entity_position);
}

std::string cry_engine::cry_entity_system::i_entity::get_distance_to_string(cry_engine::cry_entity_system::i_entity* entity) {
	const auto distance = this->get_distance_to(entity);

	std::stringstream ss;
	if (distance < 1000.f) {
		ss << std::fixed << std::setprecision(0) << distance << _("m");

	} else {
		ss.precision(3);
		ss << std::fixed << std::setprecision(0) << (distance / 1000.f) << _("km");
	}

	return ss.str();
}

std::tuple<std::string, ImColor, float> cry_engine::cry_entity_system::i_entity_class::get_entity_name(std::string distance) {
	const auto get_name = this->get_name();
	std::string name(get_name);

	if (name.contains(_("HunterBasic")) && variables::entities::hunter) {
		auto color = ImColor(
			variables::entities::hunter_color[0],
			variables::entities::hunter_color[1],
			variables::entities::hunter_color[2],
			variables::entities::hunter_color[3]
		);

		std::string text;
		text.append(_("hunter [")).append(distance).append(_("]"));

		return { text, color, variables::entities::max_distance };
	}

	if (name.contains(_("grunt_base")) && variables::entities::zombie) {
		auto color = ImColor(
			variables::entities::zombie_color[0],
			variables::entities::zombie_color[1],
			variables::entities::zombie_color[2],
			variables::entities::zombie_color[3]
		);

		std::string text;
		text.append(_("zombie [")).append(distance).append(_("]"));

		return { text, color, variables::entities::max_distance };
	}

	if (name.contains(_("target_butcher")) && variables::entities::boss_zombie) {
		auto color = ImColor(
			variables::entities::boss_zombie_color[0],
			variables::entities::boss_zombie_color[1],
			variables::entities::boss_zombie_color[2],
			variables::entities::boss_zombie_color[3]
		);

		std::string text;
		text.append(_("butcher [")).append(distance).append(_("]"));

		return { text, color, variables::entities::max_distance };
	}


	if (name.contains(_("Clue_Base")) && variables::entities::clue) {
		auto color = ImColor(
			variables::entities::clue_color[0],
			variables::entities::clue_color[1],
			variables::entities::clue_color[2],
			variables::entities::clue_color[3]
		);

		std::string text;
		text.append(_("clue [")).append(distance).append(_("]"));

		return { text, color, variables::entities::max_distance };
	}

	if (name.contains(_("ExtractionPoint")) && variables::entities::extraction) {
		auto color = ImColor(
			variables::entities::extraction_color[0],
			variables::entities::extraction_color[1],
			variables::entities::extraction_color[2],
			variables::entities::extraction_color[3]
		);

		std::string text;
		text.append(_("extraction [")).append(distance).append(_("]"));

		return { text, color, variables::entities::max_distance };
	}

	return { "", { 0.f, 0.f, 0.f, 0.f}, 0.f };
}

cry_engine::math::vector cry_engine::cry_entity_system::i_entity::get_bone_position(std::int64_t bone_id) {
	const auto character = this->get_character();
	if (!character) return { 0.f, 0.f, 0.f };

	const auto skeleton_pose = character->get_skeleton_pose();
	if (!skeleton_pose) return { 0.f, 0.f, 0.f };

	return (this->get_world_tm() * skeleton_pose->get_abs_joint_by_id(bone_id)).get_translation();
}

cry_engine::math::vector cry_engine::cry_entity_system::i_entity::get_bone_position(const char* bone_name) {
	std::int64_t bone = this->get_character()->get_default_skeleton().get_joint_id_by_name(bone_name);
	return get_bone_position(bone);
}

void cry_engine::cry_entity_system::i_entity::dump_bones() {
	const auto character = this->get_character(0);
	if (!character) return;

	const auto skeleton_pose = character->get_skeleton_pose();
	if (!skeleton_pose) return;

	auto& skeleton = character->get_default_skeleton();

	for (auto i = 0; i < skeleton.get_joint_count(); i++) {
		std::string bone_name = skeleton.get_joint_name_by_id(i);
		std::ranges::transform(bone_name.begin(), bone_name.end(), bone_name.begin(), ::tolower);

		std::cout << bone_name << " = " << i << "," << std::endl;
	}
}