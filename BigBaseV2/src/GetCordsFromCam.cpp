#include "Functions.h"
#include "common.hpp"
#include "natives.hpp"
#include "script.hpp"
#include "pointers.hpp"

namespace big {

	Vector3 CFunctions::GetCoordsFromCam(int distance)
	{
		Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(2);
		Vector3 coord = CAM::GET_GAMEPLAY_CAM_COORD();

		int tZ = rot.z * 0.0174532924;
		int tX = rot.x * 0.0174532924;
		int num = std::abs(std::cos(tX));

		coord.x = coord.x + (-std::sin(tZ)) * (num + distance);
		coord.y = coord.y + (std::cos(tZ)) * (num + distance);
		coord.z = coord.z + std::sin(tX) * 8;

		return coord;
	}
}