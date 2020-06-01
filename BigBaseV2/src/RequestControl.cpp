#include "Functions.h"
#include "common.hpp"
#include "natives.hpp"
#include "script.hpp"
#include "pointers.hpp"

namespace big {
	
	void CFunctions::RequestControl(Entity input)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(input);

		int tick = 0;
		while (tick <= 50)
		{
			if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(input)) {
				return;
			}
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(input);
			tick++;
		}
	}
}