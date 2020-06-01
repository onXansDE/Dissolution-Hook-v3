#include "Functions.h"
#include "common.hpp"
#include "natives.hpp"
#include "script.hpp"
#include "pointers.hpp"

namespace big {


	float CFunctions::get_distance(Vector3* pointA, Vector3* pointB)
	{
		float a_x = pointA->x;
		float a_y = pointA->y;
		float a_z = pointA->z;

		float b_x = pointB->x;
		float b_y = pointB->y;
		float b_z = pointB->z;

		double x_ba = (double)(b_x - a_x);
		double y_ba = (double)(b_y - a_y);
		double z_ba = (double)(b_z - a_z);

		double y_2 = y_ba * y_ba;
		double x_2 = x_ba * x_ba;
		double sum_2 = y_2 + x_2;

		return (float)std::sqrt(sum_2 + z_ba);
	}
}