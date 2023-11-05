#ifndef _COORDINATE_H_
#define _COORDINATE_H_

class Coordinate {
private:
  int x, y;
public:
  Coordinate(int x, int y);
  int getXCoord();
  void setXCoord(int newX);
  int getYCoord();
  void setYCoord(int newY);
  bool operator==(const Coordinate& other) const ;
};

#endif 