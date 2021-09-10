#include "Object.h"

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
	if (rcd.Normal * r.Direction() > 0.0) rcd.Normal = -rcd.Normal; //hit backface
	rcd.t = root;
	
    return true;
}
