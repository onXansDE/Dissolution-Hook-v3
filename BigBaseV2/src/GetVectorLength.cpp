#include "Functions.h"
#include "common.hpp"
#include "natives.hpp"
#include "script.hpp"
#include "pointers.hpp"

namespace big {
	float CFunctions::get_vector_length(Vector3* vector)
	{
		double x = (double)vector->x;
		double y = (double)vector->y;
		double z = (double)vector->z;

		return (float)std::sqrt(x * x + y * y + z * z);
	}
}