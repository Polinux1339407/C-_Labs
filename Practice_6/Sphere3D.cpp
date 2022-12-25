#include "Sphere3D.h"

bool Sphere3D::HasIntersect(Sphere3D other) const
{
	return Center().GetDistance(other.Center()) <= Radius() + other.Radius();
}

Box3D Sphere3D::GetAABB() { return Box3D(Center(), Radius() * 2, Radius() * 2, Radius() * 2); }
