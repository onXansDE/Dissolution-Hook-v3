#include "Menus.h"
#include "Toggles.h"
#include "Vars.h"
#include "fiber_pool.hpp"
#include "Functions.h"
#include "natives.hpp"

namespace big {


	ImVec2 weap_window_size = ImVec2(680, 500);


	void RMenus::render_weapon_menu() {
		if (show_weapon_menu) {
			ImGui::SetNextWindowSize(weap_window_size);
			if (ImGui::Begin("Weapon Menu", &show_weapon_menu, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollWithMouse)) {
				if (ImGui::BeginTable("weaponquicks", 2)) {
					ImGui::TableNextRow();
					if (ImGui::BeginTable("weaopnquickbuttons", 2)) {
						ImGui::TableNextRow();
						if (ImGui::Button("Give Weapons", default_button_size)) {
							g_fiber_pool->queue_job([&] {
								g_c_functions.giveAllWeapons();
							});
						}
						ImGui::TableNextCell();
						if (ImGui::Button("Full Ammo", default_button_size)) {

						}
						ImGui::TableNextCell();
						if (ImGui::Button("Give Digiscanner", default_button_size)) {

						}
						ImGui::TableNextCell();
						if (ImGui::Button("Give Briefcase", default_button_size)) {

						}
						ImGui::EndTable();
					}
					ImGui::TableNextCell();
					if (ImGui::BeginTable("weaponquicktoggle", 2)) {
						ImGui::Checkbox("Infinite Ammo", &g_toggles.weps_infinite_ammo);
						ImGui::Checkbox("No Realod", &g_toggles.weps_no_reload);
						ImGui::Checkbox("Explosive Ammo", &g_toggles.weps_explosive_ammo);
						ImGui::Checkbox("Money Gun", &g_toggles.weps_money_ammo);

						ImGui::EndTable();
					}
					ImGui::EndTable();
				}
				if (ImGui::BeginTable("weapon2", 2)) {
					ImGui::TableNextRow();
					ImGui::Text("Modded Ammo");
					ImGui::Checkbox("Infinite Ammo", &g_toggles.weps_infinite_ammo);
					ImGui::Checkbox("Car Gun", &g_toggles.weps_car_gun);
					ImGui::Checkbox("Money Gun", &g_toggles.weps_money_ammo);
					ImGui::Checkbox("Fire Ammo", &g_toggles.weps_fire_ammo);
					ImGui::Checkbox("Explosive Ammo", &g_toggles.weps_explosive_ammo);
					ImGui::Checkbox("Multiplier", &g_toggles.weps_multiplier_enb);
					if (g_toggles.weps_multiplier_enb) {
						ImGui::SliderFloat("Range", &g_vars.range_damage_multiplier, 1, 100);
						ImGui::SliderFloat("Melee", &g_vars.meele_damage_multiplier, 1, 100);
					}
					ImGui::TableNextCell();
					ImGui::Text("Combat");
					ImGui::Checkbox("Explo Fist", &g_toggles.weps_explosive_melee);
					ImGui::Checkbox("Aimbot", &g_toggles.weps_silent_aim);
					if (g_toggles.weps_silent_aim) {
						ImGui::Checkbox("No Friends", &g_toggles.weps_silent_aim_no_friends);
					}
					ImGui::TableNextCell();
					ImGui::Text("Mods");
					ImGui::Checkbox("Delete Gun", &g_toggles.weps_delete_gun);
					ImGui::Checkbox("Gravity Gun", &g_toggles.weps_gravity_gun);
					ImGui::Checkbox("No Realod", &g_toggles.weps_no_reload);
					ImGui::Checkbox("Rapid Fire", &g_toggles.weps_rapid_fire);
					ImGui::Checkbox("Teleport Gun", &g_toggles.weps_teleport_gun);
					ImGui::Checkbox("Infinite Parachute", &g_toggles.weps_infinite_parchutes);
					ImGui::EndTable();
				}
			}
			ImGui::End();
		}
	}
}