#include "Box3D.h"

bool Box3D::HasIntersect(Box3D other) const
{
	double xMin1 = center.X() - xw / 2;
	double xMax1 = center.X() + xw / 2;
	double yMax1 = center.Y() + yw / 2;
	double yMin1 = center.Y() - yw / 2;
	double zMin1 = center.Z() - zw / 2;
	double zMax1 = center.Z() + zw / 2;

	double xMin2 = other.Center().X() - other.XW() / 2;
	double xMax2 = other.Center().X() + other.XW() / 2;
	double yMin2 = other.Center().Y() - other.YW() / 2;
	double yMax2 = other.Center().Y() + other.YW() / 2;
	double zMin2 = other.Center().Z() - other.ZW() / 2;
	double zMax2 = other.Center().Z() + other.ZW() / 2;

	return (xMin1 <= xMax2 && xMax1 >= xMin2) &&
		   (yMin1 <= yMax2 && yMax1 >= yMin2) &&
		   (zMin1 <= zMax2 && zMax1 >= zMin2);
}
