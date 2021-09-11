#pragma once
#include "Object.h"
#include <vector>
#include <memory>
class Object;
using std::vector;
using std::shared_ptr;

class Scene
{
public:
	Scene() = default;
	void AddObject(shared_ptr<Object> obj) { objects.push_back(obj); }
	void ClearObjects() { objects.clear(); }
	virtual bool Hit(const Ray& r, double t1, double t2, RecordHit& rec) const;
	
public:
	vector<shared_ptr<Object>> objects;
};