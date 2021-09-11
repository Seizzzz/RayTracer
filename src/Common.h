#pragma once
#include <cstdint>
#include <limits>
#include <random>
#include "Vec3.h"
#include <string>
#include "Object.h"
using std::string;

namespace Common
{
	const double	g_AspectRatio = 16.0 / 9.0;
	const double	g_FocalLength = 1.0;
	const uint32_t	g_ImageWidth = 400;
	const uint32_t	g_ImageHeight = static_cast<uint32_t>(g_ImageWidth / g_AspectRatio);
	const double	g_ViewPortHeight = 2.0;
	const double	g_ViewPortWidth = g_ViewPortHeight * g_AspectRatio;
	const uint32_t	g_SamplesPerPixel = 5;
	const uint32_t	g_TraceDepth = 50;
	const double	DOUBLE_MAX = std::numeric_limits<double>::max();
	const string	g_PPMFileLocation = "../image.ppm";
}

inline double GenerateRandomDouble(double min = 0.0, double max = 1.0)
{
	static std::uniform_real_distribution<double> dstr(0.0, 1.0);
	static std::mt19937 gen;
	return min + (max - min) * dstr(gen);
}

inline double clamp(const double& x, const double& min, const double& max)
{
	if (x > max) return max;
	if (x < min) return min;
	return x;
}

inline Color VisualizeNormal(const Vec3& normal)
{
	return 0.5 * (normal + Vec3(1.0, 1.0, 1.0)); //[-1,1]->[0,1]
}

inline Vec3 RandomDiffuse(const Vec3& normal)
{
	auto random_vec = Sphere::GenerateRandomInUnitSphere().unit();
	if (random_vec * normal > 0) return random_vec; //outward
	return -random_vec; //inward
}

inline Vec3 reflect(const Vec3& in, const Vec3& normal)
{
	return in - 2 * (in * normal) * normal;
}