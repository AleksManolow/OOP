#include"Map.h"
char** Map::allocateMemory(int r, int c, char** rhs){
	char** matrix = new char*[r];
	for (size_t i = 0; i < r; i++) {
		matrix[i] = new char[c];
		for(size_t j = 0; j < c; j++) {
			matrix[i][j] = rhs[i][j];
		}
	}
	return matrix;
}
void Map::deleteMemory() {
	for(size_t i = 0; i < rows; i++) {
		delete[] map[i];
	}
	delete[] map;
}

Map::Map()
{
    rows = 0;
    columns = 0;
    map = NULL;
}
Map::Map(int _rows, int _columns, char** _map)
{
    rows = _rows;
    columns = _columns;
    map = allocateMemory(_rows, _columns, _map);
}
Map::Map(const Map& other)
{
    rows = other.rows;
    columns = other.columns;
    map = allocateMemory(other.rows, other.columns, other.map);
    
}
Map& Map::operator=(const Map& other)
{
    if (this != &other)
    {
        deleteMemory();

        rows = other.rows;
        columns = other.columns;
        map = allocateMemory(other.rows, other.columns, other.map);
    }

    return *this;
}
Map::~Map()
{
    deleteMemory();
}
void Map::print() const
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << map[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    
}