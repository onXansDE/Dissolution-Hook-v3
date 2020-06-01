#include "Functions.h"
#include "common.hpp"
#include "natives.hpp"
#include "script.hpp"
#include "pointers.hpp"

namespace big {
	Vector3 CFunctions::add(Vector3* vectorA, Vector3* vectorB) {
		Vector3 result;
		result.x = vectorA->x;
		result.y = vectorA->y;
		result.z = vectorA->z;

		result.x += vectorB->x;
		result.y += vectorB->y;
		result.z += vectorB->z;

		return result;
	}
}