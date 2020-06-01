#include "Functions.h"
#include "common.hpp"
#include "natives.hpp"
#include "script.hpp"
#include "pointers.hpp"


namespace big {
	void CFunctions::getPlayerList() {
		playerCount = 0;
		for (int i = 0; i < 32; i++) {
			if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {
				playerCount++;
				Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
				Player player = NETWORK::NETWORK_GET_PLAYER_INDEX_FROM_PED(ped);
				players[i].name = NETWORK::NETWORK_PLAYER_GET_NAME(player);
				players[i].position = ENTITY::GET_ENTITY_COORDS(ped, true);
				players[i].health = ENTITY::GET_ENTITY_HEALTH(ped);
				players[i].maxHealth = ENTITY::GET_ENTITY_MAX_HEALTH(ped);
				players[i].armour = PED::GET_PED_ARMOUR(ped);
				players[i].maxArmour = PLAYER::GET_PLAYER_MAX_ARMOUR(player);
				players[i].wantedLevel = PLAYER::GET_PLAYER_WANTED_LEVEL(player);
				int interior = INTERIOR::GET_INTERIOR_FROM_ENTITY(ped);
				if (interior == 0) {
					players[i].inInterior = false;
				}
				else {
					players[i].inInterior = true;
				}
				if (PED::IS_PED_IN_ANY_VEHICLE(ped, false)) {
					players[i].playerVehicle = PED::GET_VEHICLE_PED_IS_USING(ped);
					players[i].vehiclehash = ENTITY::GET_ENTITY_MODEL(players[i].playerVehicle);
					players[i].vehicleName = VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(players[i].vehiclehash);
					players[i].isInVehicle = true;
				}
				else {
					players[i].isInVehicle = false;
				}
				Hash streetname;
				Hash intersaction;
				PATHFIND::GET_STREET_NAME_AT_COORD(players[i].position.x, players[i].position.y, players[i].position.z, &streetname, &intersaction);
				players[i].streetname = HUD::GET_STREET_NAME_FROM_HASH_KEY(streetname);

				players[i].zonename = ZONE::GET_NAME_OF_ZONE(players[i].position.x, players[i].position.y, players[i].position.z);
				players[i].inCutscene = NETWORK::IS_PLAYER_IN_CUTSCENE(player);
				players[i].passiveMode = false;
				players[i].mutedMe = NETWORK::NETWORK_AM_I_MUTED_BY_PLAYER(player);
				players[i].isInvincible = PLAYER::GET_PLAYER_INVINCIBLE(player);
			}
			else {
				players[i].name = "NOTCONNECTED";
			}
		}
	}
}