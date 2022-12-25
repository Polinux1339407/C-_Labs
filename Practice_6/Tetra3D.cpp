#include "Tetra3D.h"
#include <algorithm>

Box3D Tetra3D::GetAABB(Point3D a, Point3D b, Point3D c, Point3D d) const
{
	double minX = std::min({a.X(), b.X(), c.X(), d.X()});
	double minY = std::min({a.Y(), b.Y(), c.Y(), d.Y()});
	double minZ = std::min({a.Z(), b.Z(), c.Z(), d.Z()});
	double maxX = std::max({a.X(), b.X(), c.X(), d.X()});
	double maxY = std::max({a.Y(), b.Y(), c.Y(), d.Y()});
	double maxZ = std::max({a.Z(), b.Z(), c.Z(), d.Z()});
	return Box3D(Point3D(minX, minY, minZ), Point3D(maxX, maxY, maxZ));
}
