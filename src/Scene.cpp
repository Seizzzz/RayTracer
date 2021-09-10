#include "Scene.h"
using std::dynamic_pointer_cast;

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
