#include <exception>
#include <stdexcept>
#include <iostream>
#include "CellType.hh"

void fillMap(CellType **map);
CellType** initMap(void) noexcept;

CellType** initMap(void) noexcept
{
    unsigned int width;
    unsigned int height;
    CellType **map;

    std::cin >> width;
    std::cin >> height;

    map = new CellType*[width];
    for (unsigned int i = 0; i < width; ++i) {
        map[i] = new CellType[height];
    }

    return map;
}

void fillMap(CellType **map)
{
    char character;

    for (unsigned int i = 0; i < (sizeof(map) / sizeof(*map)); ++i) {
        std::cin >> character;
        for (unsigned int j = 0; j < (sizeof(map[i]) / sizeof(*map)); ++j) {
            switch(character) {
                case 'G':
                    map[i][j] = CellType::GrassCell;
                    break;
                case 'W':
                    map[i][j] = CellType::WaterCell;
                    break;
                case 'R':
                    map[i][j] = CellType::RockCell;
                    break;
                case 'M':
                    map[i][j] = CellType::MountainCell;
                    break;
                default:
                    throw std::runtime_error("Unvalid map type input");
            }
        }
    }
}

void freeMap(CellType **map) noexcept
{
    for (unsigned int i = 0; i < (sizeof(map) / sizeof(*map)); ++i) {
        delete[] map[i];
    }
    delete[] map;
}

CellType** parseMap(void) noexcept
{
    CellType **map;

    try {
        map = initMap();
        fillMap(map);
    } catch (std::invalid_argument) {
        std::cout << "invalid map data" << std::endl;
        freeMap(map);
    }

    return map;
}
