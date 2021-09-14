#pragma once
class ostream;
class Vec3;
using Color = Vec3;
using Point3 = Vec3;

class Vec3
{
public:
	Vec3() = delete;
	Vec3(double x, double y, double z) : m_dvec{ x, y, z } {}
	
public:
	Vec3 operator-() const { return Vec3(-m_dvec[0], -m_dvec[1], -m_dvec[2]); }
	Vec3& operator+=(const Vec3& otr);
	Vec3& operator-=(const Vec3& otr) { return operator+=(-otr); }
	Vec3& operator*=(const Vec3& otr);
	Vec3& operator*=(const double& factor);
	Vec3& operator/=(const double& factor) { return operator*=(1 / factor); }

public:
	Vec3 operator+(const Vec3& otr) const;
	Vec3 operator-(const Vec3& otr) const;
	double operator*(const Vec3& otr) const;
	Vec3 operator/(const Vec3& otr) const;
	Vec3 operator/(const double& factor) const;
	Vec3 operator&(const Vec3& otr) const;
	friend Vec3 operator*(const double& factor, const Vec3& v);

public:
	double dot(const Vec3& otr) const;
	Vec3 cross(const Vec3& otr) const;
	double norm() const;
	Vec3 unit() const;
	Vec3 lerp(const Vec3& otr, double t) const;

public:
	Color gamma() const;

public:
	bool IsBarely() const;

public:
	static Vec3 GenerateRandom(double min = 0.0, double max = 1.0);
	
public:
	double x() const { return m_dvec[0]; }
	double y() const { return m_dvec[1]; }
	double z() const { return m_dvec[2]; }
	double& x() { return m_dvec[0]; }
	double& y() { return m_dvec[1]; }
	double& z() { return m_dvec[2]; }

public:
	friend ostream& operator<<(ostream& out, const Vec3& v);

private:
	double m_dvec[3];
};