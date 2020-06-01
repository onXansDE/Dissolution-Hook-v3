#include "Menus.h"
#include "Toggles.h"
#include "Vars.h"
#include "fiber_pool.hpp"
#include "Functions.h"
#include "natives.hpp"

namespace big {


	ImVec2 vehi_window_size = ImVec2(680, 520);
	ImVec2 vehi_mods_window = ImVec2(200, 180);

	void RMenus::render_vehicle_menu() {
		if (g_menus.show_vehicle_menu) {

			ImGui::SetNextWindowSize(vehi_window_size, ImGuiCond_Once);
			if (ImGui::Begin("Vehicle Options", &g_menus.show_vehicle_menu, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollWithMouse)) {
				if (ImGui::BeginTable("vehiclequick", 2)) {
					ImGui::TableNextRow();
					ImGui::Text("Quick Spawn");
					if (ImGui::Button("T20", default_button_size)) {
						g_fiber_pool->queue_job([&]
						{
							g_c_functions.spawnVehicle("t20", true, true);
						});
					}
					ImGui::SameLine();
					if (ImGui::Button("Bati", default_button_size)) {
						g_fiber_pool->queue_job([&]
						{
							g_c_functions.spawnVehicle("bati", true, true);
						});
					}
					if (ImGui::Button("Hydra", default_button_size)) {
						g_fiber_pool->queue_job([&]
						{
							g_c_functions.spawnVehicle("hydra", true, true);
						});
					}
					ImGui::SameLine();
					if (ImGui::Button("Zion", default_button_size)) {
						g_fiber_pool->queue_job([&]
						{
							g_c_functions.spawnVehicle("zion2", true, true);
						});
					}
					ImGui::TableNextCell();
					ImGui::Text("Quick Mods");
					if (ImGui::BeginTable("quickmods", 2)) {
						ImGui::TableNextRow();
						ImGui::Checkbox("Vehicle God", &g_toggles.vehi_mod_cargod);
						ImGui::TableNextCell();
						ImGui::Checkbox("Enable Multipliers ", &g_toggles.vehi_mod_enbmultipliers);
						ImGui::TableNextCell();
						ImGui::Checkbox("Horn Boost", &g_toggles.vehi_mod_hornboost);
						ImGui::TableNextCell();
						ImGui::Checkbox("Rainbow", &g_toggles.vehi_mod_rainbow);
						ImGui::EndTable();
					}
					ImGui::EndTable();
				}
				ImGui::Spacing();
				if (ImGui::BeginTable("vehicle2", 3, ImGuiTableFlags_RowBg)) {
					ImGui::TableNextRow();
					ImGui::Text("Los Santos Customs");
					if (ImGui::BeginTable("simplelsc", 2)) {
						ImGui::TableNextRow();
						if (ImGui::Button("Fix Vehicle", small_button_size)) {
							g_fiber_pool->queue_job([]
							{
								if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
								{
									Vehicle playerVeh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
									VEHICLE::SET_VEHICLE_FIXED(playerVeh);
								}
							});
						}
						ImGui::TableNextCell();
						if (ImGui::Button("Max Upgrade", small_button_size)) {
							Vehicle playerVeh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
							g_c_functions.maxVehicle(playerVeh);
						}
						ImGui::TableNextCell();
						if (ImGui::Button("Random Color", small_button_size)) {
							Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
							DWORD model = ENTITY::GET_ENTITY_MODEL(veh);

							if (PED::IS_PED_IN_ANY_VEHICLE)
							{
								VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, rand() % 255, rand() % 255, rand() % 255);
								VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, rand() % 255, rand() % 255, rand() % 255);
							}
						}
						ImGui::TableNextCell();
						if (ImGui::Button("Advanced", small_button_size)) {
							if (g_menus.show_advanced_lsc_menu) {
								g_menus.show_advanced_lsc_menu = false;
							}
							else {
								g_menus.show_advanced_lsc_menu = true;
							}
						}
						ImGui::TableNextCell();
						if (ImGui::ColorEdit4("Primary Color", (float*)&g_vars.prim_color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoAlpha)) {
							if (g_toggles.vehi_lsc_livecolor) {
								Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
								DWORD model = ENTITY::GET_ENTITY_MODEL(veh);

								if (PED::IS_PED_IN_ANY_VEHICLE)
								{
									VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, g_vars.prim_color.x * 255, g_vars.prim_color.y * 255, g_vars.prim_color.z * 255);
								}
							}
						}
						ImGui::TableNextCell();
						if (ImGui::ColorEdit4("Second Color", (float*)&g_vars.sec_color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoAlpha)) {
							if (g_toggles.vehi_lsc_livecolor) {
								Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
								DWORD model = ENTITY::GET_ENTITY_MODEL(veh);

								if (PED::IS_PED_IN_ANY_VEHICLE)
								{
									VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, g_vars.sec_color.x * 255, g_vars.sec_color.y * 255, g_vars.sec_color.z * 255);
								}
							}
						}
						ImGui::TableNextCell();
						if (ImGui::Button("Apply Color", small_button_size)) {
							Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
							DWORD model = ENTITY::GET_ENTITY_MODEL(veh);

							if (PED::IS_PED_IN_ANY_VEHICLE)
							{
								VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, g_vars.prim_color.x * 255, g_vars.prim_color.y * 255, g_vars.prim_color.z * 255);
								VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, g_vars.sec_color.x * 255, g_vars.sec_color.y * 255, g_vars.sec_color.z * 255);
							}
						}
						ImGui::TableNextCell();
						ImGui::Checkbox("Live Update", &g_toggles.vehi_lsc_livecolor);
						ImGui::TableNextCell();
						if (ImGui::Button("Primary Chrom", small_button_size)) {
							g_fiber_pool->queue_job([] {
								Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
								VEHICLE::SET_VEHICLE_COLOURS(veh, 120, 0);
							});

						}
						ImGui::TableNextCell();
						if (ImGui::Button("Second Chrom", small_button_size)) {
							g_fiber_pool->queue_job([] {
								Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
								VEHICLE::SET_VEHICLE_COLOURS(veh, 0, 120);
							});
						}
						ImGui::TableNextCell();
						if (ImGui::Button("Apply Plate", small_button_size)) {
							g_fiber_pool->queue_job([] {
								Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
								VEHICLE::SET_VEHICLE_MOD_KIT(veh, 1);
								VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, "DSLHOOK");
								VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh, 1);
							});
						}
						ImGui::EndTable();
					}

					ImGui::TableNextCell();
					ImGui::Text("Spawner");
					if (ImGui::BeginTable("simplespawner", 1)) {
						ImGui::TableNextRow();
						ImGui::Checkbox("Spawn Maxed", &g_toggles.vehi_spw_maxed);
						ImGui::TableNextCell();
						ImGui::Checkbox("Spawn Inside", &g_toggles.vehi_spw_inside);
						ImGui::TableNextCell();
						static char name2[32] = "zentorno";
						ImGui::InputText("inputcarname2", name2, IM_ARRAYSIZE(name2));
						ImGui::TableNextCell();
						if (ImGui::Button("Spawn Vehicle", long_button_size)) {
							g_fiber_pool->queue_job([&]
							{
								g_c_functions.spawnVehicle(name2, g_toggles.vehi_spw_maxed, g_toggles.vehi_spw_inside);
							});

						}
						ImGui::TableNextCell();
						if (ImGui::Button("Advanced", long_button_size)) {
						}
						ImGui::EndTable();
					}

					ImGui::TableNextCell();
					ImGui::Text("Mods");
					if (ImGui::BeginChild("vehiclemodsw", vehi_mods_window)) {
						if (ImGui::CollapsingHeader("Common")) {
							ImGui::Checkbox("Auto Repair", &g_toggles.vehi_mod_autorepair);
							ImGui::Checkbox("Vehicle God", &g_toggles.vehi_mod_cargod);
							ImGui::Checkbox("Tire God", &g_toggles.vehi_mod_tireinvinc);
							ImGui::Checkbox("Invisible Vehicle", &g_toggles.vehi_mod_invisible);
							ImGui::Checkbox("Animated DSL Plate", &g_toggles.vehi_lsc_animatedplate);
							if (g_toggles.vehi_lsc_animatedplate) {
								ImGui::SliderInt("Speed ", &g_vars.vehi_mod_movplatespeed, 30, 300);
							}
						}
						if (ImGui::CollapsingHeader("Multiplier")) {
							ImGui::Checkbox("Enable Multipliers", &g_toggles.vehi_mod_enbmultipliers);
							ImGui::SliderFloat("Speed", &g_vars.car_speed_multiplier, 1.0f, 400.0f);
							ImGui::SliderFloat("Grip", &g_vars.car_grip_multiplier, 1.0f, 400.0f);
							ImGui::SliderFloat("Torque", &g_vars.car_torque_multiplier, 1.0f, 500.0f);
							if (ImGui::Button("Reset")) {
								g_vars.car_speed_multiplier = 1.0f;
								g_vars.car_torque_multiplier = 1.0f;
								g_vars.car_grip_multiplier = 1.0f;
							}
						}
						if (ImGui::CollapsingHeader("Movement")) {
							ImGui::Checkbox("Vehicle Fly", &g_toggles.vehi_mod_carfly);
							if (g_toggles.vehi_mod_carfly) {
								ImGui::Text("Acceleration");
								ImGui::SliderFloat("##accelle", &g_vars.vehi_mod_flyaccel, 0.005f, 0.1f);
								ImGui::Text("Top Speed");
								ImGui::SliderFloat("##maxspeed", &g_vars.vehi_mod_flymaxspeed, 10.0f, 200.0f);
							}
							ImGui::Checkbox("Ultra Speed", &g_toggles.vehi_mod_superboost);
							if (g_toggles.vehi_mod_superboost) {
								ImGui::SliderFloat("##accelle ", &g_vars.vehi_mod_superboostaccel, 0.005f, 0.1f);
								ImGui::Text("Min Speed");
								ImGui::SliderFloat("##minspeed ", &g_vars.vehi_mod_superboostamount, 10.0f, 200.0f);
								ImGui::Text("Top Speed");
								ImGui::SliderFloat("##maxspeed ", &g_vars.vehi_mod_superboostmax, 10.0f, 200.0f);
							}
							ImGui::Checkbox("Horn Boost", &g_toggles.vehi_mod_hornboost);
							if (g_toggles.vehi_mod_hornboost) {
								ImGui::Text("Acceleration");
								ImGui::SliderFloat("##accelle  ", &g_vars.vehi_mod_hornboostaccel, 0.005f, 0.1f);
								ImGui::Text("Min Speed");
								ImGui::SliderFloat("##minspeed  ", &g_vars.vehi_mod_hornboostamount, 0.0f, 200.0f);
								ImGui::Text("Top Speed");
								ImGui::SliderFloat("##maxspeed  ", &g_vars.vehi_mod_hornboostmax, 10.0f, 200.0f);

								if (g_vars.vehi_mod_hornboostmax < g_vars.vehi_mod_hornboostamount) {
									g_vars.vehi_mod_hornboostmax = g_vars.vehi_mod_hornboostamount;
								}
							}
							ImGui::Checkbox("Vehicle Jump", &g_toggles.vehi_mod_carjump);
							if (g_toggles.vehi_mod_carjump) {
								ImGui::SliderFloat("Height", &g_vars.vehi_mod_jumpheight, 3.0f, 30.0f);
							}
							ImGui::Checkbox("Slide Mode", &g_toggles.vehi_mod_sticky);
							ImGui::Checkbox("Drift mode", &g_toggles.vehi_mod_drift);

						}

						ImGui::EndChild();
					}
					ImGui::EndTable();
				}
				ImGui::Spacing();
				if (ImGui::BeginTable("vehicle3", 2)) {
					ImGui::TableNextRow();
					ImGui::Text("Stuff");
					ImGui::Spacing();
					ImGui::Text("Light Strengh");
					ImGui::Checkbox("Enabled", &g_toggles.vehi_light_mtp_en);
					ImGui::PushItemWidth(100);
					ImGui::SliderFloat("Strength", &g_vars.car_light_multiplier, 0.5f, 40.0f);
					ImGui::TableNextCell();
					ImGui::Text("Rainbow");
					if (ImGui::BeginTable("vehirainbow", 2)) {
						ImGui::TableNextRow();
						ImGui::Text("Ranbow Stuff");
						ImGui::TableNextRow();
						ImGui::Checkbox("Enabled", &g_toggles.vehi_mod_rainbow);
						ImGui::TableNextCell();
						ImGui::Checkbox("Blink Mode", &g_toggles.vehi_mod_rablinkmode);
						ImGui::TableNextCell();
						ImGui::Checkbox("Primary", &g_toggles.vehi_mod_raprimary);
						ImGui::TableNextCell();
						ImGui::Checkbox("Secondary", &g_toggles.vehi_mod_rasecondary);
						ImGui::TableNextCell();
						ImGui::Checkbox("Sync Colors", &g_toggles.vehi_mod_fadesync);
						ImGui::TableNextCell();
						ImGui::Checkbox("Tire Smoke", &g_toggles.vehi_mod_tirainbow);
						if (g_toggles.vehi_mod_tirainbow && !g_toggles.vehi_mod_rablinkmode) {
							ImGui::Checkbox("Primary Color", &g_toggles.vehi_mod_tireprime);
						}
						ImGui::TableNextRow();
						ImGui::SliderInt("Speed", &g_vars.vehi_mod_rainbowspeed, 0.0f, 100.0f);
						ImGui::EndTable();
					}
					ImGui::EndTable();

				}
			}
			ImGui::End();
		}
	}
}