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
	r_out = Ray(rcd.Position, reflect(r_in.Direction().unit(), rcd.Normal) + m_dFuzz * Sphere::GenerateRandomInUnitSphere().unit());
	attenuat = m_vAlbedo;
	return (r_out.Direction() * rcd.Normal) > 0; //only when reflect
}

bool MtrlDielectric::Scatter(const Ray& r_in, const RecordHit& rcd, Color& attenuat, Ray& r_out) const
{
	attenuat = Color(1.0, 1.0, 1.0);
	auto in_dir = r_in.Direction().unit();
	auto cos_theta = fmin(-in_dir * rcd.Normal, 1.0);
	auto sin_theta = sqrt(1 - cos_theta * cos_theta);
	double refract_ratio = rcd.bHitFront ? (1.0 / m_dRefractRatio) : m_dRefractRatio;

	static auto Schlick = [](double& cos_theta, double& refract_ratio)
	{
		auto r0 = (1 - refract_ratio) / (1 + refract_ratio);
		r0 = r0 * r0;
		return r0 + (1 - r0) * pow((1 - cos_theta), 5);
	};

	if(refract_ratio * sin_theta > 1.0 || (Schlick(cos_theta, refract_ratio)) > GenerateRandomDouble()) //diverge normal dir
	{
		Vec3 out_dir = reflect(in_dir, rcd.Normal); //reflect
		r_out = Ray(rcd.Position, out_dir);
	}
	else
	{
		Vec3 out_dir = refract(in_dir, rcd.Normal, refract_ratio); //refract
		r_out = Ray(rcd.Position, out_dir);
	}
	
	return true;
}
