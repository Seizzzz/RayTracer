#include "Scene.h"
#include "Common.h"
#include "Material.h"
using std::dynamic_pointer_cast;
using std::make_shared;

bool Scene::Hit(const Ray& r, double t1, double t2, RecordHit& rec) const
{
	bool hitted = false;
	double dist = t2;
	
	for(const auto& obj : objects)
	{
		auto obj_hittable = dynamic_pointer_cast<ObjectHittable>(obj);
		if(obj_hittable)
		{
			RecordHit rec_now;
			if(obj_hittable->Hit(r, t1, dist, rec_now))
			{
				hitted = true;
				rec = rec_now;
				dist = rec_now.t;
			}
		}
	}
    return hitted;
}

void Scene::GenerateScene()
{
	auto ground_mtrl = make_shared<MtrlLambert>(Color(0.5, 0.5, 0.5));
	AddObject(make_shared<Sphere>(Point3(0, -1000, 0), 1000, ground_mtrl));
	
	for (auto a = -3; a < 3; ++a)
	{
		for (auto b = -3; b < 3; ++b)
		{
			auto rd_mtrl = GenerateRandomDouble();
			Point3 pos(a + 0.9 * GenerateRandomDouble(), 0.2, b + 0.9 * GenerateRandomDouble());

			if((pos - Point3(4,0.2,0)).norm() > 0.9)
			{
				shared_ptr<Material> mtrl;
				if(rd_mtrl < 0.8)
				{
					auto albedo = Color::GenerateRandom() & Color::GenerateRandom();
					mtrl = make_shared<MtrlLambert>(albedo);
				}
				else if(rd_mtrl < 0.95)
				{
					auto albedo = Color::GenerateRandom(0.5, 1);
					auto fuzz = GenerateRandomDouble(0, 0.5);
					mtrl = make_shared<MtrlMetal>(albedo, fuzz);
				}
				else
				{
					mtrl = make_shared<MtrlDielectric>(1.5);
				}

				AddObject(make_shared<Sphere>(pos, 0.2, mtrl));
			}
		}
	}

	auto large_mtrl1 = make_shared<MtrlDielectric>(1.5);
	auto large_mtrl2 = make_shared<MtrlLambert>(Color(0.4, 0.2, 0.1));
	auto large_mtrl3 = make_shared<MtrlMetal>(Color(0.7, 0.6, 0.5));
	AddObject(make_shared<Sphere>(Point3(0, 1, 0), 1.0, large_mtrl1));
	AddObject(make_shared<Sphere>(Point3(-4, 1, 0), 1.0, large_mtrl2));
	AddObject(make_shared<Sphere>(Point3(4, 1, 0), 1.0, large_mtrl3));
}
