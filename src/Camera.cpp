#include "Camera.h"
#include "Common.h"
#include "Ray.h"

inline Vec3 GenerateDefoucs()
{
	Vec3 ret(0.0, 0.0, 0.0);

	do ret = Vec3(GenerateRandomDouble(-1.0, 1.0), GenerateRandomDouble(-1.0, 1.0), 0.0);
	while (ret.norm() >= 1.0);

	return ret;
}

Ray Camera::Beam(double u, double v) const
{
	Vec3 rd = m_dLensRadius * GenerateDefoucs();
	Vec3 offset = rd.x() * m_vRight + rd.y() * m_vUpward;
	
	return Ray(m_vPosition + offset, m_vLeftDown + u * m_vHorizion + v * m_vVertical - m_vPosition - offset);
}

Camera::Camera(Point3 position, Vec3 target, Vec3 upward_world, double aperture) :
	m_vPosition(position),
	m_vTargetPosition(target),
	m_vForwardInv(Vec3({ 0.0,0.0,0.0 })),
	m_vRight(Vec3({ 0.0,0.0,0.0 })),
	m_vUpward(Vec3({ 0.0,0.0,0.0 })),
	m_vHorizion(Vec3({ 0.0,0.0,0.0 })),
	m_vVertical(Vec3({ 0.0,0.0,0.0 })),
	m_vLeftDown(Vec3({ 0.0,0.0,0.0 }))
{
	m_vForwardInv = (m_vPosition - m_vTargetPosition).unit();
	m_vRight = upward_world.cross(m_vForwardInv);
	m_vUpward = m_vForwardInv.cross(m_vRight);
	//auto focus_dist = (m_vPosition - m_vTargetPosition).norm();
	auto focus_dist = 10.0;
	
	m_vHorizion = focus_dist * Common::g_ViewPortWidth * m_vRight;
	m_vVertical = focus_dist * Common::g_ViewPortHeight * m_vUpward;
	m_vLeftDown = m_vPosition - m_vHorizion / 2 - m_vVertical / 2 - focus_dist * m_vForwardInv;
	m_dLensRadius = aperture / 2.0;
}
