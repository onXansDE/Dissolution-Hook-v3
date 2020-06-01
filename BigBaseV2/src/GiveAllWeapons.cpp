#include "Functions.h"
#include "common.hpp"
#include "natives.hpp"
#include "script.hpp"
#include "pointers.hpp"

namespace big {

	static Hash weapons[] =
	{
		//WEAPON_KNIFE WEAPON_NIGHTSTICK WEAPON_HAMMER WEAPON_BAT WEAPON_GOLFCLUB WEAPON_CROWBAR WEAPON_PISTOL WEAPON_COMBATPISTOL WEAPON_APPISTOL WEAPON_PISTOL50 
		0x99b507ea, 0x678b81b1, 0x4e875f73, 0x958a4a8f, 0x440e4788, 0x84bd7bfd, 0x1b06d571, 0x5ef9fec4, 0x22d8fe39, 0x99aeeb3b,
		//WEAPON_MICROSMG WEAPON_SMG WEAPON_ASSAULTSMG WEAPON_ASSAULTRIFLE WEAPON_CARBINERIFLE WEAPON_ADVANCEDRIFLE WEAPON_MG WEAPON_COMBATMG WEAPON_PUMPSHOTGUN WEAPON_SAWNOFFSHOTGUN
		0x13532244, 0x2be6766b, 0xefe7e2df, 0xbfefff6d, 0x83bf0278, 0xaf113f99, 0x9d07f764, 0x7fd62962, 0x1d073a89, 0x7846a318,
		//WEAPON_ASSAULTSHOTGUN WEAPON_BULLPUPSHOTGUN WEAPON_STUNGUN WEAPON_SNIPERRIFLE WEAPON_COMBATPDW WEAPON_HEAVYSNIPER WEAPON_GRENADELAUNCHER WEAPON_GRENADELAUNCHER_SMOKE WEAPON_RPG WEAPON_MINIGUN
		0xe284c527, 0x9d61e50f, 0x3656c8c1, 0x5fc3c11,  0xa3d4d34,  0xc472fe2,  0xa284510b, 0x4dd2dc56, 0xb1ca77b1, 0x42bf8a85,
		//WEAPON_GRENADE WEAPON_STICKYBOMB WEAPON_SMOKEGRENADE WEAPON_BZGAS WEAPON_MOLOTOV WEAPON_FIREEXTINGUISHER WEAPON_PETROLCAN WEAPON_KNUCKLE WEAPON_MARKSMANPISTOL WEAPON_SNSPISTOL
		0x93e220bd, 0x2c3731d9, 0xfdbc8a50, 0xa0973d5e, 0x24b17070, 0x60ec506,  0x34a67b97, 0xd8df3c3c, 0xdc4db296, 0xbfd21232,
		//WEAPON_SPECIALCARBINE WEAPON_HEAVYPISTOL WEAPON_BULLPUPRIFLE WEAPON_HOMINGLAUNCHER WEAPON_PROXMINE WEAPON_SNOWBALL WEAPON_VINTAGEPISTOL WEAPON_DAGGER WEAPON_FIREWORK WEAPON_MUSKET
		0xc0a3098d, 0xd205520e, 0x7f229f94, 0x63ab0442, 0xab564b93, 0x787f0bb,  0x83839c4,  0x92a27487, 0x7f7497e5, 0xa89cb99e,
		//WEAPON_MARKSMANRIFLE WEAPON_HEAVYSHOTGUN WEAPON_GUSENBERG WEAPON_HATCHET WEAPON_RAILGUN WEAPON_FLASHLIGHT WEAPON_MACHINEPISTOL WEAPON_MACHETE WEAPON_BAT WEAPON_SMOKEGRENADE
		0xc734385a, 0x3aabbbaa, 0x61012683, 0xf9dcbf2d, 0x6d544c99, 0x8bb05fd7, 0xdb1aa450, 0xdd5df8d9, 0x958a4a8f, 0xfdbc8a50,
		//WEAPON_DBSHOTGUN WEAPON_COMPACTRIFLE WEAPON_REVOLVER WEAPON_SWITCHBLADE
		0xef951fbb,	0x624fe830,	0xc1b3c3d1,	0xdfe37640,

		0xba45e8b8, 0x12e82d3d, 0xbd248b55, 0x0781fe4a, 0xcd274149, 0x94117305, 0x19044ee0

	};

	void CFunctions::giveAllWeapons() {
		for (Hash h : weapons) {
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), h, 9999, 0);
		}
	}
}