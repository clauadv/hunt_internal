#include <includes.h>
#include "hooks/hooks.h"

bool menu::initialize() {
	ImGui::CreateContext();
	ImGui_ImplWin32_Init(hooks::window);
	ImGui_ImplDX11_Init(d3d11::device, d3d11::context);

	auto& io = ImGui::GetIO();
	io.IniFilename = nullptr;
	io.LogFilename = nullptr;
	io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;

	ImGui::StyleColorsDark();

	auto& style = ImGui::GetStyle();
	style.ScrollbarSize = 13.0f;
	style.WindowTitleAlign = ImVec2{ 0.5f, 0.5f };
	style.WindowRounding = 6.f;

	return true;
}

void menu::render() {
	auto& style = ImGui::GetStyle();
	auto& io = ImGui::GetIO();
	io.MouseDrawCursor = variables::menu::opened;

	static float alpha = 0.f;

	const auto& draw_list = ImGui::GetBackgroundDrawList();
	draw_list->AddRectFilled(ImVec2{ 0.f, 0.f }, io.DisplaySize, ImColor{ 0.f, 0.f, 0.f, alpha });

	if (!variables::menu::opened) {
		alpha = std::fmax(alpha - io.DeltaTime * 3.0f, 0.f);
		style.Alpha = std::fmax(style.Alpha - io.DeltaTime * 6.0f, 0.f);
		return;
	}

	alpha = std::fmin(alpha + io.DeltaTime * 3.0f, 0.5f);
	style.Alpha = std::fmin(style.Alpha + io.DeltaTime * 6.0f, 1.f);

	ImGui::SetNextWindowSize(ImVec2{ 500.f, 412.f }, ImGuiCond_Once);
	ImGui::Begin(_("papusa barbie"), nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);

	ImVec2 p0 = ImGui::GetCursorScreenPos();
	ImGui::SetCursorScreenPos({ p0.x + 80.f, p0.y });

	ImGui::BeginGroup();
	{
		ImGui::Checkbox(_("hunter"), &variables::entities::hunter);
		ImGui::SameLine();
		ImGui::ColorEdit4((_("##hunter_color")), variables::entities::hunter_color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

		ImGui::Checkbox(_("zombie"), &variables::entities::zombie);
		ImGui::SameLine();
		ImGui::ColorEdit4((_("##zombie_color")), variables::entities::zombie_color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

		ImGui::Checkbox(_("boss zombie"), &variables::entities::boss_zombie);
		ImGui::SameLine();
		ImGui::ColorEdit4((_("##boss_zombie_color")), variables::entities::boss_zombie_color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

		ImGui::Checkbox(_("clue"), &variables::entities::clue);
		ImGui::SameLine();
		ImGui::ColorEdit4((_("##clue_color")), variables::entities::clue_color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

		ImGui::Checkbox(_("extraction"), &variables::entities::extraction);
		ImGui::SameLine();
		ImGui::ColorEdit4((_("##extraction_color")), variables::entities::extraction_color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_AlphaBar);

		ImGui::Spacing();
		ImGui::Spacing();

		ImGui::Text(_("max distance"));
		ImGui::SliderFloat(_("##max_distance"), &variables::entities::max_distance, 0.f, 500.f, _("%.3gm"), 1.f);
	} 
	ImGui::EndGroup();

	ImGui::End();
}