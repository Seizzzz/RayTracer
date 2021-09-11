#include "Vec3.h"
#include "Common.h"
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

Color Vec3::gamma() const
{
	return Color(sqrt(m_dvec[0]), sqrt(m_dvec[1]), sqrt(m_dvec[2]));
}

bool Vec3::IsBarely() const
{
	static const double limit = 1e-8;
	return (m_dvec[0] < limit) && (m_dvec[1] < limit) && (m_dvec[2] < limit);
}

Vec3 Vec3::GenerateRandom(double min, double max)
{
	return Vec3(GenerateRandomDouble(min, max), GenerateRandomDouble(min, max), GenerateRandomDouble(min, max));
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

Vec3 Vec3::operator&(const Vec3& otr) const //°´Î»³Ë
{
	return Vec3(
		m_dvec[0] * otr.m_dvec[0],
		m_dvec[1] * otr.m_dvec[1],
		m_dvec[2] * otr.m_dvec[2]);
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
	return *this / norm();
}
