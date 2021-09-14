#pragma once
#include "Vec3.h"

class Ray;

class Camera
{
public:
	Ray Beam(double u, double v) const;
	
public:
	Camera() = delete;
	Camera(Point3 position, Vec3 target, Vec3 upward_world, double aperture = 2.0);

private:
	Point3 m_vPosition;
	Vec3 m_vTargetPosition;
	Vec3 m_vForwardInv;
	Vec3 m_vRight;
	Vec3 m_vUpward;
	Vec3 m_vHorizion;
	Vec3 m_vVertical;
	Point3 m_vLeftDown;
	double m_dLensRadius;
};