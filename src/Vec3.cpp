#include "Vec3.h"
#include <iostream>
#include <cmath>
#include <cassert>

inline Vec3 operator*(const double& factor, const Vec3& v)
{
	return Vec3(
		v.m_dvec[0] * factor,
		v.m_dvec[1] * factor,
		v.m_dvec[2] * factor);
}

Vec3 Vec3::lerp(const Vec3& otr, double t) const
{
	return *this + t * (otr - *this);
}

inline Vec3 operator/(const double& factor, const Vec3& v)
{
	return (1 / factor) * v;
}

std::ostream& operator<<(std::ostream& out, const Vec3& v)
{
	out << "Vec3: (" << v.x() << " ," << v.y() << "v, " << v.z();
	return out;
}

Vec3& Vec3::operator+=(const Vec3& otr)
{
	m_dvec[0] += otr.m_dvec[0];
	m_dvec[1] += otr.m_dvec[1];
	m_dvec[2] += otr.m_dvec[2];
    return *this;
}

Vec3& Vec3::operator*=(const Vec3& otr)
{
	m_dvec[0] *= otr.m_dvec[0];
	m_dvec[1] *= otr.m_dvec[1];
	m_dvec[2] *= otr.m_dvec[2];
	return *this;
}

Vec3& Vec3::operator*=(const double& factor)
{
	m_dvec[0] *= factor;
	m_dvec[1] *= factor;
	m_dvec[2] *= factor;
	return *this;
}

inline Vec3 Vec3::operator+(const Vec3& otr) const
{
	return Vec3(
		m_dvec[0] + otr.m_dvec[0], 
		m_dvec[1] + otr.m_dvec[1], 
		m_dvec[2] + otr.m_dvec[2]);
}

inline Vec3 Vec3::operator-(const Vec3& otr) const
{
	return operator+(-otr);
}

double Vec3::operator*(const Vec3& otr) const
{
	return m_dvec[0] * otr.m_dvec[0] +
		m_dvec[1] * otr.m_dvec[1] +
		m_dvec[2] * otr.m_dvec[2];
}

inline Vec3 Vec3::operator/(const Vec3& otr) const
{
	return Vec3(
		m_dvec[0] / otr.m_dvec[0],
		m_dvec[1] / otr.m_dvec[1],
		m_dvec[2] / otr.m_dvec[2]);
}

inline Vec3 Vec3::operator/(const double& factor) const
{
	return Vec3(
		m_dvec[0] / factor,
		m_dvec[1] / factor,
		m_dvec[2] / factor);
}

inline Vec3& Vec3::dot(const Vec3& otr)
{
	return operator*=(otr);
}

Vec3& Vec3::cross(const Vec3& otr)
{
	assert(0); //todo
	return *this;
}

inline double Vec3::norm() const
{
	return sqrt(
		m_dvec[0] * m_dvec[0]
		+ m_dvec[1] * m_dvec[1]
		+ m_dvec[2] * m_dvec[2]);
}

Vec3 Vec3::unit() const
{
	assert(norm() != 0.0);
	return *this / norm();
}
