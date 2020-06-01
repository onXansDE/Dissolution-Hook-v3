#include "Functions.h"
#include "common.hpp"
#include "natives.hpp"
#include "script.hpp"
#include "pointers.hpp"

namespace big {
	Vector3 CFunctions::rot_to_direction(Vector3* rot)
	{
		float radiansZ = rot->z * 0.0174532924f;
		float radiansX = rot->x * 0.0174532924f;
		float num = std::abs((float)std::cos((double)radiansX));
		Vector3 dir;
		dir.x = (float)((double)((float)(-(float)std::sin((double)radiansZ))) * (double)num);
		dir.y = (float)((double)((float)std::cos((double)radiansZ)) * (double)num);
		dir.z = (float)std::sin((double)radiansX);
		return dir;
	}
}