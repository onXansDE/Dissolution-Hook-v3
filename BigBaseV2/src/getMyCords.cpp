#include "Functions.h"
#include "common.hpp"
#include "natives.hpp"
#include "script.hpp"
#include "pointers.hpp"

namespace big {
	void CFunctions::getMyCords() {
		g_c_functions.myCords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
	}
}