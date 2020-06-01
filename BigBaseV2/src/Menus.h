#pragma once
#include "common.hpp"
#include "imgui.h"

namespace big {
	class RMenus {
	public:
		void render() {
			render_main_menu();
			render_self_menu();
			render_vehicle_menu();
			render_weapon_menu();
			render_recovery_menu();
			render_world_menu();
			render_network_menu();
			render_visuals_menu();
			render_theme_menu();
		}

		bool show_self_menu{};
		bool show_network_menu{};
		bool show_world_menu{};
		bool show_vehicle_menu{};
		bool show_recovery_menu{};
		bool show_debug_menu{};
		bool show_advanced_lsc_menu{};
		bool show_weapon_menu{};
		bool show_playerlist_tab{};
		bool show_visuals_menu{};

		bool show_theme_menu{};


		ImVec2 default_button_size = ImVec2(130, 20);
		ImVec2 long_button_size = ImVec2(220, 30);
		ImVec2 small_button_size = ImVec2(100, 30);
		ImVec2 medium_button_size = ImVec2(150, 30);
		ImVec2 big_button_size = ImVec2(230, 40);


	private:
		void render_main_menu();
		void render_self_menu();
		void render_vehicle_menu();
		void render_weapon_menu();
		void render_recovery_menu();
		void render_world_menu();
		void render_network_menu();
		void render_visuals_menu();
		void render_theme_menu();

	};

	inline RMenus g_menus;
}