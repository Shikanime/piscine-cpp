#ifndef __MAP_HH__
#define __MAP_HH__

#include "CellProperty.hh"
#include "CellType.hh"
#include "Unit.hh"

class Map
{
private:
    CellType **_cells;
    int _width;
    int _height;
    CellType** initCells(const int *width, const int *height) noexcept;
    void fillCells(void);
public:
    Map(void);
    Map(Map&&) noexcept;
    Map(Map const&) = delete;
    ~Map(void);

    Map& operator=(Map const&) = delete;
    Map& operator=(Map&&) noexcept;

    CellType getCell(const int x, const int y) const noexcept;
    CellProperty getCellProperties(const int x, const int y) const noexcept;
    CellType** parseMap(const int *width, const int *height) noexcept;
    bool canGo(int x, int y, Unit const&) const noexcept;
};

#endif
