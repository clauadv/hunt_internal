#include <includes.h>
#include "hooks.h"

bool hooks::initialize() {
	if (MH_Initialize() != MH_OK) throw std::runtime_error(_("failed to initialize min_hook"));

	if (d3d11::initialize()) {
		if (MH_CreateHook(reinterpret_cast<void*>(d3d11::get_present()), &hooks::present::hook, reinterpret_cast<void**>(&hooks::present::original)) != MH_OK) {
			throw std::runtime_error(_("failed to hook present"));
		}
	}

	if (MH_EnableHook(nullptr) != MH_OK) throw std::runtime_error(_("failed to initialize hooks"));

	return true;
}

bool hooks::release() {
	MH_Uninitialize();

	MH_DisableHook(nullptr);
	MH_RemoveHook(nullptr);

	utils::console::release();

	return true;
}