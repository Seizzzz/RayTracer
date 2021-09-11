#include "Material.h"
#include "Common.h"
#include "Object.h"
#include "Ray.h"

bool MtrlLambert::Scatter(const Ray& r_in, const RecordHit& rcd, Color& attenuat, Ray& r_out) const
{
	auto dir = rcd.Normal + Sphere::GenerateRandomInUnitSphere().unit();
	if (dir.IsBarely()) dir = rcd.Normal;

	r_out = Ray(rcd.Position, dir);
	attenuat = m_vAlbedo;
	
	return true;
}

bool MtrlMetal::Scatter(const Ray& r_in, const RecordHit& rcd, Color& attenuat, Ray& r_out) const
{
	r_out = Ray(rcd.Position, reflect(r_in.Direction().unit(), rcd.Normal));
	attenuat = m_vAlbedo;
	return (r_out.Direction() * rcd.Normal) > 0; //only when reflect
}

