#include "Menus.h"
#include "Toggles.h"
#include "Vars.h"
#include "imgui.h"
#include "natives.hpp"
#include "script_global.hpp"
#include "fiber_pool.hpp"

namespace big {

	ImVec2 visu_window_size = ImVec2(600, 400);
	void RMenus::render_visuals_menu() {
		if (show_visuals_menu) {
			ImGui::SetNextWindowSize(visu_window_size);
			if (ImGui::Begin("Visual Menu", &show_visuals_menu)) {
				if (ImGui::BeginTable("##visuals", 2)) {
					ImGui::TableNextRow();
					ImGui::Text("ESP");
					ImGui::BeginTable("##esp", 2);
					ImGui::TableNextRow();
					ImGui::Checkbox("Name Esp", &g_toggles.visu_name_esp);
					if (g_toggles.visu_name_esp) {
						ImGui::TableNextCell();
						ImGui::PushItemWidth(100);
						ImGui::SliderInt("Font", &g_vars.nameespfont, 0, 7);
						ImGui::TableNextCell();
						ImGui::Checkbox("Health", &g_toggles.visu_health_esp);
						ImGui::TableNextCell();
						ImGui::Checkbox("Friends", &g_toggles.visu_friend_esp);
						ImGui::TableNextCell();
						ImGui::Checkbox("Your Self", &g_toggles.visu_yourself_esp);
					}
					ImGui::TableNextRow();
					ImGui::Checkbox("Tracers", &g_toggles.visu_tracers);
					if (g_toggles.visu_tracers) {
						ImGui::TableNextCell();
						if (!g_toggles.visu_dynamic_tracer_alpha) {
							ImGui::ColorEdit4("Tracer Color", (float*)&g_vars.tracerColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoInputs);
						}
						else {
							ImGui::ColorEdit4("Tracer Color", (float*)&g_vars.tracerColor, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoAlpha);
						}
						ImGui::TableNextCell();
						ImGui::Checkbox("Dynamic Alpha", &g_toggles.visu_dynamic_tracer_alpha);

					}
					ImGui::Checkbox("Bone Esp", &g_toggles.visu_bone_esp);
					ImGui::EndTable();
					ImGui::TableNextCell();
					ImGui::Text("Others");
					ImGui::Checkbox("LASERPOINTER", &g_toggles.weps_laser_pointer);
					ImGui::EndTable();
				}
			}
			ImGui::End();
		}
	}
}