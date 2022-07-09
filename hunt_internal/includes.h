#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>
#include <iomanip>
#include <list>
#include <sstream>
#include <mutex>
#include <utility>
#include <cstdint>
#include <future>
#include <array>
#include <d3d11.h>

#include "utils/utils.h"
#include "utils/libraries/minhook/include/MinHook.h"
#include "utils/libraries/lazy_importer/include/lazy_importer.hpp"
#include "utils/libraries/xor.h"

#include "utils/libraries/imgui/imgui.h"
#include "utils/libraries/imgui/imgui_impl_dx11.h"
#include "utils/libraries/imgui/imgui_impl_win32.h"
#include "utils/libraries/imgui/imgui_internal.h"

#include "cry_engine/sdk.h"

#include "cry_engine/math/vector.h"
#include "cry_engine/math/vector_2d.h"
#include "cry_engine/math/quat.h"
#include "cry_engine/math/matrix.h"

#include "cry_engine/cry_game/game_framwork.h"
#include "cry_engine/cry_animation/cry_animation.h"
#include "cry_engine/cry_entity_system/entity_system.h"
#include "cry_engine/cry_entity_system/entity.h"
#include "cry_engine/cry_renderer/renderer.h"

#include "features/features.h"
#include "menu/d3d11/d3d11.h"
#include "menu/menu.h"

#include "hunt/bones/bones.h"