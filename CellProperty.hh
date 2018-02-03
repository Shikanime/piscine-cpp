#ifndef __CELLPROPERTY_HH__
#define __CELLPROPERTY_HH__

#include "CellType.hh"

class CellProperty
{
private:
    bool _walkable;
    bool _swimmable;
    bool _flyable;
    bool _event;
    bool _monster;

public:
    CellProperty(const bool walkable, const bool swimmable, const bool flyable, const bool event, const bool monster) noexcept;
    CellProperty(const CellType cell) noexcept;

    bool operator==(CellProperty property) const noexcept;
    bool operator!=(CellProperty property) const noexcept;

    bool isEqual(const CellProperty cell) const noexcept;
    bool isWalkable(void) const noexcept;
    void setWalkable(void) noexcept;
    void setNotWalkable(void) noexcept;
    bool isSwimmable(void) const noexcept;
    void setSwimmable(void) noexcept;
    void setNotSwimmable(void) noexcept;
    bool isFlyable(void) const noexcept;
    void setFlyable(void) noexcept;
    void setNotFlyable(void) noexcept;
    bool isEvent(void) const noexcept;
    void setEvent(void) noexcept;
    void setNotEvent(void) noexcept;
    bool isMonster(void) const noexcept;
    void setMonster(void) noexcept;
    void setNotMonster(void) noexcept;
};

bool hasFlag(CellType, CellProperty) noexcept;
CellProperty getCellFlags(const CellType) noexcept;

#endif
