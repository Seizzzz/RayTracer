#pragma once
#include <iostream>
#include <fstream>
#include <functional>
#include "Vec3.h"
using std::function;

class Canvas
{
public:
	Canvas();
	~Canvas();

public:
	void Render(const function<Color(uint32_t&, uint32_t&)>& func);
	void WriteColor(Color pxColor, uint32_t pxSamples);

private:
	std::ofstream outPPM;
	std::ostream& outInfo = std::cerr;
};