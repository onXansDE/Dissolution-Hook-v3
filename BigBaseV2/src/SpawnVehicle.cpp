#include "Functions.h"
#include "natives.hpp"
#include "script.hpp"
#include "pointers.hpp"

namespace big {
	void CFunctions::spawnVehicle(const char* name, bool maxed, bool inside) {
		auto hash = MISC::GET_HASH_KEY(name);
		while (!STREAMING::HAS_MODEL_LOADED(hash))
		{
			STREAMING::REQUEST_MODEL(hash);
			script::get_current()->yield();
		}

		auto pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		*(unsigned short*)g_pointers->m_model_spawn_bypass = 0x9090;
		auto vehicle = VEHICLE::CREATE_VEHICLE(hash, pos.x, pos.y, pos.z, 0.f, true, true,true);
		*(unsigned short*)g_pointers->m_model_spawn_bypass = 0x0574;

		script::get_current()->yield();
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
		if (*g_pointers->m_is_session_started)
		{
			DECORATOR::DECOR_SET_INT(vehicle, "MPBitset", 0);
			ENTITY::_SET_ENTITY_SOMETHING(vehicle, TRUE); //True means it can be deleted by the engine when switching lobbies/missions/etc, false means the script is expected to clean it up.
			auto networkId = NETWORK::VEH_TO_NET(vehicle);
			if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(vehicle))
				NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(networkId, true);
			VEHICLE::SET_VEHICLE_IS_STOLEN(vehicle, FALSE);
		}

		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
		if (inside) {
			ENTITY::SET_ENTITY_HEADING(vehicle, ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID()));
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), vehicle, -1);
		}
		if (maxed) {
			maxVehicle(vehicle);
		}
	}
}