#include"Map.h"
char** Map::allocateMemory(int r, int c, char** rhs){
	char** m = new char*[r];
	for (size_t i = 0; i < r; i++) {
		m[i] = new char[c];
		for(size_t j = 0; j < c; j++) {
			m[i][j] = rhs[i][j];
		}
	}
	return m;
}
void Map::deleteMemory() {
	for(size_t i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

Map::Map()
{
    rows = 0;
    columns = 0;
    matrix = NULL;
}
Map::Map(int _rows, int _columns, char** _map)
{
    rows = _rows;
    columns = _columns;
    matrix = allocateMemory(_rows, _columns, _map);
}
Map::Map(const Map& other)
{
    rows = other.rows;
    columns = other.columns;
    matrix = allocateMemory(other.rows, other.columns, other.matrix);
    
}
Map& Map::operator=(const Map& other)
{
    if (this != &other)
    {
        deleteMemory();

        rows = other.rows;
        columns = other.columns;
        matrix = allocateMemory(other.rows, other.columns, other.matrix);
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
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    
}
std::istream& operator>>(std::istream& is, Map& sheet)
{
    is >> sheet.rows >> sheet.columns;
    sheet.matrix = new char*[sheet.rows];
	for (size_t i = 0; i < sheet.rows; i++) 
    {
		sheet.matrix[i] = new char[sheet.columns];
		for(size_t j = 0; j < sheet.columns; j++) 
        {
			is >> sheet.matrix[i][j];
		}
	}
    return is;
}
std::ostream& operator<<(std::ostream& os, const Map& sheet)
{
    os << sheet.rows << ' ' <<sheet.columns << '\n';
    for (size_t i = 0; i < sheet.rows; i++) 
    {
		for(size_t j = 0; j < sheet.columns; j++) 
        {
			os << sheet.matrix[i][j] << ' ';
		}
        os << '\n';
	}
    return os;
}