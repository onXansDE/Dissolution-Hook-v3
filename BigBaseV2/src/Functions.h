#pragma once
#include "gta_util.hpp"

namespace big {
	class CFunctions {
	public:
        //SELF
        Vector3 myCords;
        void getMyCords();
		//RECOVERY
		void UnlockAll();
		void SetRank(int rpvalue);

		//VEHICLE
		void spawnVehicle(const char* name, bool maxed, bool inside);
		void maxVehicle(Vehicle veh);

		//WEAPONS
		void giveAllWeapons();
		void shootAtPed(Ped ped, int bone);

		//NETWORK
		bool IsPlayerFriend(Player player);
		void RequestControl(Entity input);
		void RequestControlOfid(Entity selectedPlayer);
        void getPlayerList();
        struct NPlayer {
            std::string name;
            bool selected;

            Player player;
            Ped ped;

            int health;
            int maxHealth;
            int armour;
            int maxArmour;
            int wantedLevel;
            bool inInterior;
            bool isInVehicle;
            bool isInvincible;
            Vehicle playerVehicle;
            std::string vehicleName;
            Hash vehiclehash;
            Vector3 position;
            std::string streetname;
            std::string zonename;
            float killdeathrate;
            float accuracy;
            bool inCutscene;
            bool passiveMode;
            bool mutedMe;

            int walletmoney;
            int bankmoney;

            int rank;
            bool inputmethod;
            bool modder;
            bool rockstar;
            bool scripthost;
            bool sessionhost;

            std::string externip;
            std::string internip;
            int port;
            int* networkhandle;

            char* socialclubid;
            NPlayer() {}

            bool operator<(const NPlayer& o)  const {
                return name == o.name || player == o.player;
            }
        };
        int playerCount;

        NPlayer players[32];
        std::map<NPlayer, char*> selected;

		//VECTORS
		Vector3 GetCoordsFromCam(int distance);
		float get_distance(Vector3* pointA, Vector3* pointB);
		float get_vector_length(Vector3* vector);
		Vector3 add(Vector3* vectorA, Vector3* vectorB);
		Vector3 multiply(Vector3* vector, float x);
		Vector3 rot_to_direction(Vector3* rot);
	};

	inline CFunctions g_c_functions;
}