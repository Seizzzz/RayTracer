#pragma once
#include "Vec3.h"

class Ray;

class Camera
{
public:
	Ray Beam(double u, double v) const;
	
public:
	Camera() = delete;
	Camera(Point3 origin, Vec3 direction, Vec3 upward);

private:
	Point3 m_vOrigin;
	Vec3 m_vDirection;
	Vec3 m_vUpward;
	Vec3 m_vHorizion;
	Vec3 m_vVertical;
	Point3 m_vLeftDown;
	
};