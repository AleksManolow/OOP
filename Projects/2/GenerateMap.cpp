#include"GenerateMap.h"
char** GenerateMap::allocateMemory(int r, int c, char** rhs){
	char** m = new char*[r];
	for (size_t i = 0; i < r; i++) {
		m[i] = new char[c];
		for(size_t j = 0; j < c; j++) {
			m[i][j] = rhs[i][j];
		}
	}
	return m;
}
void GenerateMap::deleteMemory() {
	for(size_t i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

GenerateMap::GenerateMap()
{
    rows = 0;
    columns = 0;
    matrix = NULL;
}
GenerateMap::GenerateMap(int _rows, int _columns, char** _GenerateMap)
{
    rows = _rows;
    columns = _columns;
    matrix = allocateMemory(_rows, _columns, _GenerateMap);
}
GenerateMap::GenerateMap(const GenerateMap& other)
{
    rows = other.rows;
    columns = other.columns;
    matrix = allocateMemory(other.rows, other.columns, other.matrix);
    monsters = other.monsters;
    treasures = other.treasures;
    
}
GenerateMap& GenerateMap::operator=(const GenerateMap& other)
{
    if (this != &other)
    {
        deleteMemory();
        for (int i = 0; i < treasures.size(); i++)
        {
            delete treasures[i];
        }

        rows = other.rows;
        columns = other.columns;
        matrix = allocateMemory(other.rows, other.columns, other.matrix);

        monsters = other.monsters;
        treasures = other.treasures;
    }

    return *this;
}
GenerateMap::~GenerateMap()
{
    deleteMemory();
    for (int i = 0; i < treasures.size(); i++)
    {
        delete treasures[i];
    }
}
char** GenerateMap::getMatrix() const
{
    return matrix;
}
char GenerateMap::getAt(size_t i, size_t j) const
{
    return matrix[i][j];
}

void GenerateMap::setMatrix(char** _matrix)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = matrix[j][i];
        }
    }
}
void GenerateMap::setAt(size_t i, size_t j, char c)
{
    matrix[i][j] = c;
}
void GenerateMap::print() const
{
    std::cout << "PLAYGROUND" << std::endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
std::istream& operator>>(std::istream& is, GenerateMap& sheet)
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
    int size = 0;
    is >> size;
    for (size_t i = 0; i < size; i++)
    {
        Monster temp;
        temp.loadFromStream(is);
        sheet.monsters.push_back(temp);
    }
    is >> size;
    for (size_t i = 0; i < size; i++)
    {
        std::string nameTreasure;
        is >> nameTreasure;
        if (nameTreasure == "Spell")
        {
            Treasure* temp = new Spell();
            temp->loadFromStream(is);
            sheet.treasures.push_back(temp);
        }
        else if (nameTreasure == "Weapon")
        {
            Treasure* temp = new Weapon();
            temp->loadFromStream(is);
            sheet.treasures.push_back(temp);
        }
        else if (nameTreasure == "Armor")
        {
            Treasure* temp = new Armor();
            temp->loadFromStream(is);
            sheet.treasures.push_back(temp);
        }
    }
    return is;
}
std::ostream& operator<<(std::ostream& os, const GenerateMap& sheet)
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

    os << sheet.monsters.size() << '\n';
    for (size_t i = 0; i < sheet.monsters.size(); i++)
    {
        sheet.monsters[i].writeToStream(os);
    }
    os << sheet.treasures.size() << '\n';
    for (size_t i = 0; i < sheet.treasures.size(); i++)
    {
        sheet.treasures[i]->writeToStream(os);
    }

    return os;
}