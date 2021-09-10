#pragma once
#include "Ray.h"

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
public:
	RecordHit() = default;
};

class Object
{
public:
	Object() = default;
	virtual ~Object() = default;
};

class ObjectHittable : public Object
{
public:
	virtual bool Hit(const Ray& r, double t1, double t2, RecordHit& rcd) const = 0;
};

class Sphere : public ObjectHittable
{
public:
	Sphere() = delete;
	Sphere(Point3 center, double radius) : m_vCenter(center), m_dRadius(radius) {}
	virtual bool Hit(const Ray& r, double t1, double t2, RecordHit& rcd) const override;

private:
	Point3 m_vCenter;
	double m_dRadius;
};
