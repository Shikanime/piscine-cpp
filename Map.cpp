#include <iostream>
#include <string>
#include "Map.hh"
#define DEBUG_BUILD 1

Map::Map(void)
{
    std::string buffer;

    try {
        std::cin >> buffer;
        this->_width = static_cast<unsigned int>(std::stoi(buffer));
#ifdef DEBUG_BUILD
        std::cout << "[DEBUG] Input width: " << this->_width << std::endl;
#endif
        std::cin >> buffer;
        this->_height = static_cast<unsigned int>(std::stoi(buffer));
#ifdef DEBUG_BUILD
        std::cout << "[DEBUG] Input height: " << this->_height << std::endl;
#endif
    } catch (std::invalid_argument) {
        std::cout << "invalid map data" << std::endl;
    }
    this->_cells = this->parseMap(&this->_width, &this->_height);
}

Map::~Map(void)
{
    if (!this->_cells)
        return;
    freeMap(this->_cells);
}

Map::Map(Map&& other) noexcept
{
    this->_cells = other._cells;
    other._cells = nullptr;
}

Map& Map::operator=(Map&& other) noexcept
{
    if (this == &other) {
        return *this;
    }
    this->_cells = other._cells;
    other._cells = nullptr;
    return *this;
}

CellType Map::getCell(const int x, const int y) const noexcept
{
    return this->_cells[x][y];
}

CellProperty Map::getCellProperties(const int x, const int y) const noexcept
{
    return getCellFlags(this->getCell(x, y));
}

CellType** Map::initCells(const int *width, const int *height) noexcept
{
    this->_cells = new CellType*[*height];
    for (unsigned int i = 0; i < static_cast<unsigned int>(*width); ++i) {
        this->_cells[i] = new CellType[*width];
    }
#ifdef DEBUG_BUILD
        std::cout << "[DEBUG] Map size of x:" << *width << " y:" << *height << std::endl;
#endif
    return this->_cells;
}

void Map::fillCells(void)
{
    char character;

#ifdef DEBUG_BUILD
        std::cout << "[DEBUG] Current map size: x:" << static_cast<unsigned int>(this->_width) << " y:" << static_cast<unsigned int>(this->_height) << std::endl;
#endif
    for (unsigned int i = 0; i < static_cast<unsigned int>(this->_height); ++i) {
        std::cin >> character;
        for (unsigned int j = 0; j < static_cast<unsigned int>(this->_width); ++j) {
#ifdef DEBUG_BUILD
        std::cout << "[DEBUG] Map element at x:" << j << " y:" << i << ": " << character << std::endl;
#endif
            switch(character) {
                case 'R':
                    this->_cells[j][i] = CellType::RockCell;
                    break;
                case 'G':
                    this->_cells[j][i] = CellType::GrassCell;
                    break;
                case 'W':
                    this->_cells[j][i] = CellType::WaterCell;
                    break;
                case 'M':
                    this->_cells[j][i] = CellType::MountainCell;
                    break;
                default:
                    throw std::runtime_error("Unvalid map type input");
            }
        }
    }
}

CellType** Map::parseMap(const int *width, const int *height) noexcept
{
    this->_cells = this->initCells(width, height);
    try {
        this->fillCells();
#ifdef DEBUG_BUILD
        std::cout << "[DEBUG] final map: " << std::endl;
        for (unsigned int i = 0; i < static_cast<unsigned int>(this->_height); ++i) {
            for (unsigned int j = 0; j < static_cast<unsigned int>(this->_width); ++j) {
                std::cout << this->_cells[j][i];
            }
            std::cout << std::endl;
        }
#endif
    } catch (std::invalid_argument) {
        std::cout << "invalid map data" << std::endl;
        freeMap(this->_cells);
    }
    return this->_cells;

}

bool Map::canGo(int x, int y, Unit const& unit) const noexcept
{
    CellProperty cellProperty = this->getCellProperties(x, y);

    switch (unit.getField()) {
        case UnitField::Ground:
            return cellProperty.isFlyable() || cellProperty.isWalkable();
        case UnitField::Sky:
            return cellProperty.isFlyable();
        case UnitField::Water:
            return cellProperty.isSwimmable();
        default:
            return false;
    }
}
