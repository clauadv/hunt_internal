#include <includes.h>
#include "../hooks/hooks.h"

bool cry_engine::sdk::initialize() {
	const auto main = reinterpret_cast<std::uintptr_t>(LI_FN(GetModuleHandleA)(nullptr));
	if (!main) throw std::runtime_error(_("failed to get main handle"));

	cry_engine::cry_game::game_framework = *reinterpret_cast<cry_engine::cry_game::i_game_framework**>(utils::pattern_scan(main, _("48 8B 0D ? ? ? ? 48 8B 01 FF 90 ? ? ? ? 48 8B 54 24 38 4C 8D 4C 24 20 4C 8D 05 ? ? ? ? 48 8B C8 4C 8B 10 41 FF 52 ? 48 8D 4C 24 20"), true));
	if (!cry_engine::cry_game::game_framework) throw std::runtime_error(_("failed to get cry_engine::cry_game::game_framework"));

	cry_engine::cry_entity_system::entity_system = *reinterpret_cast<cry_engine::cry_entity_system::i_entity_system**>(utils::pattern_scan(main, _("48 8B 0D ? ? ? ? 48 8D 15 ? ? ? ? 48 8B 01 FF 50 ? 48 8B D8 48 85 C0 0F 84 90"), true));
	if (!cry_engine::cry_entity_system::entity_system) throw std::runtime_error(_("failed to get cry_engine::cry_entity_system::entity_system"));

	cry_engine::cry_renderer::renderer = *reinterpret_cast<cry_engine::cry_renderer::i_renderer**>(utils::pattern_scan(main, _("48 8B 0D ? ? ? ? 48 89 BC 24 90 ? ? ? 0F 29 B4 24"), true));
	if (!cry_engine::cry_renderer::renderer) throw std::runtime_error(_("failed to get cry_engine::cry_renderer::renderer"));

	return true;
}
