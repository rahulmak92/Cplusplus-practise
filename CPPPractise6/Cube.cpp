#include "Cube.h"
Cube::Cube(double w,double len,double h):Rectangle(w,len)
{
	height = h;
	volume = getArea() * h;
}
