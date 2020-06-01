#include "Functions.h"
#include "common.hpp"
#include "natives.hpp"
#include "script.hpp"
#include "pointers.hpp"

namespace big {
	void CFunctions::RequestControlOfid(Entity selectedPlayer)
	{
		Any netid = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(selectedPlayer);
		int tick = 0;

		while (!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 50)
		{
			NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
			tick++;
		}
	}
}