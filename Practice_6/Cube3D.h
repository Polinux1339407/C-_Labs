#pragma once
#include "Box3D.h"

class Cube3D : public Box3D
{
public:
	Cube3D(Point3D center, double side)
		: _center(center), _side(side), _teta(0), _phi(0), Box3D(GetAABB(center, side, 0, 0))
	{
	}

	Cube3D(Point3D center, double side, double phi, double teta) :
		_center(center), _side(side), _teta(teta), _phi(phi), Box3D(GetAABB(center, side, phi, teta))
	{
	}

	Cube3D() = delete;

	Cube3D(const Cube3D& other) = default;

	Cube3D& operator=(const Cube3D& other) = default;

	Box3D GetAABB(Point3D center, double side, double teta, double phi);
private:
	Point3D _center;
	double _side;
	double _teta;
	double _phi;
};
