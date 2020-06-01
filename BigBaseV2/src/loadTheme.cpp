#include "general.h"
#include "common.hpp"
#include "nlohmann/json.hpp"

namespace big {
	void CGeneral::loadTheme(const char* name) {
		std::filesystem::path path = std::getenv("appdata");
		path /= "DslHookGtav3";
		path /= "Themes";
		path /= name;

		std::fstream file;

		nlohmann::json themjson = {};

		if (std::filesystem::exists(path)) {
			file.open(path, std::fstream::in | std::fstream::out);
			themjson.clear();
			themjson << file;
			imgui_easy_theming(ImVec3(themjson["text"]["red"], themjson["text"]["green"], themjson["text"]["blue"]), ImVec3(themjson["head"]["red"], themjson["head"]["green"], themjson["head"]["blue"]), ImVec3(themjson["area"]["red"], themjson["area"]["green"], themjson["area"]["blue"]), ImVec3(themjson["body"]["red"], themjson["body"]["green"], themjson["body"]["blue"]), ImVec3(themjson["pops"]["red"], themjson["pops"]["green"], themjson["pops"]["blue"]));
			file.close();
		}
	}
}