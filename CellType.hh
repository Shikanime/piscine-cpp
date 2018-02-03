#ifndef __CELLTYPE_HH__
#define __CELLTYPE_HH__

enum CellType {
    GrassCell = 'G',
    WaterCell = 'W',
    RockCell = 'R',
    MountainCell = 'M'
};

CellType** parseMap() noexcept;
void freeMap(CellType **map) noexcept;

#endif
