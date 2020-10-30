#include "common.hpp"
#include "fiber_pool.hpp"
#include "gta/player.hpp"
#include "gta_util.hpp"
#include "gui.hpp"
#include "logger.hpp"
#include "memory/module.hpp"
#include "memory/pattern.hpp"
#include "script_global.hpp"
#include "natives.hpp"
#include "pointers.hpp"
#include "renderer.hpp"
#include "script.hpp"
#include <Menus.h>
#include "Vars.h"
#include "general.h"
#include "Toggles.h"
#include "Functions.h"

#include <imgui.h>

namespace big
{
	void gui::dx_init()
	{
		auto &style = ImGui::GetStyle();
		style.WindowPadding = { 10.f, 10.f };
		style.PopupRounding = 0.f;
		style.FramePadding = { 8.f, 4.f };
		style.ItemSpacing = { 10.f, 8.f };
		style.ItemInnerSpacing = { 6.f, 6.f };
		style.TouchExtraPadding = { 0.f, 0.f };
		style.IndentSpacing = 21.f;
		style.ScrollbarSize = 15.f;
		style.GrabMinSize = 8.f;
		style.WindowBorderSize = 1.f;
		style.ChildBorderSize = 0.f;
		style.PopupBorderSize = 1.f;
		style.FrameBorderSize = 0.f;
		style.TabBorderSize = 0.f;
		style.WindowRounding = 0.f;
		style.ChildRounding = 0.f;
		style.FrameRounding = 0.f;
		style.ScrollbarRounding = 0.f;
		style.GrabRounding = 0.f;
		style.TabRounding = 0.f;
		style.WindowTitleAlign = { 0.5f, 0.5f };
		style.ButtonTextAlign = { 0.5f, 0.5f };
		style.DisplaySafeAreaPadding = { 3.f, 3.f };

		auto &colors = style.Colors;
		g_general.loadTheme("dark.json");
	}
	ImVec2 alsc_window_size = ImVec2(780, 600);

	ImVec2 watermark_size = ImVec2(160, 7);


	ImVec2 default_button_size = ImVec2(130, 20);
	ImVec2 long_button_size = ImVec2(220, 30);
	ImVec2 small_button_size = ImVec2(100, 30);
	ImVec2 medium_button_size = ImVec2(150, 30);
	ImVec2 big_button_size = ImVec2(230, 40);

#define PROP_MONEY_BAG_01 0x113FD533
#define PICKUP_MONEY_CASE 0xCE6FDD6B
#define MAIN_PERSISTENT 0x5700179C
#define PICKUP_MONEY_CASE 0xCE6FDD6B
#define PICKUP_MONEY_VARIABLE 0xEA888D49
	//Execute Hacks

	//FUNCTIONS
	void nextRainbowStep() {
		if (g_vars.vehi_rainbow_step >= (g_vars.vehi_nextrainbow_step + g_vars.vehi_mod_rainbowspeed)) {
			if (g_vars.fader1 > 0 && g_vars.fadeb1 == 0) {
				g_vars.fader1--;
				g_vars.fadeg1++;
			}
			if (g_vars.fadeg1 > 0 && g_vars.fader1 == 0) {
				g_vars.fadeg1--;
				g_vars.fadeb1++;
			}
			if (g_vars.fadeb1 > 0 && g_vars.fadeg1 == 0) {
				g_vars.fader1++;
				g_vars.fadeb1--;
			}
			if (g_vars.fader2 > 0 && g_vars.fadeb2 == 0) {
				g_vars.fader2--;
				g_vars.fadeg2++;
			}
			if (g_vars.fadeg2 > 0 && g_vars.fader2 == 0) {
				g_vars.fadeg2--;
				g_vars.fadeb2++;
			}
			if (g_vars.fadeb2 > 0 && g_vars.fadeg2 == 0) {
				g_vars.fader2++;
				g_vars.fadeb2--;
			}

			g_vars.blinkr1 = rand() % 255;
			g_vars.blinkg1 = rand() % 255;
			g_vars.blinkb1 = rand() % 255;
			g_vars.blinkr2 = rand() % 255;
			g_vars.blinkg2 = rand() % 255;
			g_vars.blinkb2 = rand() % 255;
			g_vars.vehi_nextrainbow_step = g_vars.vehi_rainbow_step + g_vars.vehi_mod_rainbowspeed;
			g_vars.vehi_rainbow_step++;
		}
		else {
			g_vars.vehi_rainbow_step++;
		}
	}

	void nextNetStep() {
		if (g_vars.net_step >= g_vars.net_nextstep) {
			g_vars.net_nextstep = g_vars.net_step + g_vars.net_checkspeed;
			g_vars.net_step++;
			g_fiber_pool->queue_job([] {
				g_c_functions.getPlayerList();
			});
		}
		else {
			g_vars.net_step++;
		}
	}

	void nextPlateStep() {

		if (g_vars.vehi_movplate_step >= g_vars.vehi_nextmovplate_step) {
			if (g_vars.vehi_moveplate_state == 6) {
				g_vars.vehi_moveplate_state = 0;
			}
			if (g_toggles.vehi_lsc_animatedplate) {
				g_fiber_pool->queue_job([&] {
					if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) {
						Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
						VEHICLE::SET_VEHICLE_MOD_KIT(veh, 1);
						VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh, g_vars.platesteps[g_vars.vehi_moveplate_state]);
						VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(veh, 1);
						g_vars.vehi_moveplate_state++;
					}
				});
			}
			g_vars.vehi_nextmovplate_step = g_vars.vehi_movplate_step + g_vars.vehi_mod_movplatespeed;
			g_vars.vehi_movplate_step++;
		}
		else {
			g_vars.vehi_movplate_step++;
		}
	}

	void moneylobbydroptimer() {
		if (g_vars.drop_money_step >= g_vars.drop_nextmoney_step) {
			g_fiber_pool->queue_job([] {
				if (g_toggles.lobby_drop_money) {
					g_vars.drop_nextmoney_step = g_vars.drop_money_step + g_vars.drop_money_speed;
					Player playerPed = PLAYER::PLAYER_PED_ID();
					for (int i = 0; i < 32; i++) {
						if (NETWORK::NETWORK_IS_PLAYER_CONNECTED(i)) {
							Player playerHandle = PLAYER::GET_PLAYER_PED(i);
							Vector3 playerCoords = ENTITY::GET_ENTITY_COORDS(playerHandle, 0);
							OBJECT::CREATE_AMBIENT_PICKUP(MISC::GET_HASH_KEY("PICKUP_MONEY_MED_BAG"), playerCoords.x, playerCoords.y, playerCoords.z + 3, 0, 2500, 1, 0, 1);
						}
					}
				}
			});
			g_vars.drop_money_step++;
		}
		else {
			g_vars.drop_money_step++;
		}
	}

	void giveWeapon(Ped selectedPed)
	{
		if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
		{
			if (!WEAPON::IS_WEAPON_VALID(MISC::GET_HASH_KEY("WEAPON_RAILGUN")))
			{
				return;
			}
			else
			{
				char* weapon = "WEAPON_RAILGUN";
				Hash pedWeapon = MISC::GET_HASH_KEY(weapon);
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(selectedPed, pedWeapon, 0, true);
				WEAPON::SET_PED_AMMO(selectedPed, pedWeapon, 1000, true);
			}
		}
	}
	void set_all_nearby_peds_to_calm(Player selectedPlayer)
	{
		const int numElements = 10;
		const int arrSize = numElements * 2 + 2;  //Start at index 2, and the odd elements are padding
		int peds[arrSize];
		//0 index is the size of the array
		peds[0] = numElements;

		int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);
		for (int i = 0; i < count; ++i)
		{
			for (int n = 0; n < 32; n++)
			{
				int offsettedID = i * 2 + 2;
				if (ENTITY::DOES_ENTITY_EXIST(peds[offsettedID]))
				{
					if ((peds[offsettedID]) == selectedPlayer) continue;
					{
						PED::SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(peds[offsettedID], true);
						PED::SET_PED_FLEE_ATTRIBUTES(peds[offsettedID], 0, 0);
						PED::SET_PED_COMBAT_ATTRIBUTES(peds[offsettedID], 17, 1);
					}
				}
			}
		}
	}

	void gui::dx_on_tick()
	{
		TRY_CLAUSE
		{
			g_menus.render();
		if (g_menus.show_debug_menu) {
			if (ImGui::Begin("Debug")) {
				const long double sysTime = time(0);
				const long double sysTimeMS = sysTime * 1000;
				ImGui::Text("Rainbowstep: %i", g_vars.vehi_rainbow_step);
				ImGui::Text("Next Rainbowstep: %i", g_vars.vehi_nextrainbow_step);
				ImGui::Spacing();
				ImGui::Text("Moveplatestep: %i", g_vars.vehi_movplate_step);
				ImGui::Text("Next Moveplatestep: %i", g_vars.vehi_nextmovplate_step);
				ImGui::Text("Moveplatestate: %i", g_vars.vehi_moveplate_state);
				ImGui::Spacing();
				ImGui::Text("Money: %i", g_vars.drop_money_step);
				ImGui::Text("Next Moneystep: %i", g_vars.drop_nextmoney_step);
				ImGui::Spacing();
			}
			ImGui::End();
		}

		}
		EXCEPT_CLAUSE
	}
	void gui::dx_on_tick_overlay() {
		ImGui::SetNextWindowSize(watermark_size);
		ImGui::Begin("##watermark", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar);
		ImGui::Text("DISSOLUTION HOOK v2");
		ImGui::End();
	}

	void gui::script_init()
	{
		const long double sysTime = time(0);
		const long double sysTimeMS = sysTime * 1000;
		g_vars.vehi_nextrainbow_step = g_vars.vehi_nextrainbow_step + 300;
		g_vars.vehi_nextmovplate_step = g_vars.vehi_nextmovplate_step + 300;
		g_vars.drop_nextmoney_step = g_vars.drop_nextmoney_step + 300;
		g_vars.net_nextstep = 100;
		g_vars.net_step = 0;
	}

	void gui::script_on_tick()
	{
		nextRainbowStep();
		nextPlateStep();
		moneylobbydroptimer();
		nextNetStep();
		g_fiber_pool->queue_job([] {
			g_c_functions.getMyCords();
		});
		if (g_gui.m_opened)
		{
			g_fiber_pool->queue_job([] {
				PAD::DISABLE_CONTROL_ACTION(1, 1, true);
				PAD::DISABLE_CONTROL_ACTION(1, 2, true);
				PAD::DISABLE_CONTROL_ACTION(2, 19, true);
				PAD::DISABLE_CONTROL_ACTION(2, 37, true);
				PAD::DISABLE_CONTROL_ACTION(2, 39, true);
				PAD::DISABLE_CONTROL_ACTION(2, 42, true);
				PAD::DISABLE_CONTROL_ACTION(2, 18, true);
				PAD::DISABLE_CONTROL_ACTION(2, 69, true);
				PAD::DISABLE_CONTROL_ACTION(2, 92, true);
				PAD::DISABLE_CONTROL_ACTION(2, 106, true);
				PAD::DISABLE_CONTROL_ACTION(2, 122, true);
				PAD::DISABLE_CONTROL_ACTION(2, 135, true);
				PAD::DISABLE_CONTROL_ACTION(2, 176, true);
				PAD::DISABLE_CONTROL_ACTION(2, 223, true);
				PAD::DISABLE_CONTROL_ACTION(2, 229, true);
				PAD::DISABLE_CONTROL_ACTION(2, 237, true);
				PAD::DISABLE_CONTROL_ACTION(2, 329, true);
				PAD::DISABLE_CONTROL_ACTION(0, 24, true);
				PAD::DISABLE_CONTROL_ACTION(2, 25, true);
				PAD::DISABLE_CONTROL_ACTION(2, 47, true);
				PAD::DISABLE_CONTROL_ACTION(2, 263, true);
				PAD::DISABLE_CONTROL_ACTION(2, 264, true);
				PAD::DISABLE_CONTROL_ACTION(2, 257, true);
				PAD::DISABLE_CONTROL_ACTION(2, 140, true);
				PAD::DISABLE_CONTROL_ACTION(2, 141, true);
				PAD::DISABLE_CONTROL_ACTION(2, 142, true);
				PAD::DISABLE_CONTROL_ACTION(2, 143, true);
				PAD::DISABLE_CONTROL_ACTION(2, 346, true);
				PAD::DISABLE_CONTROL_ACTION(2, 144, true);
				PAD::DISABLE_CONTROL_ACTION(2, 121, true);
				PAD::DISABLE_CONTROL_ACTION(2, 156, true);
				PAD::DISABLE_CONTROL_ACTION(2, 14, true);
				PAD::DISABLE_CONTROL_ACTION(2, 15, true);
				PAD::DISABLE_CONTROL_ACTION(2, 16, true);
				PAD::DISABLE_CONTROL_ACTION(2, 17, true);
				PAD::DISABLE_CONTROL_ACTION(2, 50, true);
				PAD::DISABLE_CONTROL_ACTION(2, 99, true);
				PAD::DISABLE_CONTROL_ACTION(2, 115, true);
				PAD::DISABLE_CONTROL_ACTION(2, 180, true);
				PAD::DISABLE_CONTROL_ACTION(2, 99, true);
				PAD::DISABLE_CONTROL_ACTION(2, 181, true);
				PAD::DISABLE_CONTROL_ACTION(2, 198, true);
				PAD::DISABLE_CONTROL_ACTION(2, 241, true);
				PAD::DISABLE_CONTROL_ACTION(2, 242, true);
				PAD::DISABLE_CONTROL_ACTION(2, 261, true);
				PAD::DISABLE_CONTROL_ACTION(2, 262, true);
				PAD::DISABLE_CONTROL_ACTION(2, 332, true);
				PAD::DISABLE_CONTROL_ACTION(2, 333, true);
				PAD::DISABLE_CONTROL_ACTION(2, 334, true);
				PAD::DISABLE_CONTROL_ACTION(2, 348, true);
				PAD::DISABLE_CONTROL_ACTION(2, 81, true);
				PAD::DISABLE_CONTROL_ACTION(2, 82, true);
				PAD::DISABLE_CONTROL_ACTION(2, 83, true);
				PAD::DISABLE_CONTROL_ACTION(2, 84, true);
			});
		}

		//NETWORK

		//VEHICLE
		if (g_toggles.vehi_mod_rainbow) {
			Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
			if (g_toggles.vehi_mod_rablinkmode) {

				if (g_toggles.vehi_mod_fadesync) {
					if (g_toggles.vehi_mod_raprimary) {
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, g_vars.blinkr1, g_vars.blinkg1, g_vars.blinkb1);
					}
					if (g_toggles.vehi_mod_rasecondary) {
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, g_vars.blinkr1, g_vars.blinkg1, g_vars.blinkb1);
					}
				}
				else {

					if (g_toggles.vehi_mod_raprimary) {
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, g_vars.blinkr1, g_vars.blinkg1, g_vars.blinkb1);
					}
					if (g_toggles.vehi_mod_rasecondary) {
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, g_vars.blinkr2, g_vars.blinkg2, g_vars.blinkb2);
					}
				}
			}
			else {
				if (g_toggles.vehi_mod_fadesync) {
					if (g_toggles.vehi_mod_raprimary) {
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, g_vars.fader1, g_vars.fadeg1, g_vars.fadeb1);
					}
					if (g_toggles.vehi_mod_rasecondary) {
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, g_vars.fader1, g_vars.fadeg1, g_vars.fadeb1);
					}
				}
				else {

					if (g_toggles.vehi_mod_raprimary) {
						VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, g_vars.fader1, g_vars.fadeg1, g_vars.fadeb1);
					}
					if (g_toggles.vehi_mod_rasecondary) {
						VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, g_vars.fader2, g_vars.fadeg2, g_vars.fadeb2);
					}
				}
			}
		}

		if (g_toggles.vehi_mod_tirainbow) {
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) {
				Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
				DWORD model = ENTITY::GET_ENTITY_MODEL(veh);
				if (g_toggles.vehi_mod_rablinkmode) {
					if (g_toggles.vehi_mod_fadesync) {
						VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, g_vars.blinkr1, g_vars.blinkg1, g_vars.blinkb1);
					}
					else {
						VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, rand() % 255, rand() % 255, rand() % 255);
					}
				}
				else {
					if (g_toggles.vehi_mod_tireprime) {
						VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, g_vars.fader1, g_vars.fadeg1, g_vars.fadeb1);
					}
					else {
						VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, g_vars.fader2, g_vars.fadeg2, g_vars.fadeb2);
					}
				}
			}
		}

		if (g_toggles.vehi_mod_sticky)
		{
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
			{
				Vehicle myVehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
				VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(myVehicle, 1);
			}
		}

		if (g_toggles.vehi_mod_invisible) {
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
			{
				Vehicle myVehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
				ENTITY::SET_ENTITY_VISIBLE(myVehicle, false, 0);
			}
		}
		else {
			Vehicle myVehicle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
			ENTITY::SET_ENTITY_VISIBLE(myVehicle, true, 1);
		}

		if (g_toggles.vehi_mod_enbmultipliers)
		{
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) {
				Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
				VEHICLE::_SET_VEHICLE_ENGINE_POWER_MULTIPLIER(veh, g_vars.car_speed_multiplier);
				VEHICLE::_SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER(veh, g_vars.car_torque_multiplier);
				VEHICLE::SET_VEHICLE_FRICTION_OVERRIDE(veh, g_vars.car_grip_multiplier);
			}
		}
		else {
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) {
				Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
				VEHICLE::_SET_VEHICLE_ENGINE_POWER_MULTIPLIER(veh, 1);
				VEHICLE::_SET_VEHICLE_ENGINE_TORQUE_MULTIPLIER(veh, 1);
				VEHICLE::SET_VEHICLE_FRICTION_OVERRIDE(veh, 1);
			}
		}

		if (g_toggles.vehi_light_mtp_en) {
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) {
				Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
				VEHICLE::SET_VEHICLE_LIGHT_MULTIPLIER(veh, g_vars.car_light_multiplier);
			}
		}
		else {
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) {
				Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
				VEHICLE::SET_VEHICLE_LIGHT_MULTIPLIER(veh, 1);
			}
		}

		if (g_toggles.vehi_mod_autorepair)
		{
			g_fiber_pool->queue_job([]
			{
				if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
				{
					Vehicle playerVeh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
					VEHICLE::SET_VEHICLE_FIXED(playerVeh);
				}
			});
		}

		if (g_toggles.vehi_mod_cargod) {
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
			{
				Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
				ENTITY::SET_ENTITY_INVINCIBLE(veh, true);
				ENTITY::SET_ENTITY_PROOFS(veh, 1, 1, 1, 1, 1, 1, 1, 1);
				VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 0);
				VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(veh, 0);
				VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(veh, 0);
			}

			else {
				if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
				{
					Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
					ENTITY::SET_ENTITY_INVINCIBLE(veh, false);
					ENTITY::SET_ENTITY_PROOFS(veh, 0, 0, 0, 0, 0, 0, 0, 0);
					VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, 1);
					VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(veh, 1);
					VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(veh, 1);
				}
			}
		}

		if (g_toggles.vehi_mod_tireinvinc)
		{
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
			{
				Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
				VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, false);
				VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(veh, false);
				VEHICLE::SET_VEHICLE_HAS_STRONG_AXLES(veh, true);
			}
		}
		else {
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
			{
				Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
				VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(veh, true);
				VEHICLE::SET_VEHICLE_WHEELS_CAN_BREAK(veh, true);
				VEHICLE::SET_VEHICLE_HAS_STRONG_AXLES(veh, false);
			}
		}

		if (g_toggles.vehi_mod_drift)
		{
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) {

				VEHICLE::SET_VEHICLE_REDUCE_GRIP(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), 1);
			}
		}
		else
		{
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) {
				VEHICLE::SET_VEHICLE_REDUCE_GRIP(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), 0);
			}
		}

		if (g_toggles.vehi_mod_carfly) {
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) {
				Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
				if (PAD::IS_CONTROL_PRESSED(0, 72)) {
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 0.0f);
				}
				else {
					if (PAD::IS_CONTROL_PRESSED(0, 76)) {
						ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0, 0, 10, 0, 0, 0, true, true, true, true, false, true);
					}
					if (PAD::IS_CONTROL_PRESSED(0, 71)) {
						float speed = ENTITY::GET_ENTITY_SPEED(veh);
						if (speed < 3.0f) speed = 3.0f;
						speed += speed * g_vars.vehi_mod_flyaccel;
						if (speed > g_vars.vehi_mod_flymaxspeed) speed = g_vars.vehi_mod_flymaxspeed;
						VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, speed);
					}
					else {
						VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 0.0f);
					}

				}
			}
		}

		if (g_toggles.vehi_mod_superboost) {
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) {
				Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
				if (PAD::IS_CONTROL_PRESSED(0, 76)) {
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, 0.0f);
				}
				else {
					if (PAD::IS_CONTROL_PRESSED(0, 71)) {
						float speed = ENTITY::GET_ENTITY_SPEED(veh);
						if (speed < g_vars.vehi_mod_superboostamount) speed = g_vars.vehi_mod_superboostamount;
						speed += speed * g_vars.vehi_mod_superboostaccel;
						if (speed > g_vars.vehi_mod_superboostmax) speed = g_vars.vehi_mod_superboostmax;
						VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, speed);
						VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh,1);

					}
					else if (PAD::IS_CONTROL_PRESSED(0, 72)) {
						float speed = ENTITY::GET_ENTITY_SPEED(veh);
						VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, -speed);
						VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh,1);
					}

				}

			}
		}

		if (g_toggles.vehi_mod_hornboost) {
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) {
				Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
				if (PAD::IS_CONTROL_PRESSED(0, 86)) {
					float speed = ENTITY::GET_ENTITY_SPEED(veh);
					if (speed < g_vars.vehi_mod_hornboostamount) speed = g_vars.vehi_mod_hornboostamount;
					speed += speed * g_vars.vehi_mod_hornboostaccel;
					if (speed > g_vars.vehi_mod_hornboostmax) speed = g_vars.vehi_mod_hornboostmax;
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(veh, speed);
				}

			}
		}

		if (g_toggles.vehi_mod_carjump) {
			if (PAD::IS_CONTROL_JUST_PRESSED(0, 76)) {
				if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) {
					Vehicle veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
					ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0, 0, g_vars.vehi_mod_jumpheight, 0, 0, 0, true, true, true, true, false, true);
				}
			}
		}

		//SELF
		if (g_toggles.self_godmode) {
			ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), true);
		}
		else
		{
			ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), false);
		}
		if (g_toggles.self_alpha_enb) {
			ENTITY::SET_ENTITY_ALPHA(PLAYER::PLAYER_PED_ID(), g_vars.self_alpha, false);
			ENTITY::SET_ENTITY_ALPHA(PLAYER::PLAYER_ID(), g_vars.self_alpha, false);
		}
		else {
			ENTITY::SET_ENTITY_ALPHA(PLAYER::PLAYER_PED_ID(), 255, false);
			ENTITY::SET_ENTITY_ALPHA(PLAYER::PLAYER_ID(), 255, false);
		}
		if (g_toggles.self_ultrarun) {
			if (TASK::IS_PED_RUNNING(PLAYER::PLAYER_PED_ID()) || TASK::IS_PED_SPRINTING(PLAYER::PLAYER_PED_ID()) && !PED::IS_PED_RUNNING_RAGDOLL_TASK(PLAYER::PLAYER_PED_ID()))
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(PLAYER::PLAYER_PED_ID(), true, 0.0f, g_vars.self_ultrarun_speed, 0.0f, 0, 0, 0, true, true, true, true, false, true);
			}
		}

		if (g_toggles.self_invisible) {
			ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), 0, 0);
			ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_ID(), 0, 0);
			ENTITY::SET_ENTITY_ALPHA(PLAYER::PLAYER_PED_ID(), 200, 0);
			ENTITY::SET_ENTITY_ALPHA(PLAYER::PLAYER_ID(), 200, 0);
			NETWORK::SET_PLAYER_VISIBLE_LOCALLY(PLAYER::PLAYER_ID(), true);
		}
		else {
			ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), 1, 0);
			ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_ID(), 1, 0);
		}

		if (g_toggles.self_superjump) {
			//gta_util::get_local_ped()->m_playerinfo->m_frame_flags |= 1 << 14;
			if (g_vars.self_ultrajump_force > 0) {
				WEAPON::REMOVE_WEAPON_FROM_PED(PLAYER::PLAYER_PED_ID(), MISC::GET_HASH_KEY("GADGET_PARACHUTE"));
				if (PED::IS_PED_JUMPING(PLAYER::PLAYER_PED_ID()))
				{
					ENTITY::APPLY_FORCE_TO_ENTITY(PLAYER::PLAYER_PED_ID(), true, 0, 0, g_vars.self_ultrajump_force, 0, 0, 0, true, true, true, true, false, true);
				}
			}
		}

		if (g_toggles.self_ignoreme) {
			Entity player = PLAYER::PLAYER_PED_ID();
			PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
			PLAYER::SET_MAX_WANTED_LEVEL(0);
			PLAYER::SET_POLICE_IGNORE_PLAYER(player, true);
			PLAYER::SET_EVERYONE_IGNORE_PLAYER(player, true);
			PLAYER::SET_PLAYER_CAN_BE_HASSLED_BY_GANGS(player, false);
			PLAYER::SET_IGNORE_LOW_PRIORITY_SHOCKING_EVENTS(player, true);
		}
		else {
			Entity player = PLAYER::PLAYER_PED_ID();
			PLAYER::SET_MAX_WANTED_LEVEL(5);
			PLAYER::SET_POLICE_IGNORE_PLAYER(player, false);
			PLAYER::SET_EVERYONE_IGNORE_PLAYER(player, false);
			PLAYER::SET_PLAYER_CAN_BE_HASSLED_BY_GANGS(player, true);
			PLAYER::SET_IGNORE_LOW_PRIORITY_SHOCKING_EVENTS(player, false);
		}

		if (g_toggles.self_nonoise) {
			PLAYER::SET_PLAYER_NOISE_MULTIPLIER(PLAYER::PLAYER_ID(), g_vars.self_nonoise_mult);
		}
		else {
			PLAYER::SET_PLAYER_NOISE_MULTIPLIER(PLAYER::PLAYER_ID(), 1);
		}

		if (g_toggles.self_seatbelt) {
			PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER::PLAYER_PED_ID(), 1);
		}
		else {
			PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER::PLAYER_PED_ID(), 0);
		}

		if (g_toggles.self_nocops) {
			PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());
			PLAYER::SET_MAX_WANTED_LEVEL(0);
			PLAYER::SET_POLICE_IGNORE_PLAYER(PLAYER::PLAYER_ID(), true);
		}
		else {
			PLAYER::SET_MAX_WANTED_LEVEL(5);
			PLAYER::SET_POLICE_IGNORE_PLAYER(PLAYER::PLAYER_ID(), false);
		}

		if (g_toggles.self_nogangs) {
			PLAYER::SET_PLAYER_CAN_BE_HASSLED_BY_GANGS(PLAYER::PLAYER_ID(), false);
		}
		else {
			PLAYER::SET_PLAYER_CAN_BE_HASSLED_BY_GANGS(PLAYER::PLAYER_ID(), true);

		}

		if (g_toggles.self_noragdoll) {
			PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER::PLAYER_PED_ID(), false);
			PED::SET_PED_CAN_RAGDOLL(PLAYER::PLAYER_PED_ID(), false);
		}
		else {
			PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER::PLAYER_PED_ID(), true);
			PED::SET_PED_CAN_RAGDOLL(PLAYER::PLAYER_PED_ID(), true);
		}

		if (g_toggles.self_offradar) {
			*script_global(2424073 + 1 + PLAYER::PLAYER_ID() * 421 + 200).as<bool*>() = true;
			*script_global(2437549 + 70).as<int*>() = NETWORK::GET_NETWORK_TIME();
		}

		if (g_toggles.self_superman) {
			Hash hash = MISC::GET_HASH_KEY("GADGET_PARACHUTE");
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), hash, 1, 1);
			PLAYER::SET_PLAYER_INVINCIBLE(PLAYER::PLAYER_ID(), 1);
			PED::SET_PED_TO_RAGDOLL_WITH_FALL(PLAYER::PLAYER_PED_ID(), 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);
			g_fiber_pool->queue_job([] {
				if (PAD::IS_CONTROL_PRESSED(0, 32)) // W key
				{
					ENTITY::APPLY_FORCE_TO_ENTITY(PLAYER::PLAYER_PED_ID(), true, 3, 0, 0, 0, 0, 0, 0, true, true, true, true, true);
				}

				if (PAD::IS_CONTROL_PRESSED(0, 33)) // S key
				{
					ENTITY::APPLY_FORCE_TO_ENTITY(PLAYER::PLAYER_PED_ID(), true, 3, 6, 0, 0, 0, 0, 0, true, true, true, true, true);
				}
				if (PAD::IS_CONTROL_PRESSED(0, 21)) //VK_SHIFT
				{
					ENTITY::APPLY_FORCE_TO_ENTITY(PLAYER::PLAYER_PED_ID(), true, 0, 0, -6, 0, 0, 0, 0, true, true, true, true, true);
				}
				if (PAD::IS_CONTROL_PRESSED(0, 21)) //SPACE
				{
					ENTITY::APPLY_FORCE_TO_ENTITY(PLAYER::PLAYER_PED_ID(), true, 0, 0, 6, 0, 0, 0, 0, true, true, true, true, true);
				}
			});
		}

		//WEAPON
		int64_t wflags;

		if (g_toggles.weps_delete_gun)
		{
			g_fiber_pool->queue_job([] {
				if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID())) {
					Object object;
					PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &object);
					NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(object);
					ENTITY::SET_ENTITY_AS_MISSION_ENTITY(object, true, true);
					ENTITY::DELETE_ENTITY(&object);
				}
			});
		}

		if (g_toggles.weps_explosive_melee) {
			//gta_util::get_local_ped()->m_playerinfo->m_frame_flags |= 1 << 13;
		}

		if (g_toggles.weps_fire_ammo)
		{
			//gta_util::get_local_ped()->m_playerinfo->m_frame_flags |= 1 << 12;
		}

		if (g_toggles.weps_explosive_ammo)
		{
			//gta_util::get_local_ped()->m_playerinfo->m_frame_flags |= 1 << 11;
		}



		if (g_toggles.weps_laser_pointer) {
			g_fiber_pool->queue_job([] {
				Entity EntityTarget;
				Player player = PLAYER::PLAYER_ID();
				Ped playerPed = PLAYER::PLAYER_PED_ID();

				Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
				Vector3 dir = g_c_functions.rot_to_direction(&rot);
				Vector3 camPosition = CAM::GET_GAMEPLAY_CAM_COORD();
				Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				float spawnDistance = g_c_functions.get_distance(&camPosition, &playerPosition);
				spawnDistance += 5;
				Vector3 spawnPosition = g_c_functions.add(&camPosition, &g_c_functions.multiply(&dir, spawnDistance));

				if (PLAYER::IS_PLAYER_FREE_AIMING(PLAYER::PLAYER_ID())) {
					Vector3 FromCoord = PED::GET_PED_BONE_COORDS(PLAYER::PLAYER_PED_ID(), 57005, 0, 0, 0);
					GRAPHICS::DRAW_LINE(FromCoord.x, FromCoord.y, FromCoord.z, spawnPosition.x, spawnPosition.y, spawnPosition.z, 255, 0, 255, 255);

					/*int max = int(300 + 0.5);
					for (int i = 0; i >= max; ++i)
					{
						float CurDistance = i;
						Vector3 Coord = GetCoordsFromCam(CurDistance);
						GRAPHICS::DRAW_LIGHT_WITH_RANGE(Coord.x, Coord.y, Coord.z, 255, 0, 255, 1, 3);
					}*/
				}
			});

		}

		if (g_toggles.weps_no_reload)
		{
			Hash cur;
			if (WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &cur, 1))
			{
				if (WEAPON::IS_WEAPON_VALID(cur))
				{
					int maxAmmo;
					if (WEAPON::GET_MAX_AMMO(PLAYER::PLAYER_PED_ID(), cur, &maxAmmo))
					{
						WEAPON::SET_PED_AMMO(PLAYER::PLAYER_PED_ID(), cur, maxAmmo, true);

						maxAmmo = WEAPON::GET_MAX_AMMO_IN_CLIP(PLAYER::PLAYER_PED_ID(), cur, 1);
						if (maxAmmo > 0)
							WEAPON::SET_AMMO_IN_CLIP(PLAYER::PLAYER_PED_ID(), cur, maxAmmo);
					}
				}
			}
		}

		if (g_toggles.weps_infinite_ammo) {
			WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), true);
		}
		else {
			WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), false);
		}

		if (g_toggles.weps_money_ammo)
		{
			if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID())) {
				Vector3 tmp[3];
				WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), tmp);
				if (tmp->x != 0 && tmp->y != 0 && tmp->z != 0)
					OBJECT::CREATE_AMBIENT_PICKUP(MISC::GET_HASH_KEY("PICKUP_MONEY_MED_BAG"), tmp->x, tmp->y, tmp->z, 0, g_vars.money_gun_amount, 1, 0, 1);
			}
		}

		if (g_toggles.weps_teleport_gun) {

			if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID())) {
				Vector3 tmp[3];
				WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(PLAYER::PLAYER_PED_ID(), tmp);
				if (tmp->x != 0 && tmp->y != 0 && tmp->z != 0)
					ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), tmp->x, tmp->y, tmp->z + 1, 0, 0, 1, 0);
			}
		}

		if (g_toggles.weps_gravity_gun) {
			g_fiber_pool->queue_job([] {
				Entity EntityTarget;
				Player player = PLAYER::PLAYER_ID();
				Ped playerPed = PLAYER::PLAYER_PED_ID();

				Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(0);
				Vector3 dir = g_c_functions.rot_to_direction(&rot);
				Vector3 camPosition = CAM::GET_GAMEPLAY_CAM_COORD();
				Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
				float spawnDistance = g_c_functions.get_distance(&camPosition, &playerPosition);
				spawnDistance += 5;
				Vector3 spawnPosition = g_c_functions.add(&camPosition, &g_c_functions.multiply(&dir, spawnDistance));


				Player tempPed = PLAYER::PLAYER_ID();
				if (g_toggles.grav_target_locked)
				{
					if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget) && GetAsyncKeyState(VK_RBUTTON))
					{
						Vector3 EntityTargetPos = ENTITY::GET_ENTITY_COORDS(EntityTarget, 0);
						PLAYER::DISABLE_PLAYER_FIRING(tempPed, true);
						if (ENTITY::IS_ENTITY_A_PED(EntityTarget) && PED::IS_PED_IN_ANY_VEHICLE(EntityTarget, 1))
						{
							EntityTarget = PED::GET_VEHICLE_PED_IS_IN(EntityTarget, 0);
						}

						g_c_functions.RequestControl(EntityTarget);
						if (ENTITY::IS_ENTITY_A_PED(EntityTarget) || ENTITY::IS_ENTITY_A_VEHICLE(EntityTarget)) {
							if (ENTITY::IS_ENTITY_A_VEHICLE(EntityTarget)) ENTITY::SET_ENTITY_HEADING(EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));

							ENTITY::SET_ENTITY_COORDS_NO_OFFSET(EntityTarget, spawnPosition.x, spawnPosition.y, spawnPosition.z, 0, 0, 0);
						}

						if (GetAsyncKeyState(VK_LBUTTON))
						{
							ENTITY::SET_ENTITY_HEADING(EntityTarget, ENTITY::GET_ENTITY_HEADING(tempPed));
							ENTITY::APPLY_FORCE_TO_ENTITY(EntityTarget, 1, dir.x * 10000.0f, dir.y * 10000.0f, dir.z * 10000.0f, 0.0f, 0.0f, 0.0f, 0, 0, 1, 1, 0, 1);
							g_toggles.grav_target_locked = false;
							PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
						}
					}
				}
				if (!PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &EntityTarget))
				{
					g_toggles.grav_target_locked = true;
					PLAYER::DISABLE_PLAYER_FIRING(tempPed, false);
				}
			});
		}

		if (g_toggles.weps_silent_aim) {
			g_fiber_pool->queue_job([] {
				Entity ent;
				if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PLAYER::PLAYER_ID(), &ent)) {
					if (ENTITY::IS_ENTITY_A_PED(ent)) {
						g_c_functions.shootAtPed(ent, 31086);
					}
				}
			});
		}

		if (g_toggles.weps_multiplier_enb) {
			PED::SET_AI_WEAPON_DAMAGE_MODIFIER(g_vars.range_damage_multiplier);
			PED::SET_AI_MELEE_WEAPON_DAMAGE_MODIFIER(g_vars.meele_damage_multiplier);
		}
		else {
			PED::RESET_AI_WEAPON_DAMAGE_MODIFIER();
			PED::RESET_AI_MELEE_WEAPON_DAMAGE_MODIFIER();

		}
		//VISUAL
		if (g_toggles.visu_name_esp) {
			g_fiber_pool->queue_job([] {
				Player playerPed = PLAYER::PLAYER_PED_ID();
				for (int i = 0; i < 32; i++)
				{
					Player playerHandle = PLAYER::GET_PLAYER_PED(i);
					Vector3 handleCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerHandle, 0, 0, 0);
					Vector3 playerCoords = ENTITY::GET_ENTITY_COORDS(playerPed, 0);
					char* Name = (char*)PLAYER::GET_PLAYER_NAME(PLAYER::INT_TO_PLAYERINDEX(i));

					if (ENTITY::DOES_ENTITY_EXIST(playerHandle))
					{
						float x1;
						float y1;

						BOOL screenCoords = GRAPHICS::_WORLD3D_TO_SCREEN2D(handleCoords.x, handleCoords.y, handleCoords.z, &x1, &y1);
						std::string playerName = PLAYER::GET_PLAYER_NAME(PLAYER::INT_TO_PLAYERINDEX(i));

						float distance = g_c_functions.get_distance(&playerCoords, &handleCoords);

						std::string nameSetup = "~HUD_COLOUR_WHITE~" + playerName;
						if (g_toggles.visu_friend_esp) {
							if (g_c_functions.IsPlayerFriend(PLAYER::INT_TO_PLAYERINDEX(i)) && PLAYER::INT_TO_PLAYERINDEX(i) != PLAYER::PLAYER_ID()) {
								nameSetup = "~HUD_COLOUR_GREEN~" + playerName;
							}
						}
						if (g_toggles.visu_yourself_esp) {
							if (PLAYER::INT_TO_PLAYERINDEX(i) == PLAYER::PLAYER_ID()) {
								nameSetup = "~HUD_COLOUR_GREEN~" + playerName;
							}
						}

						char* playerInfo = new char[nameSetup.length() + 1];

						std::strcpy(playerInfo, nameSetup.c_str());



						float fontsize = 1;

						fontsize = 1 / (distance / 140);

						if (fontsize < 0.2) {
							fontsize = 0.2;
						}

						if (fontsize > 0.5) {
							fontsize = 0.50;
						}
						if (g_toggles.visu_yourself_esp) {
							HUD::SET_TEXT_FONT(g_vars.nameespfont);
							HUD::SET_TEXT_SCALE(0.0, fontsize);
							HUD::SET_TEXT_COLOUR(0, 255, 0, 255);
							HUD::SET_TEXT_CENTRE(0);
							HUD::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
							HUD::SET_TEXT_EDGE(0, 0, 0, 0, 0);
							HUD::_SET_TEXT_ENTRY("STRING");
							HUD::_ADD_TEXT_COMPONENT_STRING(playerInfo);
							HUD::_DRAW_TEXT(x1, y1);
							HUD::SET_TEXT_OUTLINE();
							HUD::SET_TEXT_DROPSHADOW(5, 0, 78, 255, 255);
						}
						else if (PLAYER::INT_TO_PLAYERINDEX(i) != PLAYER::PLAYER_ID()) {
							HUD::SET_TEXT_FONT(g_vars.nameespfont);
							HUD::SET_TEXT_SCALE(0.0, fontsize);
							HUD::SET_TEXT_COLOUR(0, 255, 0, 255);
							HUD::SET_TEXT_CENTRE(0);
							HUD::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
							HUD::SET_TEXT_EDGE(0, 0, 0, 0, 0);
							HUD::_SET_TEXT_ENTRY("STRING");
							HUD::_ADD_TEXT_COMPONENT_STRING(playerInfo);
							HUD::_DRAW_TEXT(x1, y1);
							HUD::SET_TEXT_OUTLINE();
							HUD::SET_TEXT_DROPSHADOW(5, 0, 78, 255, 255);
						}
					}
				}
			});
		}

		if (g_toggles.visu_tracers) {
			g_fiber_pool->queue_job([] {
				for (int i = 0; i < 32; i++) {
					if (!strcmp(PLAYER::GET_PLAYER_NAME(PLAYER::INT_TO_PLAYERINDEX(i)), "")) continue;
					{
						if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED(i)))
						{
							Player playerHandle = PLAYER::GET_PLAYER_PED(i);
							Player playerPed = PLAYER::PLAYER_PED_ID();
							int VehHandle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
							Vector3 getcoords1 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerHandle, 0, 0, 0);
							Vector3 getcoords3 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(playerPed, 0, 0, 0);
							float distance = g_c_functions.get_distance(&getcoords1, &getcoords3);
							float tracerColor2 = 1 / (distance / 140);

							if (g_toggles.visu_dynamic_tracer_alpha) {
								g_vars.tracerColor.w = 1;
								if (tracerColor2 < 0.4) {
									tracerColor2 = 0.4;
								}

								if (tracerColor2 > 1) {
									tracerColor2 = 1;
								}

							}
							else {
								tracerColor2 = 1;
							}
							GRAPHICS::DRAW_LINE(getcoords1.x, getcoords1.y, getcoords1.z, getcoords3.x, getcoords3.y, getcoords3.z, g_vars.tracerColor.x * 255, g_vars.tracerColor.y * 255, g_vars.tracerColor.z * 255, g_vars.tracerColor.w * 255 * tracerColor2);
						}
					}
				}
			});
		}

		if (g_toggles.visu_snow) {
			MISC::SET_WEATHER_TYPE_NOW_PERSIST("XMAS");
			*script_global(262145 + 4723).as<bool*>() = true;
			//g_pointers->m_SessionWeather(1, 9, 76, 0);
			GRAPHICS::_SET_FORCE_PED_FOOTSTEPS_TRACKS(1);
			GRAPHICS::_SET_FORCE_VEHICLE_TRAILS(1);
		}

		//RECOVERY

		//WORLD
		if (g_toggles.world_calm_peds) {
			g_fiber_pool->queue_job([] {
				set_all_nearby_peds_to_calm(PLAYER::PLAYER_ID());
			});
		}

		if (g_toggles.world_sync_time) {
			time_t now = time(0);
			tm t;
			localtime_s(&t, &now);
			CLOCK::SET_CLOCK_TIME(t.tm_hour, t.tm_min, t.tm_sec);
		}
		g_fiber_pool->queue_job([] {
			CLOCK::PAUSE_CLOCK(g_toggles.world_frezze_time);
		});
	}


	void gui::script_func()
	{
		g_gui.script_init();
		while (true)
		{
			g_gui.script_on_tick();
			script::get_current()->yield();
		}
	}
}
