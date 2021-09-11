#include "Object.h"
#include "Ray.h"
#include <cmath>

Object::Object() : m_pMtrl(nullptr)
{
	
}

Sphere::Sphere(Point3 center, double radius, shared_ptr<Material> mtrl) :
	m_vCenter(center),
	m_dRadius(radius)
{
	m_pMtrl = mtrl;
}

bool Sphere::Hit(const Ray& r, double t1, double t2, RecordHit& rcd) const
{
	auto A_C = r.Origin() - m_vCenter;
	auto a = r.Direction() * r.Direction();
	auto h = r.Direction() * A_C; // b=2h
	auto c = A_C * A_C - m_dRadius * m_dRadius;
	auto delta = h * h - a * c;
	if (delta < 0.0) return false;
	
	auto root = (-h - sqrt(delta)) / a; //root1
	if(root < t1 || root > t2)
	{
		root = (-h + sqrt(delta)) / a; //root2
		if (root < t1 || root > t2) return false;
	}

	rcd.Position = r.getDestination(root);
	rcd.Normal = (rcd.Position - m_vCenter) / m_dRadius;
	if (rcd.Normal * r.Direction() > 0.0) //hit backface
	{
		rcd.Normal = -rcd.Normal;
		rcd.bHitFront = false;
	}
	rcd.t = root;
	rcd.pMtrl = m_pMtrl;
	
    return true;
}

Vec3 Sphere::GenerateRandomInUnitSphere()
{
	Vec3 ret(0.0, 0.0, 0.0);
	
	do ret = Vec3::GenerateRandom(-1.0, 1.0);
	while (ret.norm() > 1.0);
	
	return ret;
}
