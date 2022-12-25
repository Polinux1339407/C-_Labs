#pragma once
#include "Box3D.h"


class Tetra3D : public Box3D
{
public:
	Tetra3D(Point3D a, Point3D b, Point3D c, Point3D d) :
		Box3D(GetAABB(a, b, c, d)), _a(a), _b(b), _c(c), _d(d)
	{
	}

	Box3D GetAABB(Point3D a, Point3D b, Point3D c, Point3D d) const;

private:
	Point3D _a;
	Point3D _b;
	Point3D _c;
	Point3D _d;
};
