#ifndef __ROACH_HH__
#define __ROACH_HH__

#include "Unit.hh"

class Roach : public Unit
{
public:
	UnitField getField(void) override const noexcept;
};

#endif
