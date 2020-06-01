#include "Functions.h"
#include "common.hpp"
#include "natives.hpp"
#include "script.hpp"
#include "pointers.hpp"

namespace big {
	Vector3 CFunctions::multiply(Vector3* vector, float x)
	{
		Vector3 result;
		result.x = vector->x;
		result.y = vector->y;
		result.z = vector->z;

		result.x *= x;
		result.y *= x;
		result.z *= x;

		return result;
	}
}