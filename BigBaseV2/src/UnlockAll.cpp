#include "Functions.h"
#include "natives.hpp"

namespace big {
	void CFunctions::UnlockAll() {
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STAM"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STRN"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_LUNG"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_DRIV"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_FLY"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_SHO"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STL"), 100, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP0_AWD_FMRACEWORLDRECHOLDER"), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_ENEMYDRIVEBYKILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_USJS_COMPLETED"), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_USJS_FOUND"), 50, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP0_AWD_FMWINALLRACEMODES"), 1, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP0_AWD_FMWINEVERYGAMEMODE"), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_DB_PLAYER_KILLS"), 1000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_KILLS_PLAYERS"), 1000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FMHORDWAVESSURVIVE"), 21, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FM_TDM_MVP"), 60, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_HOLD_UP_SHOPS"), 20, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_RACES_WON"), 101, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_NO_ARMWRESTLING_WINS"), 21, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP0_AWD_FMATTGANGHQ"), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FMBBETWIN"), 50000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 51, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP0_AWD_FMFULLYMODDEDCAR"), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FM_DM_TOTALKILLS"), 500, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MPPLY_DM_TOTAL_DEATHS"), 412, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MPPLY_TIMES_FINISH_DM_TOP_3"), 36, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_PLAYER_HEADSHOTS"), 623, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FM_DM_WINS"), 63, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FM_TDM_WINS"), 13, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FM_GTA_RACES_WON"), 12, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FM_GOLF_WON"), 2, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_TG_WON"), 2, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_RT_WON"), 2, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_CT_WON"), 2, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FM_SHOOTRANG_GRAN_WON"), 2, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_FM_TENNIS_WON"), 2, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MPPLY_TENNIS_MATCHES_WON"), 2, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MPPLY_TOTAL_TDEATHMATCH_WON"), 63, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MPPLY_TOTAL_RACES_WON"), 101, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MPPLY_TOTAL_DEATHMATCH_LOST"), 23, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MPPLY_TOTAL_RACES_LOST"), 36, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_25_KILLS_STICKYBOMBS"), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_50_KILLS_GRENADES"), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_GRENADE_ENEMY_KILLS"), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_AWD_20_KILLS_MELEE"), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MOLOTOV_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CMBTPISTOL_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_PISTOL50_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_APPISTOL_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MICROSMG_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SMG_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ASLTSMG_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ASLTRIFLE_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CRBNRIFLE_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ADVRIFLE_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MG_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CMBTMG_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ASLTMG_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_PUMP_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SAWNOFF_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_BULLPUP_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_ASLTSHTGN_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SNIPERRFL_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_HVYSNIPER_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_GRNLAUNCH_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_RPG_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MINIGUNS_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_GRENADE_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SMKGRENADE_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_STKYBMB_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_MOLOTOV_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_HAIR_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_JBIB_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_LEGS_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_FEET_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_BERD_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_8"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_9"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_PROPS_10"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_OUTFIT"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_5"), -1, 1);;
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_HAIR_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_JBIB_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_6"), -1, 1);;
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_LEGS_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_FEET_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_BERD_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_8"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_9"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_PROPS_10"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_OUTFIT"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TORSO"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_SPECIAL2_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_DECL"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TEETH"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TEETH_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_AVAILABLE_TEETH_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TORSO"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_SPECIAL2_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_DECL"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_CLTHS_ACQUIRED_TEETH"), -1, 1);

		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_STAM"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_STRN"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_LUNG"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_DRIV"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_FLY"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_SHO"), 100, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_STL"), 100, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP1_AWD_FMRACEWORLDRECHOLDER"), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_ENEMYDRIVEBYKILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_USJS_COMPLETED"), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_USJS_FOUND"), 50, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP1_AWD_FMWINALLRACEMODES"), 1, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP1_AWD_FMWINEVERYGAMEMODE"), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_DB_PLAYER_KILLS"), 1000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_KILLS_PLAYERS"), 1000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FMHORDWAVESSURVIVE"), 21, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_CAR_BOMBS_ENEMY_KILLS"), 25, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FM_TDM_MVP"), 60, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_HOLD_UP_SHOPS"), 20, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_RACES_WON"), 101, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_NO_ARMWRESTLING_WINS"), 21, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP1_AWD_FMATTGANGHQ"), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FMBBETWIN"), 50000, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FM_DM_WINS"), 51, 1);
		STATS::STAT_SET_BOOL(MISC::GET_HASH_KEY("MP1_AWD_FMFULLYMODDEDCAR"), 1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FM_DM_TOTALKILLS"), 500, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_MPPLY_DM_TOTAL_DEATHS"), 412, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_MPPLY_TIMES_FINISH_DM_TOP_3"), 36, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_PLAYER_HEADSHOTS"), 623, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FM_DM_WINS"), 63, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FM_TDM_WINS"), 13, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FM_GTA_RACES_WON"), 12, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FM_GOLF_WON"), 2, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FM_SHOOTRANG_TG_WON"), 2, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FM_SHOOTRANG_RT_WON"), 2, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FM_SHOOTRANG_CT_WON"), 2, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FM_SHOOTRANG_GRAN_WON"), 2, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_FM_TENNIS_WON"), 2, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_MPPLY_TENNIS_MATCHES_WON"), 2, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_MPPLY_TOTAL_TDEATHMATCH_WON"), 63, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_MPPLY_TOTAL_RACES_WON"), 101, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_MPPLY_TOTAL_DEATHMATCH_LOST"), 23, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_MPPLY_TOTAL_RACES_LOST"), 36, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_25_KILLS_STICKYBOMBS"), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_50_KILLS_GRENADES"), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_GRENADE_ENEMY_KILLS"), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_AWD_20_KILLS_MELEE"), 50, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_MOLOTOV_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CMBTPISTOL_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_PISTOL50_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_APPISTOL_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_MICROSMG_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SMG_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_ASLTSMG_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_ASLTRIFLE_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CRBNRIFLE_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_ADVRIFLE_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_MG_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CMBTMG_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_ASLTMG_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_PUMP_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SAWNOFF_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_BULLPUP_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_ASLTSHTGN_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SNIPERRFL_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_HVYSNIPER_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_GRNLAUNCH_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_RPG_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_MINIGUNS_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_GRENADE_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SMKGRENADE_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_STKYBMB_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_MOLOTOV_ENEMY_KILLS"), 600, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_FEET_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_HAIR"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_HAIR_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_HAIR_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_HAIR_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_HAIR_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_HAIR_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_HAIR_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_HAIR_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_JBIB"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_JBIB_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_JBIB_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_JBIB_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_JBIB_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_JBIB_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_JBIB_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_JBIB_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_LEGS"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_LEGS_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_LEGS_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_LEGS_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_LEGS_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_LEGS_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_LEGS_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_LEGS_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_FEET"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_FEET_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_FEET_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_FEET_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_FEET_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_FEET_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_FEET_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_FEET_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_BERD"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_BERD_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_BERD_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_BERD_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_BERD_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_BERD_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_BERD_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_BERD_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_PROPS"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_PROPS_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_PROPS_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_PROPS_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_PROPS_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_PROPS_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_PROPS_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_PROPS_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_PROPS_8"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_PROPS_9"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_PROPS_10"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_OUTFIT"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_HAIR"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_HAIR_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_HAIR_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_HAIR_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_HAIR_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_HAIR_5"), -1, 1);;
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_HAIR_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_HAIR_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_JBIB"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_JBIB_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_JBIB_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_JBIB_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_JBIB_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_JBIB_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_JBIB_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_JBIB_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_LEGS"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_LEGS_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_LEGS_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_LEGS_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_LEGS_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_LEGS_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_LEGS_6"), -1, 1);;
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_LEGS_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_FEET"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_FEET_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_FEET_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_FEET_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_FEET_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_FEET_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_FEET_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_FEET_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_BERD"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_BERD_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_BERD_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_BERD_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_BERD_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_BERD_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_BERD_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_BERD_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_8"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_9"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_PROPS_10"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_OUTFIT"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_TORSO"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_SPECIAL2_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_DECL"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_TEETH"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_TEETH_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_AVAILABLE_TEETH_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_TORSO"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL_2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL_3"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL_4"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL_5"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL_6"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL_7"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL2"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_SPECIAL2_1"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_DECL"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_CLTHS_ACQUIRED_TEETH"), -1, 1);



		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_REV_DA_IN_POSSESSION"), -1, 1);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STAM"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STRN"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_LUNG"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_DRIV"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_FLY"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_SHO"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP0_SCRIPT_INCREASE_STL"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_STAM"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_STRN"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_LUNG"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_DRIV"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_FLY"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_SHO"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MP1_SCRIPT_INCREASE_STL"), 100, 0);
		STATS::STAT_SET_INT(MISC::GET_HASH_KEY("MPPLY_VEHICLE_ID_ADMIN_WEB"), 117401876, 1);
	}
}