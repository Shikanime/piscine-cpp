#include "Game.hh"

bool Game::canPlaceUnit(int x, int y, Unit const& unit) const noexcept
{
	return this->_map.canGo(x, y, unit);
}

bool Game::placeUnit(Unit* unit) noexcept
{
	if (!this->canPlaceUnit(unit->getPositionX(), unit->getPositionY(), *unit)) {
		return false;
	}
	this->_units.push_back(unit);
	return true;
}
