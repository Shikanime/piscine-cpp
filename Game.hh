#ifndef __GAME_HH__
#define __GAME_HH__

#include <vector>
#include "Map.hh"

class Game
{
private:
	Map _map;
	std::vector<Unit*> _units;
public:
	bool canPlaceUnit(int x, int y, Unit const& unit) const noexcept;
	bool placeUnit(Unit* unit) noexcept;
};

#endif
