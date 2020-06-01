#include "general.h"
#include "common.hpp"
#include "nlohmann/json.hpp"

namespace big {
	void CGeneral::getThemeList() {
		std::filesystem::path m_file_path = std::getenv("appdata");
		m_file_path /= "DslHookGtav3";

		if (!std::filesystem::exists(m_file_path))
		{
			std::filesystem::create_directory(m_file_path);
		}
		else if (!std::filesystem::is_directory(m_file_path))
		{
			std::filesystem::remove(m_file_path);
			std::filesystem::create_directory(m_file_path);
		}

		m_file_path /= "Themes";

		if (!std::filesystem::exists(m_file_path))
		{
			std::filesystem::create_directory(m_file_path);
		}
		else if (!std::filesystem::is_directory(m_file_path))
		{
			std::filesystem::remove(m_file_path);
			std::filesystem::create_directory(m_file_path);
		}

		int i = 0;
		for (const auto& entry : std::filesystem::directory_iterator(m_file_path)) {
			if (i <= 100) {
				themes[i] = entry.path().filename().string();
				i++;
			}
		}
	}
}