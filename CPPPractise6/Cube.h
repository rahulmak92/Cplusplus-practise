#ifndef CUBE_h
#define CUBE_H
#include "Rectangle.h"
class Cube : public Rectangle
{
	protected :
				double height;
				double volume;
	public	:
				Cube():Rectangle()
				{
					height = 0.0;
					volume = 0.0;
				}
				Cube(double,double,double);

				double getHeight() const
				{
					return height;
				}
				double getVolume() const
				{
					return volume;
				}
};
#endif
