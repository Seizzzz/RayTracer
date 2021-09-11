#pragma once
#include "Vec3.h"

class Ray;
struct RecordHit;

class Material
{
public:
	Material() = default;
	
public:
	virtual bool Scatter(const Ray& r_in, const RecordHit& rcd, Color& attenuat, Ray& r_out) const = 0;
};

class MtrlLambert : public Material
{
public:
	MtrlLambert(const Color& abd) : m_vAlbedo(abd) {}
	
public:
	virtual bool Scatter(const Ray& r_in, const RecordHit& rcd, Color& attenuat, Ray& r_out) const override;

private:
	Color m_vAlbedo;
};

class MtrlMetal : public Material
{
public:
	MtrlMetal(const Color& abd) : m_vAlbedo(abd) {}

public:
	virtual bool Scatter(const Ray& r_in, const RecordHit& rcd, Color& attenuat, Ray& r_out) const override;

private:
	Color m_vAlbedo;
};
