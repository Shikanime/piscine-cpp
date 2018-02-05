#ifndef __STALKER_HH__
#define __STALKER_HH__

#include "Unit.hh"

class Stalker : public Unit
{
public:
	UnitField getField(void) override const noexcept;
};

#endif
