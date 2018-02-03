#ifndef __GAME_HH__
#define __GAME_HH__

#include <vector>
#include "Map.hh"

class Game
{
private:
	Map _map;
	std::vector<Unit*> _units;
};

#endif
