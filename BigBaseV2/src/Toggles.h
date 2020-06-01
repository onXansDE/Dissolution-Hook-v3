#pragma once

namespace big {
	class CToggles {
	public:
		//SELF
		bool self_godmode = false;
		bool self_superjump = false;
		bool self_ultrajump = false;
		bool self_fastrun = false;
		bool self_fastswim = false;
		bool self_noclip = false;
		bool self_noragdoll = false;
		bool self_nonoise = false;
		bool self_invisible = false;
		bool self_offradar = false;
		bool self_ignoreme = false;
		bool self_superman = false;
		bool self_seatbelt = false;
		bool self_nocops = false;
		bool self_nogangs = false;
		bool self_ultrarun = false;
		bool self_alpha_enb = false;

		//VEHICLE
		bool vehi_spw_maxed = false;
		bool vehi_spw_inside = true;
		bool vehi_lsc_livecolor = true;
		bool vehi_lsc_animatedplate = false;
		bool vehi_mod_autorepair = false;
		bool vehi_mod_tireinvinc = false;
		bool vehi_mod_rainbow = false;
		bool vehi_mod_rablinkmode = true;
		bool vehi_mod_fadesync = false;
		bool vehi_mod_tireprime = false;
		bool vehi_mod_hornboost = false;
		bool vehi_mod_superboost = false;
		bool vehi_mod_carfly = false;
		bool vehi_mod_invisible = false;
		bool vehi_mod_enbmultipliers = false;
		bool vehi_mod_carjump = false;
		bool vehi_mod_tirainbow = false;
		bool vehi_mod_tiblinkmode = true;
		bool vehi_mod_raprimary = true;
		bool vehi_mod_rasecondary = true;
		bool vehi_mod_sticky = false;
		bool vehi_mod_drift = false;
		bool vehi_mod_cargod = false;
		bool vehi_light_mtp_en = false;

		//WEAPON
		bool weps_infinite_ammo = false;
		bool weps_no_reload = false;
		bool weps_fire_ammo = false;
		bool weps_explosive_ammo = false;
		bool weps_money_ammo = false;
		bool weps_teleport_gun = false;
		bool weps_explosive_melee = false;
		bool weps_infinite_parchutes = false;
		bool weps_delete_gun = false;
		bool weps_rapid_fire = false;
		bool weps_gravity_gun = false;
		bool weps_car_gun = false;
		bool weps_ped_gun = false;
		bool grav_target_locked = false;
		bool weps_laser_pointer = false;
		bool weps_silent_aim = false;
		bool weps_silent_aim_no_friends = true;
		bool weps_multiplier_enb = false;


		//WORLD
		bool world_sync_time = false;
		bool world_frezze_time = false;
		bool world_no_cars = false;
		bool world_calm_peds = false;

		//NETWORK
		bool lobby_drop_money = false;


		//VISUALS
		bool visu_name_esp = false;
		bool visu_health_esp = false;
		bool visu_friend_esp = true;
		bool visu_yourself_esp = false;
		bool visu_tracers = false;
		bool visu_bone_esp = false;
		bool visu_dynamic_tracer_alpha = false;
	};
	inline CToggles g_toggles;
}