#pragma once
#include <cstdint>
#include <limits>
#include <random>
#include "Vec3.h"

namespace Common
{
	const double	g_AspectRatio = 16.0 / 9.0;
	const double	g_FocalLength = 1.0;
	const uint32_t	g_ImageWidth = 400;
	const uint32_t	g_ImageHeight = static_cast<uint32_t>(g_ImageWidth / g_AspectRatio);
	const double	g_ViewPortHeight = 2.0;
	const double	g_ViewPortWidth = g_ViewPortHeight * g_AspectRatio;
	const uint32_t	g_SamplesPerPixel = 20;
	const double	DOUBLE_MAX = std::numeric_limits<double>::max();
}

inline double random_double()
{
	static std::uniform_real_distribution<double> dstr(0.0, 1.0);
	static std::mt19937 gen;
	return dstr(gen);
}

inline double clamp(double x, double min, double max)
{
	if (x > max) return max;
	if (x < min) return min;
	return x;
}

inline Color VisualizeNormal(Vec3 normal)
{
	return 0.5 * (normal + Vec3(1.0, 1.0, 1.0)); //[-1,1]->[0,1]
}