#include "CellProperty.hh"

CellProperty::CellProperty(const bool walkable, const bool swimmable, const bool flyable, const bool event, const bool monster) noexcept
    : _walkable(walkable), _swimmable(swimmable), _flyable(flyable), _event(event), _monster(monster)
{
}

CellProperty::CellProperty(const CellType cell) noexcept
{
    switch (cell) {
        case CellType::GrassCell:
            CellProperty(true, false, true, false, false);
            break;
        case CellType::WaterCell:
            CellProperty(false, true, true, false, false);
            break;
        case CellType::RockCell:
            CellProperty(false, false, true, false, false);
            break;
        case CellType::MountainCell:
        default:
            CellProperty(false, false, false, false, false);
            break;
    }
}

bool CellProperty::operator==(CellProperty property) const noexcept
{
	return this->isEqual(property);
}

bool CellProperty::operator!=(CellProperty property) const noexcept
{
	return !this->isEqual(property);
}

bool CellProperty::isEqual(const CellProperty property) const noexcept
{
	return (this->isWalkable() == property.isWalkable()) &&
		(this->isSwimmable() == property.isSwimmable()) &&
		(this->isFlyable()   == property.isFlyable()) &&
		(this->isEvent()     == property.isEvent()) &&
		(this->isMonster()   == property.isMonster());
}

bool CellProperty::isWalkable(void) const noexcept
{
	return _walkable;
}

void CellProperty::setWalkable(void) noexcept
{
	this->_walkable = true;
}

void CellProperty::setNotWalkable(void) noexcept
{
	this->_walkable = false;
}

bool CellProperty::isSwimmable(void) const noexcept
{
	return this->_swimmable;
}

void CellProperty::setSwimmable(void) noexcept
{
	this->_swimmable = true;
}

void CellProperty::setNotSwimmable(void) noexcept
{
	this->_swimmable = false;
}

bool CellProperty::isFlyable(void) const noexcept
{
	return this->_flyable;
}

void CellProperty::setFlyable(void) noexcept
{
	this->_flyable = true;
}

void CellProperty::setNotFlyable(void) noexcept
{
	this->_flyable = false;
}

bool CellProperty::isEvent(void) const noexcept
{
	return this->_event;
}

void CellProperty::setEvent(void) noexcept
{
	this->_event = true;
}

void CellProperty::setNotEvent(void) noexcept
{
	this->_event = false;
}

bool CellProperty::isMonster(void) const noexcept
{
	return _monster;
}

void CellProperty::setMonster(void) noexcept
{
	this->_monster = true;
}

void CellProperty::setNotMonster(void) noexcept
{
	this->_monster = false;
}

CellProperty getCellFlags(const CellType cell) noexcept
{
	switch (cell) {
		case CellType::GrassCell:
			return CellProperty(true, false, true, false, false);
		case CellType::WaterCell:
			return CellProperty(false, true, true, false, false);
		case CellType::RockCell:
			return CellProperty(false, false, true, false, false);
		case CellType::MountainCell:
			return CellProperty(false, false, false, false, false);
		default:
			return CellProperty(false, false, false, false, false);
	}
}

bool hasFlag(CellType cell, CellProperty property) noexcept
{
	CellProperty	cellProperty(getCellFlags(cell));

	return (cellProperty.isWalkable() == property.isWalkable()) ||
		(cellProperty.isSwimmable() == property.isSwimmable()) ||
		(cellProperty.isFlyable()   == property.isFlyable()) ||
		(cellProperty.isEvent()     == property.isEvent()) ||
		(cellProperty.isMonster()   == property.isMonster());
}