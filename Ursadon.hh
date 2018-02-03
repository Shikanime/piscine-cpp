#ifndef __URSADON_HH__
#define __URSADON_HH__

#include "Unit.hh"

class Ursadon : public Unit
{
public:
	UnitField getField(void) const noexcept;
};

#endif
