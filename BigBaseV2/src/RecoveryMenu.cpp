#include "Menus.h"
#include "Toggles.h"
#include "Vars.h"
#include "imgui.h"
#include "natives.hpp"
#include "script_global.hpp"
#include "fiber_pool.hpp"

namespace big {


	ImVec2 reco_window_size = ImVec2(600, 400);

	void RMenus::render_recovery_menu() {
		if (g_menus.show_recovery_menu) {
			ImGui::SetNextWindowSize(reco_window_size, ImGuiCond_Once);
			if (ImGui::Begin("Recovery Options", &g_menus.show_recovery_menu)) {
				ImGui::Text("Money");
				ImGui::Separator();
				ImGui::Text("Stealth");

			}
			ImGui::End();
		}
	}
}