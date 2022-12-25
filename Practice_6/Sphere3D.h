#include "Box3D.h"


class Sphere3D : public Box3D
{
public:
	Sphere3D(Point3D center, double radius)
		: Box3D(GetAABB()), radius(radius)
	{
	}

	Sphere3D(const Sphere3D& other) = default;

	Sphere3D() = delete;

	Sphere3D& operator=(const Sphere3D& other) = default;

	bool HasIntersect(Sphere3D other) const;

	double Radius() const { return radius; }

	Box3D GetAABB();

private:
	double radius;
};
