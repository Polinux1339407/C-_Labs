#pragma once
class Point3D
{
public:
	Point3D(double x, double y, double z)
		: x(x), y(y), z(z)
	{
	}

	Point3D(const Point3D& other) = default;

	Point3D() = delete;

	bool operator==(const Point3D& other) const;

	bool operator!=(const Point3D& other) const;

	Point3D operator+(const Point3D& other) const;

	Point3D operator-(const Point3D& other) const;

	Point3D operator*(double scalar) const;

	Point3D operator/(double scalar) const;

	const Point3D& operator+=(const Point3D& other);

	const Point3D& operator-=(const Point3D& other);

	double GetDistance(Point3D point) const;

	Point3D Rotate(double teta, double phi) const;

	double X() const { return x; }

	double Y() const { return y; }

	double Z() const { return z; }

private:
	double x;
	double y;
	double z;
};
