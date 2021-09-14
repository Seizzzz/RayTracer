#include "Common.h"
#include "Canvas.h"
#include "Vec3.h"
#include "Ray.h"
#include "Scene.h"
#include "Object.h"
#include "Camera.h"
#include "Material.h"

void Draw()
{	
	Canvas cvs;

	Scene scn;
	scn.GenerateScene();
	
	Camera cma(Point3(13.0, 2.0, 3.0), Vec3(0.0, 0.0, 0.0), Vec3(0.0, 1.0, 0.0), 0.1);
	
	function<Color(const Ray& r, uint32_t times)> ray_color; //为了递归调用lambda函数
	ray_color = [&](const Ray& r, uint32_t times)->Color
	{
		if (times >= Common::g_TraceDepth) return Vec3(0.0, 0.0, 0.0);

		RecordHit rcd;
		if (scn.Hit(r, 0.001, Common::DOUBLE_MAX, rcd))
		{
			Ray out({ 0,0,0 }, { 0,0,0 });
			Color atteuat({ 0,0,0 });
			if(rcd.pMtrl->Scatter(r, rcd, atteuat, out))
			{
				return atteuat & ray_color(out, times + 1);
			}
		}

		auto unit_dir = r.Direction().unit();
		auto t = 0.5 * (1 + unit_dir.y()); //[-1,1]->[0,1]
		return Color(1.0, 1.0, 1.0).lerp(Color(0.5, 0.7, 1.0), t);
	};

	cvs.Render([&](uint32_t& i, uint32_t& j)
	{
		auto u = (i + GenerateRandomDouble()) / (Common::g_ImageWidth - 1);
		auto v = (j + GenerateRandomDouble()) / (Common::g_ImageHeight - 1);

		Ray r = cma.Beam(u, v);
		return ray_color(r, 0);
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