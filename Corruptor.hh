#ifndef __CORRUPTOR_HH__
#define __CORRUPTOR_HH__

#include "Unit.hh"

class Corruptor : public Unit
{
public:
	UnitField getField(void) const noexcept;
};

#endif
