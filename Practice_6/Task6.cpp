#include <iostream>
#include "Box3D.h"
#include "Cube3D.h"
#include "Sphere3D.h"
#include "Tetra3D.h"
#include <cassert>
#include <corecrt_math_defines.h>

void RunTest()
{
	//Point3D
	Point3D a(2, 0, 0);
	assert(a == Point3D(2, 0, 0));
	assert(a != Point3D(1, 0, 0));
	assert(a + Point3D(1, 1, 1) == Point3D(3, 1, 1));
	assert(a - Point3D(1, 1, 1) == Point3D(1, -1, -1));
	assert(a * 2 == Point3D(4, 0, 0));
	assert(a / 2 == Point3D(1, 0, 0));
	assert(a.Rotate(-M_PI_2, 0) == Point3D(0, 2, 0));

	//Box3D
	Box3D b1(Point3D(0, 0, 0), Point3D(1, 1, 1));
	assert(b1.HasIntersect(b1));
	Box3D b2(Point3D(0, 0, 0), Point3D(2, 2, 2));
	assert(b1.HasIntersect(b2) && b2.HasIntersect(b1));
	b2 = Box3D(Point3D(2, 2, 2), Point3D(3, 3, 3));
	assert(!b1.HasIntersect(b2) && !b2.HasIntersect(b1));

	//Cube3D
	Cube3D c1(Point3D(0, 0, 0), 1);
	Cube3D c2(Point3D(0, 0, 0), 1, 0, 0);
	assert(c1.HasIntersect(c2) && c2.HasIntersect(c1));
	c2 = Cube3D(Point3D(0, 0, 0), 1, M_PI / 3, M_PI / 4);
	assert(c1.HasIntersect(c2) && c2.HasIntersect(c1));

	//Sphere3D
	Sphere3D s1(Point3D(0, 0, 0), 1);
	Sphere3D s2(Point3D(1, 1, 1), 1);
	assert(s1.HasIntersect(s2) && s2.HasIntersect(s1));

	//Tetra3D
	Tetra3D t1(Point3D(0, 0, 0), Point3D(1, 0, 0), Point3D(0, 1, 0), Point3D(0, 0, 1));
	Tetra3D t2(Point3D(0, 0, 0), Point3D(2, 0, 0), Point3D(0, 2, 0), Point3D(0, 0, 1));
	assert(t1.HasIntersect(t2) && t2.HasIntersect(t1));

	std::cout << "All tests passed" << std::endl;
}

int main()
{
	RunTest();
}
