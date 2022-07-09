#pragma once

namespace cry_engine::sdk {
	bool initialize();

	template <std::size_t index, typename return_type, typename... args>
	__forceinline return_type call(void* instance, args... _args) {
		using fn = return_type(__thiscall*)(void*, args...);

		auto function = (*reinterpret_cast<fn**>(instance))[index];
		return function(instance, _args...);
	}
}