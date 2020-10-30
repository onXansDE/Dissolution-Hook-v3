#include "Menus.h"
#include "Functions.h"
#include "Toggles.h"
#include "Vars.h"
#include "imgui.h"
#include "natives.hpp"
#include "script_global.hpp"
#include "fiber_pool.hpp"

namespace big {


	ImVec2 netw_window_size = ImVec2(600, 400);
	ImVec2 netw_player_window = ImVec2(200, 240);

	void RMenus::render_network_menu() {
		if (g_menus.show_network_menu) {
			ImGui::SetNextWindowSize(netw_window_size, ImGuiCond_Once);
			if (ImGui::Begin("Network Options", &g_menus.show_network_menu, ImGuiWindowFlags_NoResize)) {
				if (ImGui::BeginTabBar("Network")) {
					ImGui::Text("Online Players: %i", g_c_functions.playerCount);
					if (ImGui::BeginTabItem("Playerlist", NULL)) {
						ImGui::Text("Playerlist");
						if (ImGui::BeginTable("##playerlist", 11, ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable)) {
							ImGui::TableSetupColumn("Name", ImGuiTableColumnFlags_NoHide);
							ImGui::TableSetupColumn("Health", ImGuiTableColumnFlags_None);
							ImGui::TableSetupColumn("Wanted", ImGuiTableColumnFlags_None);
							ImGui::TableSetupColumn("Vehicle", ImGuiTableColumnFlags_None);
							ImGui::TableSetupColumn("Distance", ImGuiTableColumnFlags_None);
							ImGui::TableSetupColumn("Godmode", ImGuiTableColumnFlags_None);
							ImGui::TableSetupColumn("In Building", ImGuiTableColumnFlags_None);
							ImGui::TableSetupColumn("Street", ImGuiTableColumnFlags_DefaultHide);
							ImGui::TableSetupColumn("Zone", ImGuiTableColumnFlags_DefaultHide);
							ImGui::TableSetupColumn("In Cutscene", ImGuiTableColumnFlags_DefaultHide);
							ImGui::TableSetupColumn("SCID", ImGuiTableColumnFlags_DefaultHide);
							ImGui::TableAutoHeaders();

							for (CFunctions::NPlayer p : g_c_functions.players) {
								if (p.name != "NOTCONNECTED") {
									ImGui::TableNextRow();
									ImGui::TableSetColumnIndex(0);
									ImGui::Text(p.name.c_str());
									ImGui::TableSetColumnIndex(1);
									ImGui::Text("%i/%i HP",p.health,p.maxHealth);
									ImGui::TableSetColumnIndex(2);
									ImGui::Text("%i/5", p.wantedLevel);
									ImGui::TableSetColumnIndex(3);
									if (p.isInVehicle) {
										ImGui::Text("%s", p.vehicleName.c_str());
									}
									else {
										ImGui::Text("Running");
									}
									ImGui::TableSetColumnIndex(4);
									float distance = g_c_functions.get_distance(&p.position, &g_c_functions.myCords);
									ImGui::Text("%i m", (int) distance);
									ImGui::TableSetColumnIndex(5);
									if (p.isInvincible) {
										ImGui::Text("YES");
									}
									else {
										ImGui::Text("NO");
									}
									ImGui::TableSetColumnIndex(6);
									if (p.inInterior) {
										ImGui::Text("YES");
									}
									else {
										ImGui::Text("NO");
									}
									ImGui::TableSetColumnIndex(7);
									ImGui::Text("%s", p.streetname.c_str());
									ImGui::TableSetColumnIndex(8);
									ImGui::Text("%s", p.zonename.c_str());
									ImGui::TableSetColumnIndex(9);
									if (p.inCutscene) {
										ImGui::Text("YES");
									}
									else {
										ImGui::Text("NO");
									}
									ImGui::TableSetColumnIndex(10);
									
								}
							}
							ImGui::EndTable();
						}

						ImGui::EndTabItem();
					}
					if (ImGui::BeginTabItem("Lobby", NULL)) {

						ImGui::Checkbox("Money Lobby", &g_toggles.lobby_drop_money);
						ImGui::SliderInt("Money Speed", &g_vars.drop_money_speed, 1, 2000);
						ImGui::EndTabItem();
					}
					ImGui::EndTabBar();
				}


			}
			ImGui::End();
			for (const auto& [p, scid] : g_c_functions.selected) {
				if (ImGui::Begin(p.name.c_str())) {

				}
				ImGui::End();
			}
		}
	}
}