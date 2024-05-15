#include "position.h"
#include "../../controller/enviroment.h"

// Add your code to implement the Position class here.
Position::Position(int iPx, int iPy):positionX(iPx), positionY(iPy) {}
Position::Position():Position(0,0) {}
Position::~Position()=default;
bool Position::operator==(const Position &other) const { return positionX==other.getX() && positionY==other.getY(); }
int Position::getX() const { return positionX; }
int Position::getY() const { return positionY; }
int Position::incrX() { return ++positionX; }
int Position::incrY() { return ++positionY; }
int Position::decrX() { return --positionX; }
int Position::decrY() { return --positionY; }
