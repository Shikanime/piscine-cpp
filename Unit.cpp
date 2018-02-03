#include "Unit.hh"

Unit::Unit(const int x, const int y) noexcept
    : _x(x), _y(y)
{
}

int Unit::getPositionX(void) const noexcept
{
    return this->_y;
}

int Unit::getPositionY(void) const noexcept
{
    return this->_y;
}
