#ifndef __MARINE_HH__
#define __MARINE_HH__

#include "Unit.hh"

class Marine : public Unit
{
public:
	UnitField getField(void) const noexcept;
};

#endif
