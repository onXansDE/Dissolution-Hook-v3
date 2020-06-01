#include "Functions.h"
#include "common.hpp"
#include "natives.hpp"
#include "script.hpp"
#include "pointers.hpp"

namespace big {
	bool CFunctions::IsPlayerFriend(Player player) {
		BOOL BplayerFriend = false;
		bool bplayerFriend = false;
		int handle[76]; //var num3 = sub_34009(A_0, (A_1) + 264, (A_1) + 272);
		NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, &handle[0], 13);
		if (NETWORK::NETWORK_IS_HANDLE_VALID(&handle[0], 13))
		{
			BplayerFriend = NETWORK::NETWORK_IS_FRIEND(&handle[0]);
		}
		if (BplayerFriend == 1)
			bplayerFriend = true;
		else
			bplayerFriend = false;

		return bplayerFriend;
	}
}