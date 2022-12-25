#include "Point3D.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <limits>


bool Point3D::operator==(const Point3D& other) const
{
	return abs(other.x - x) <= std::numeric_limits<double>::epsilon() &&
		abs(other.y - y) <= std::numeric_limits<double>::epsilon() &&
		abs(other.z - z) <= std::numeric_limits<double>::epsilon();
}

bool Point3D::operator!=(const Point3D& other) const { return !(*this == other); }

Point3D Point3D::operator+(const Point3D& other) const { return Point3D(x + other.x, y + other.y, z + other.z); }

Point3D Point3D::operator-(const Point3D& other) const { return Point3D(x - other.x, y - other.y, z - other.z); }

const Point3D& Point3D::operator+=(const Point3D& other)
{
	*this = *this + other;
	return *this;
}

const Point3D& Point3D::operator-=(const Point3D& other)
{
	*this = *this - other;
	return *this;
}

Point3D Point3D::operator*(double scalar) const { return Point3D(x * scalar, y * scalar, z * scalar); }

Point3D Point3D::operator/(double scalar) const { return Point3D(x / scalar, y / scalar, z / scalar); }

double Point3D::GetDistance(Point3D point) const
{
	return sqrt(pow(x - point.x, 2) + pow(y - point.y, 2) + pow(z - point.z, 2));
}


Point3D Point3D::Rotate(double phi, double teta) const
{
	double x1 = x * (cos(teta) * cos(phi)) + y * (cos(teta) * sin(phi)) -
		z * sin(teta);
	double y1 = x * -sin(phi) + y * cos(phi);
	double z1 = x * (sin(teta) * cos(phi)) + y * (sin(teta) * sin(phi)) +
		z * cos(teta);
	return Point3D(x1, y1, z1);
}
