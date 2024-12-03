#pragma once
#ifdef CURVELIBRARY_EXPORTS
#define CURVE_API __declspec(dllexport)
#else
#define CURVE_API __declspec(dllimport)
#endif