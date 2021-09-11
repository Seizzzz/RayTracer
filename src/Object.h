#pragma once
#include "Vec3.h"
#include <memory>
class Ray;
class Material;
using std::shared_ptr;

struct Record
{
public:
	Record() = default;
};

struct RecordHit : public Record
{
	Point3 Position = Vec3(0.0, 0.0, 0.0);
	Vec3 Normal = Vec3(0.0, 0.0, 0.0);
	double t = 0.0;
	bool bHitFront = true;
	shared_ptr<Material> pMtrl;
public:
	RecordHit() = default;
};

class Object
{
public:
	Object();
	shared_ptr<Material> m_pMtrl;
	virtual ~Object() = default;
};

class ObjectHittable : public Object
{
public:
	ObjectHittable() = default;
	
public:
	virtual bool Hit(const Ray& r, double t1, double t2, RecordHit& rcd) const = 0;
};

class Sphere : public ObjectHittable
{
public:
	Sphere() = delete;
	Sphere(Point3 center, double radius, shared_ptr<Material> mtrl = nullptr);
	virtual bool Hit(const Ray& r, double t1, double t2, RecordHit& rcd) const override;

public:
	static Vec3 GenerateRandomInUnitSphere();

private:
	Point3 m_vCenter;
	double m_dRadius;
};