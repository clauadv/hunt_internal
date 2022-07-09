#include <includes.h>

std::vector<std::pair<cry_engine::math::vector, cry_engine::math::vector>> hunt::bones::get_array(cry_engine::cry_entity_system::i_entity* entity) {
	const auto character = entity->get_character();
	if (!character) return {};

	std::vector<std::pair<cry_engine::math::vector, cry_engine::math::vector>> bone;

	const auto head = entity->get_bone_position(_("head"));
	const auto neck = entity->get_bone_position(_("neck"));
	const auto pelvis = entity->get_bone_position(_("pelvis"));

	bone.emplace_back(std::make_pair(head, neck));
	bone.emplace_back(std::make_pair(neck, pelvis));

	// right upper body
	{
		const auto r_upperarm = entity->get_bone_position(_("r_upperarm"));
		const auto r_forearm = entity->get_bone_position(_("r_forearm"));
		const auto r_hand = entity->get_bone_position(_("r_hand"));

		bone.emplace_back(std::make_pair(neck, r_upperarm));
		bone.emplace_back(std::make_pair(r_upperarm, r_forearm));
		bone.emplace_back(std::make_pair(r_forearm, r_hand));
	}

	// right lower body
	{
		const auto r_thigh = entity->get_bone_position(_("r_thigh"));
		const auto r_calf = entity->get_bone_position(_("r_calf"));
		const auto r_foot = entity->get_bone_position(_("r_foot"));

		bone.emplace_back(std::make_pair(pelvis, r_thigh));
		bone.emplace_back(std::make_pair(r_thigh, r_calf));
		bone.emplace_back(std::make_pair(r_calf, r_foot));
	}

	// left upper body
	{
		const auto l_upperarm = entity->get_bone_position(_("l_upperarm"));
		const auto l_forearm = entity->get_bone_position(_("l_forearm"));
		const auto l_hand = entity->get_bone_position(_("l_hand"));

		bone.emplace_back(std::make_pair(neck, l_upperarm));
		bone.emplace_back(std::make_pair(l_upperarm, l_forearm));
		bone.emplace_back(std::make_pair(l_forearm, l_hand));
	}

	// left lower body
	{
		const auto l_thigh = entity->get_bone_position(_("l_thigh"));
		const auto l_calf = entity->get_bone_position(_("l_calf"));
		const auto l_foot = entity->get_bone_position(_("l_foot"));

		bone.emplace_back(std::make_pair(pelvis, l_thigh));
		bone.emplace_back(std::make_pair(l_thigh, l_calf));
		bone.emplace_back(std::make_pair(l_calf, l_foot));
	}

	return bone;
}