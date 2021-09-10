#include "Camera.h"

Ray Camera::Beam(double u, double v) const
{
	return Ray(m_vOrigin, m_vLeftDown + u * m_vHorizion + v * m_vVertical - m_vOrigin);
}

Camera::Camera(Point3 origin, Vec3 direction, Vec3 upward) :
	m_vOrigin(origin),
	m_vDirection(direction),
	m_vUpward(upward),
	m_vHorizion(Vec3(Common::g_ViewPortWidth, 0.0, 0.0)),
	m_vVertical(Vec3(0.0, Common::g_ViewPortHeight, 0.0)),
	m_vLeftDown(m_vOrigin - m_vHorizion / 2 - m_vVertical / 2 - Vec3(0.0, 0.0, Common::g_FocalLength))
{

}
