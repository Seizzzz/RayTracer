#include "Common.h"
#include "Canvas.h"
#include "Vec3.h"
#include "Ray.h"
#include "Scene.h"
#include "Object.h"
#include "Camera.h"
using std::make_shared;

void Draw()
{
	Canvas cvs;

	Scene scn;
	scn.AddObject(make_shared<Sphere>(Point3(0, 0, -1), 0.5));
	scn.AddObject(make_shared<Sphere>(Point3(0, -100.5, -1), 100));

	Camera cma(Point3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, -1.0), Vec3(0.0, 1.0, 0.0));
	
	auto ray_color = [&](const Ray& r)
	{
		RecordHit rcd;
		if (scn.Hit(r, 0.0, Common::DOUBLE_MAX, rcd))
		{
			return VisualizeNormal(rcd.Normal);
		}

		auto unit_dir = r.Direction().unit();
		auto t = 0.5 * (1 + unit_dir.y()); //[-1,1]->[0,1]
		static auto base_color = Color(0.5, 0.7, 1.0);
		static auto dest_color = Color(1.0, 1.0, 1.0);
		return dest_color.lerp(base_color, t);
	};

	cvs.Render([&](uint32_t& i, uint32_t& j)
	{
		auto u = (i + random_double()) / (Common::g_ImageWidth - 1);
		auto v = (j + random_double()) / (Common::g_ImageHeight - 1);

		Ray r = cma.Beam(u, v);
		return ray_color(r);
	});
}

int main()
{
	try
	{
		Draw();
	}
	catch(...)
	{
		std::cerr << "Unexpected Error Occurred" << std::flush;
	}
}