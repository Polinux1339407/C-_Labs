#pragma once
#include <cmath>

#include "Point3D.h"

class Box3D
{
public:
	explicit Box3D(Point3D center, double width, double height, double depth)
		: center(center), xw(width), yw(height), zw(depth)
	{
	}

	explicit Box3D(Point3D min, Point3D max)
		: center((min + max) / 2), xw(abs(max.X() - min.X())), yw(abs(max.Y() - min.Y())),
		  zw(abs(max.Z() - min.Z()))
	{
	}

	Box3D() = delete;

	Box3D(const Box3D& other) = default;

	Box3D& operator=(const Box3D& other) = default;

	bool HasIntersect(Box3D other) const;

	Point3D Center() const { return center; }

	double XW() const { return xw; }
	double YW() const { return yw; }
	double ZW() const { return zw; }

	Box3D GetAABB() { return *this; }

private:
	Point3D center;
	double xw;
	double yw;
	double zw;
};
