#include "Menus.h";
#include "Functions.h";
#include <imgui.h>
namespace big {

	ImVec2 main_window_size = ImVec2(210, 400);
	ImVec2 main_menu_button_size = ImVec2(110, 25);


	void RMenus::render_main_menu() {
		ImGui::SetNextWindowSize(main_window_size);
		if (ImGui::Begin("Dissolution Hook v3", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_MenuBar))
		{
			if (ImGui::BeginMenuBar()) {
				if (ImGui::BeginMenu("Configs")) {
					ImGui::MenuItem("Save");
					ImGui::MenuItem("Load");
					ImGui::MenuItem("Load Recent");
					ImGui::MenuItem("Manage");
					ImGui::EndMenu();
				}
				if (ImGui::BeginMenu("Tools")) {
					if (ImGui::MenuItem("Themes")) {
						if (g_menus.show_theme_menu) {
							g_menus.show_theme_menu = false;
						}
						else {
							g_menus.show_theme_menu = true;
						}
					}
					if (ImGui::MenuItem("Quick Unlock All")) {
						g_c_functions.UnlockAll();
						g_c_functions.SetRank(432);
					}
					ImGui::MenuItem("Saved Colors");
					ImGui::MenuItem("Options");
					ImGui::MenuItem("Console");
					if (ImGui::MenuItem("Debug")) {
						if (g_menus.show_debug_menu) {
							g_menus.show_debug_menu = false;
						}
						else {
							g_menus.show_debug_menu = true;
						}
					}
					ImGui::MenuItem("Log");
					if (ImGui::MenuItem("Unload")) {
						g_running = false;
					}
					ImGui::EndMenu();
				}
				if (ImGui::BeginMenu("Help")) {
					if (ImGui::MenuItem("My Discord")) {
						system("start https://discord.gg/qcZxkrz");
					}
					ImGui::EndMenu();
				}
				ImGui::EndMenuBar();
				ImGui::Spacing();
				ImGui::Separator();

				int currentwidth = ImGui::GetWindowSize().x;
				int nextwidth = (currentwidth - main_menu_button_size.x) / 2;
				ImGui::SameLine(nextwidth);
				ImGui::Text("Made by onXan#1772");
				ImGui::Text("Mods");
				ImGui::Spacing();
				ImGui::SameLine(nextwidth);
				if (ImGui::BeginTable("menutable", 1)) {
					ImGui::TableNextRow();
					if (ImGui::Button("Self", main_menu_button_size)) {
						if (g_menus.show_self_menu) {
							g_menus.show_self_menu = false;
						}
						else {
							g_menus.show_self_menu = true;
						}
					}
					ImGui::TableNextRow();
					if (ImGui::Button("Network", main_menu_button_size)) {
						if (g_menus.show_network_menu) {
							g_menus.show_network_menu = false;
						}
						else {
							g_menus.show_network_menu = true;
						}
					}
					ImGui::TableNextRow();
					if (ImGui::Button("World", main_menu_button_size)) {
						if (g_menus.show_world_menu) {
							g_menus.show_world_menu = false;
						}
						else {
							g_menus.show_world_menu = true;
						}
					}
					ImGui::TableNextRow();
					if (ImGui::Button("Vehicle", main_menu_button_size)) {
						if (g_menus.show_vehicle_menu) {
							g_menus.show_vehicle_menu = false;
						}
						else {
							g_menus.show_vehicle_menu = true;
						}
					}
					ImGui::TableNextRow();
					if (ImGui::Button("Recovery", main_menu_button_size)) {
						if (g_menus.show_recovery_menu) {
							g_menus.show_recovery_menu = false;
						}
						else {
							g_menus.show_recovery_menu = true;
						}
					}
					ImGui::TableNextRow();
					if (ImGui::Button("Weapons", main_menu_button_size)) {
						if (g_menus.show_weapon_menu) {
							g_menus.show_weapon_menu = false;
						}
						else {
							g_menus.show_weapon_menu = true;
						}
					}
					ImGui::TableNextRow();
					if (ImGui::Button("Visuals", main_menu_button_size)) {
						if (g_menus.show_visuals_menu) {
							g_menus.show_visuals_menu = false;
						}
						else {
							g_menus.show_visuals_menu = true;
						}
					}
					ImGui::EndTable();
				}

			}
		}
		ImGui::End();
	}
}