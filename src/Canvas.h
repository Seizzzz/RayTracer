#pragma once
#include "Common.h"
#include "Vec3.h"
#include <iostream>
#include <functional>
using std::function;

class Canvas
{
public:
	void Render(const std::function<Color(uint32_t&, uint32_t&)>& func) const;
	void WriteColor(Color pxColor, uint32_t pxSamples) const;

private:
	std::ostream& outPPM = std::cout;
	std::ostream& outInfo = std::cerr;
};