#include "Menus.h"
#include "Toggles.h"
#include "Vars.h"
#include "imgui.h"
#include "natives.hpp"
#include "script_global.hpp"
#include "fiber_pool.hpp"

namespace big {

	ImVec2 worl_window_size = ImVec2(600, 400);

	void RMenus::render_world_menu() {
		if (g_menus.show_world_menu) {
			ImGui::SetNextWindowSize(worl_window_size, ImGuiCond_Once);
			if (ImGui::Begin("World Menu", &g_menus.show_world_menu, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollWithMouse)) {
				if (ImGui::BeginTable("worldquicks", 2)) {
					ImGui::TableNextRow();
					if (ImGui::BeginTable("quickbuttons", 2)) {
						ImGui::TableNextRow();
						if (ImGui::Button("DAY/NIGHT", default_button_size)) {

						}
						ImGui::TableNextCell();
						if (ImGui::Button("Winter", default_button_size)) {

						}
						ImGui::TableNextCell();
						if (ImGui::Button("Clear Peds", default_button_size)) {
						}
						ImGui::TableNextCell();
						if (ImGui::Button("Clear Vehicles", default_button_size)) {

						}
						ImGui::EndTable();
					}
					ImGui::TableNextCell();

					if (ImGui::BeginTable("quicktoggles", 2)) {
						ImGui::TableNextRow();
						ImGui::Checkbox("Sync Time", &g_toggles.world_sync_time);
						ImGui::TableNextCell();
						ImGui::Checkbox("Frezze Time", &g_toggles.world_frezze_time);
						ImGui::TableNextCell();
						ImGui::Checkbox("No Cars", &g_toggles.world_no_cars);
						ImGui::TableNextCell();
						ImGui::Checkbox("Calm Peds", &g_toggles.world_calm_peds);
						ImGui::EndTable();
					}
					ImGui::EndTable();
				}
			}

			ImGui::End();
		}
	}
}