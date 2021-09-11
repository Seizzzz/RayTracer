#include "Canvas.h"
#include "Common.h"

Canvas::Canvas()
{
	outPPM.open(Common::g_PPMFileLocation);
}

Canvas::~Canvas()
{
	outPPM.close();
}

void Canvas::Render(const function<Color(uint32_t&, uint32_t&)>& func)
{
	outPPM << "P3\n" << Common::g_ImageWidth << ' ' << Common::g_ImageHeight << "\n255\n";
	for (auto line = 0u; line < Common::g_ImageHeight; ++line)
	{
		auto j = Common::g_ImageHeight - line;
		outInfo << "\nLine remaining: " << j << std::flush;
		for (auto i = 0u; i < Common::g_ImageWidth; ++i)
		{
			auto color = Color(0.0, 0.0, 0.0);
			for(auto times = 0u; times < Common::g_SamplesPerPixel; ++times)
			{
				color += func(i, j);
			}
			WriteColor(color, Common::g_SamplesPerPixel);
		}
	}
}

void Canvas::WriteColor(Color pxColor, uint32_t pxSamples)
{
	auto scale = 1.0 / pxSamples;
	pxColor = (scale * pxColor).gamma();
	
	outPPM
		<< static_cast<int>(256 * clamp(pxColor.x(), 0.0, 0.999)) << ' '
		<< static_cast<int>(256 * clamp(pxColor.y(), 0.0, 0.999)) << ' '
		<< static_cast<int>(256 * clamp(pxColor.z(), 0.0, 0.999)) << '\n';
}
