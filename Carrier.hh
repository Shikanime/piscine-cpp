#ifndef __CARRIER_HH__
#define __CARRIER_HH__

#include "Unit.hh"

class Carrier : public Unit
{
public:
	UnitField getField(void) override const noexcept;
};

#endif
