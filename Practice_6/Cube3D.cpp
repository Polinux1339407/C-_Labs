#include "Cube3D.h"

#include <algorithm>
#include <vector>

Box3D Cube3D::GetAABB(Point3D center, double side, double phi, double teta)
{
	std::vector<Point3D> points;
	points.push_back(center + Point3D(side / 2, side / 2, side / 2));
	points.push_back(center + Point3D(side / 2, side / 2, -side / 2));
	points.push_back(center + Point3D(side / 2, -side / 2, side / 2));
	points.push_back(center + Point3D(side / 2, -side / 2, -side / 2));
	points.push_back(center + Point3D(-side / 2, side / 2, side / 2));
	points.push_back(center + Point3D(-side / 2, side / 2, -side / 2));
	points.push_back(center + Point3D(-side / 2, -side / 2, side / 2));
	points.push_back(center + Point3D(-side / 2, -side / 2, -side / 2));
	for (size_t i = 0; i < std::size(points); i++) { points[i] = points[i].Rotate(phi, teta); }

	auto minmaxX = std::minmax_element(points.begin(), points.end(), [](Point3D a, Point3D b)
	{
		return a.X() < b.X();
	});
	auto minmaxY = std::minmax_element(points.begin(), points.end(), [](Point3D a, Point3D b)
	{
		return a.Y() < b.Y();
	});
	auto minmaxZ = std::minmax_element(points.begin(), points.end(), [](Point3D a, Point3D b)
	{
		return a.Z() < b.Z();
	});

	return Box3D(Point3D((*minmaxX.first).X(), (*minmaxY.first).Y(), (*minmaxZ.first).Z()),
	             Point3D((*minmaxX.second).X(), (*minmaxY.second).Y(), (*minmaxZ.second).Z()));
}
