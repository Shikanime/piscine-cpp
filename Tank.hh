#ifndef __TANK_HH__
#define __TANK_HH__

#include "Unit.hh"

class Tank : public Unit
{
public:
	UnitField getField(void) const noexcept;
};

#endif
