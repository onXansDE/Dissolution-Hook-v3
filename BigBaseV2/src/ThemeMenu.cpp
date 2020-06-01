#include "Menus.h"
#include "common.hpp"
#include "general.h"

namespace big {


	static ImVec4 color_for_text = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
	static ImVec4 color_for_head = ImVec4(0.29f, 0.29f, 0.29f, 1.0f);
	static ImVec4 color_for_area = ImVec4(0.17f, 0.17f, 0.17f, 1.0f);
	static ImVec4 color_for_body = ImVec4(0.06f, 0.06f, 0.06f, 1.0f);
	static ImVec4 color_for_pops = ImVec4(0.08f, 0.08f, 0.08f, 1.0f);

	ImVec2 them_window_size = ImVec2(600, 400);
	ImVec2 them_list_window = ImVec2(200, 350);

	std::string selected = "dark";
	const char* themename = selected.c_str();

	void RMenus::render_theme_menu() {
		if (show_theme_menu) {
			themename = selected.c_str();
			ImGui::SetNextWindowSize(them_window_size);
			if (ImGui::Begin("Themes", &show_theme_menu, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoScrollbar)) {
				if (ImGui::BeginTable("themes1", 2)) {
					ImGui::TableNextRow();
					if (ImGui::BeginChild("themelist", them_list_window)) {
						ImGui::Text("CustomThemes");
						ImGui::Separator();

						for (std::string s : g_general.themes) {
							if (s.size() > 0) {
								if (ImGui::Selectable(s.c_str(), selected == s.c_str())) {
									selected = s;
								}
							}
						}

						ImGui::EndChild();
					}
					ImGui::TableNextCell();
					ImGui::Text("Options");
					ImGui::Text("Selected: %s", themename);
					if (ImGui::Button("Load Theme")) {
						g_general.loadTheme(themename);
					}
					if (ImGui::Button("Refresh")) {
						g_general.getThemeList();
					}
					ImGui::Spacing();
					ImGui::Text("Custom");
					ImGui::ColorEdit4("Text", (float*)&color_for_text, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoAlpha);
					ImGui::ColorEdit4("Head", (float*)&color_for_head, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoAlpha);
					ImGui::ColorEdit4("Area", (float*)&color_for_area, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoAlpha);
					ImGui::ColorEdit4("Body", (float*)&color_for_body, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoAlpha);
					ImGui::ColorEdit4("Pops", (float*)&color_for_pops, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoAlpha);
					if (ImGui::Button("Apply")) {
						g_general.imgui_easy_theming(CGeneral::ImVec3(color_for_text.x, color_for_text.y, color_for_text.z), CGeneral::ImVec3(color_for_head.x, color_for_head.y, color_for_head.z), CGeneral::ImVec3(color_for_area.x, color_for_area.y, color_for_area.z), CGeneral::ImVec3(color_for_body.x, color_for_body.y, color_for_body.z), CGeneral::ImVec3(color_for_pops.x, color_for_pops.y, color_for_pops.z));
					}

					static char name[32] = "mytheme";
					ImGui::InputText("Name", name, 32);
					if (ImGui::Button("Save")) {
						nlohmann::json themjson;
						themjson["name"] = name;
						themjson["text"]["red"] = color_for_text.x;
						themjson["text"]["green"] = color_for_text.y;
						themjson["text"]["blue"] = color_for_text.z;
						themjson["head"]["red"] = color_for_head.x;
						themjson["head"]["green"] = color_for_head.y;
						themjson["head"]["blue"] = color_for_head.z;
						themjson["area"]["red"] = color_for_area.x;
						themjson["area"]["green"] = color_for_area.y;
						themjson["area"]["blue"] = color_for_area.z;
						themjson["body"]["red"] = color_for_body.x;
						themjson["body"]["green"] = color_for_body.y;
						themjson["body"]["blue"] = color_for_body.z;
						themjson["pops"]["red"] = color_for_pops.x;
						themjson["pops"]["green"] = color_for_pops.y;
						themjson["pops"]["blue"] = color_for_pops.z;

						std::filesystem::path path = getenv("appdata");
						path /= "DslHookGtav3";
						path /= "Themes";
						std::string filename = name;
						filename.append(".json");
						path /= filename;

						if (!std::filesystem::exists(path)) {
							std::ofstream file(path);
							file << themjson.dump(4);
							file.close();
						}
						g_general.getThemeList();
					}
					ImGui::EndTable();
				}
			}
			ImGui::End();
		}
	}
}