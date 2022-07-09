#include <includes.h>

void features::esp::draw(cry_engine::cry_entity_system::i_entity* local_entity, cry_engine::cry_entity_system::i_entity* entity, cry_engine::cry_entity_system::i_entity_class* entity_class) {
	const auto distance = local_entity->get_distance_to(entity);
	const auto distance_string = local_entity->get_distance_to_string(entity);

	const auto entity_name = entity_class->get_entity_name(distance_string);
	const auto& entity_position = entity->get_position();

	// draw name
	{
		if (distance > std::get<2>(entity_name)) return;

		cry_engine::math::vector screen{};
		if (cry_engine::cry_renderer::world_to_screen(entity_position, screen)) {
			const auto text_size = ImGui::CalcTextSize(std::get<0>(entity_name).c_str());
			ImGui::GetOverlayDrawList()->AddText(ImVec2(screen.x - (text_size.x / 2.f), screen.y), std::get<1>(entity_name), std::get<0>(entity_name).c_str());
		}
	}

	// draw skeleton
	{
		for (const auto& bone : hunt::bones::get_array(entity)) {
			cry_engine::math::vector first_bone{}, second_bone{};

			if (cry_engine::cry_renderer::world_to_screen(bone.first, first_bone) && cry_engine::cry_renderer::world_to_screen(bone.second, second_bone)) {
				ImGui::GetOverlayDrawList()->AddLine({ first_bone.x, first_bone.y }, { second_bone.x, second_bone.y }, ImGui::ColorConvertFloat4ToU32(ImVec4(1.f, 1.f, 1.f, 1.f)));
			}
		}
	}
}