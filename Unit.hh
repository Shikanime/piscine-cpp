#ifndef __UNIT_HH__
#define __UNIT_HH__

#include "UnitField.hh"

class Unit
{
private:
    int _x;
    int _y;
public:
    Unit(const int x, const int y) noexcept;

    int getPositionX(void) const noexcept;
    int getPositionY(void) const noexcept;
    virtual UnitField getField(void) const noexcept = 0;
};

#endif
