#include "Functions.h"
#include "common.hpp"
#include "natives.hpp"
#include "script.hpp"
#include "pointers.hpp"

namespace big {
	void CFunctions::shootAtPed(Ped ped, int bone)
	{
		Vector3 Mouth = PED::GET_PED_BONE_COORDS(ped, bone, 0, 0, 0);
		PED::SET_PED_SHOOTS_AT_COORD(PLAYER::PLAYER_PED_ID(), Mouth.x, Mouth.y, Mouth.z, true);
	}
}