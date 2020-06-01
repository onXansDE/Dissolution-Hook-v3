#include "Menus.h"
#include "Toggles.h"
#include "Vars.h"
#include "imgui.h"
#include "natives.hpp"
#include "script_global.hpp"
#include "fiber_pool.hpp"
#include <script.hpp>


namespace big {


	ImVec2 self_window_size = ImVec2(600, 400);
	ImVec2 self_mods_window = ImVec2(200, 240);

	void RMenus::render_self_menu() {
		if (show_self_menu) {
			ImGui::SetNextWindowSize(self_window_size, ImGuiCond_Once);
			if (ImGui::Begin("Self Options", &show_self_menu, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoScrollbar)) {
				if (ImGui::BeginTable("selfoptions1", 2)) {
					ImGui::TableNextRow();
					ImGui::Text("Quick Buttons");
					if (ImGui::BeginTable("selfquickbuttons", 2)) {
						ImGui::TableNextRow();
						if (ImGui::Button("Fix Player", default_button_size)) {
							QUEUE_JOB_BEGIN_CLAUSE() {
								ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), ENTITY::GET_ENTITY_MAX_HEALTH(PLAYER::PLAYER_PED_ID()), 1);
							}
							QUEUE_JOB_END_CLAUSE
						}
						ImGui::TableNextCell();
						if (ImGui::Button("Kill Player", default_button_size)) {
							ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 0, 1);
						}
						ImGui::TableNextCell();
						if (ImGui::Button("Offradar", default_button_size)) {
							*script_global(2424073 + 1 + PLAYER::PLAYER_ID() * 421 + 200).as<bool*>() = true;
							*script_global(2437549 + 70).as<int*>() = NETWORK::GET_NETWORK_TIME();
						}
						ImGui::TableNextCell();
						if (ImGui::Button("Clear Wanted", default_button_size)) {
							PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
						}
						ImGui::EndTable();
					}
					ImGui::TableNextCell();
					ImGui::Text("Quick Toggle");
					if (ImGui::BeginTable("selfquicktoggle", 2)) {
						ImGui::TableNextRow();
						ImGui::Checkbox("Godmode", &g_toggles.self_godmode);
						ImGui::TableNextCell();
						ImGui::Checkbox("Super Jump", &g_toggles.self_superjump);
						ImGui::TableNextCell();
						ImGui::Checkbox("No Ragdoll", &g_toggles.self_noragdoll);
						ImGui::TableNextCell();
						ImGui::Checkbox("Ignore Me", &g_toggles.self_ignoreme);


						ImGui::EndTable();
					}
					ImGui::EndTable();
				}
				ImGui::Separator();
				if (ImGui::BeginTable("selfoptions2", 3)) {
					ImGui::TableNextRow();
					ImGui::Text("Visuals");
					if (ImGui::BeginChild("selfvisuals", self_mods_window)) {
						ImGui::Checkbox("Invisble", &g_toggles.self_invisible);
						ImGui::Checkbox("Local Alpha", &g_toggles.self_alpha_enb);
						if (g_toggles.self_alpha_enb) {
							ImGui::SliderInt("##Alpha", &g_vars.self_alpha, 0, 255);
						}
						/*if (ImGui::Button("Random Clothing", long_button_size)) {

						}
						if (ImGui::Button("Ped Menu", long_button_size)) {

						}*/
						ImGui::EndChild();
					}
					ImGui::TableNextCell();
					ImGui::Text("Mods");
					if (ImGui::BeginChild("selfmods", self_mods_window)) {
						if (ImGui::CollapsingHeader("Common")) {
							ImGui::Checkbox("Godmode", &g_toggles.self_godmode);
							ImGui::Checkbox("No Ragdoll", &g_toggles.self_noragdoll);
							ImGui::Checkbox("Seatbelt", &g_toggles.self_seatbelt);
							ImGui::Checkbox("Offradar", &g_toggles.self_offradar);
							ImGui::Checkbox("Never Wanted", &g_toggles.self_nocops);

						}
						if (ImGui::CollapsingHeader("Movement")) {
							ImGui::Checkbox("Fast Run", &g_toggles.self_fastrun);
							if (g_toggles.self_fastrun) {
								ImGui::SliderFloat("Speed", &g_vars.self_fastrun_speed, 1.1f, 10.0f);
							}
							ImGui::Checkbox("Ultra Run", &g_toggles.self_ultrarun);
							if (g_toggles.self_ultrarun) {
								ImGui::SliderFloat("Speed ", &g_vars.self_ultrarun_speed, 0.1f, 5.0f);
							}
							ImGui::Checkbox("Fast Swim", &g_toggles.self_fastswim);
							if (g_toggles.self_fastswim) {
								ImGui::SliderFloat("Speed", &g_vars.self_fastswim_speed, 1.1f, 10.0f);
							}
							ImGui::Checkbox("Super Jump", &g_toggles.self_superjump);
							if (g_toggles.self_superjump) {
								ImGui::SliderFloat("Jump Force", &g_vars.self_ultrajump_force, 0.0f, 10.0f);
							}
							ImGui::Checkbox("Superman", &g_toggles.self_superman);
							ImGui::Checkbox("No Clip", &g_toggles.self_noclip);
						}
						if (ImGui::CollapsingHeader("Ignore")) {
							ImGui::Checkbox("Ignore Me", &g_toggles.self_ignoreme);
							ImGui::Checkbox("Cops Ignore", &g_toggles.self_nocops);
							ImGui::Checkbox("Gangs Ignore", &g_toggles.self_nogangs);
							ImGui::Checkbox("No Noise", &g_toggles.self_nonoise);
							if (g_toggles.self_nonoise) {
								ImGui::SliderFloat("Noise Ammount", &g_vars.self_nonoise_mult, 0.0f, 2.0f);
							}
							if (ImGui::SliderInt("Max Wanted", &g_vars.self_max_wanted_level, 0, 5)) {
								PLAYER::SET_MAX_WANTED_LEVEL(g_vars.self_max_wanted_level);
							}
						}
						ImGui::EndChild();
					}
					ImGui::TableNextCell();
					ImGui::Text("Protections");
					if (ImGui::BeginChild("selfprotections", self_mods_window)) {
						ImGui::Text("Soon...");
						ImGui::EndChild();
					}
					ImGui::EndTable();
				}
				ImGui::Separator();

			}
			ImGui::End();
		}
	}
}