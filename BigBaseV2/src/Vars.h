#pragma once

namespace big {
	class CVars {
	public:
		//SELF
		float self_fastrun_speed = 2.0f;
		float self_fastswim_speed = 2.0f;
		float self_nonoise_mult = 0.0f;
		float self_ultrajump_force = 0.0f;
		float self_ultrarun_speed = 1.0f;

		int self_max_wanted_level = 5;
		int self_alpha = 255;

		//VEHICLE

		float car_speed_multiplier = 1.0f;
		float car_break_multiplier = 1.0f;
		float car_handling_multiplier = 1.0f;
		float car_grip_multiplier = 1.0f;
		float car_torque_multiplier = 1.0f;
		float car_light_multiplier = 1.0;
		float vehi_mod_jumpheight = 7.0f;
		float vehi_mod_hornboostamount = 40.0f;
		float vehi_mod_hornboostaccel = 0.02f;
		float vehi_mod_hornboostmax = 120.0f;
		float vehi_mod_flyaccel = 0.02f;
		float vehi_mod_flymaxspeed = 120.0f;
		float vehi_mod_superboostaccel = 0.02f;
		float vehi_mod_superboostamount = 3.0f;
		float vehi_mod_superboostmax = 120.0f;
		int vehi_mod_rainbowspeed = 1;
		long vehi_nextrainbow_step;
		long vehi_rainbow_step;

		int vehi_mod_movplatespeed = 100;
		long vehi_nextmovplate_step;
		long vehi_movplate_step;
		int vehi_moveplate_state = 0;

		const char* platesteps[7] = { "DSLHOOK", "SLHOOKD", "LHOOKDS", "HOOKDSL", "OOKDSLH", "OKDSLHO", "KDSLHOOK" };

		int fader1 = 255, fadeg1 = 0, fadeb1 = 0;
		int fader2 = 0, fadeg2 = 0, fadeb2 = 255;
		int blinkr1 = 255, blinkg1 = 0, blinkb1 = 0;
		int blinkr2 = 255, blinkg2 = 0, blinkb2 = 0;


		ImVec4 prim_color = ImVec4(235 / 255, 64 / 255, 52 / 255, 255 / 255);
		ImVec4 sec_color = ImVec4(36 / 255, 36 / 255, 36 / 255, 255 / 255);

		ImVec4 rain_color = ImVec4(70, 140, 240, 255);
		ImVec4 secrain_color = ImVec4(240, 140, 70, 255);

		//WEAPONS
		int money_gun_amount = 2500;
		float weps_aimbot_fov = 25.f;
		float range_damage_multiplier = 1.0f;
		float meele_damage_multiplier = 1.0f;

		//NETWORK

		int playerCount = 0;

		int selectedPlayer = -1;

		bool players[32];

		char* distances[32];

		int drop_money_speed = 1;
		long drop_nextmoney_step;
		long drop_money_step;

		//VISUALS
		int nameespfont = 1;
		ImVec4 tracerColor = ImVec4(1, 0, 1, 1);

		//NETWORK
		int net_step;
		int net_nextstep;
		int net_checkspeed = 50;
	};
	inline CVars g_vars;
}