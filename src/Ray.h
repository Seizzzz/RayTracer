#pragma once
#include "Vec3.h"

class Ray
{
public:
	Ray() = delete;
	Ray(Point3 origin, Vec3 direction) : m_vOrigin(origin), m_vDirection(direction) {}

	Point3 Origin() const { return m_vOrigin; }
	Vec3 Direction() const { return m_vDirection; }

	Point3 getDestination(const double& t) const { return m_vOrigin + t * m_vDirection; }

private:
	Point3 m_vOrigin;
	Vec3 m_vDirection;
};