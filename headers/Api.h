#pragma once
#if defined(_WIN32)
	#if defined (BLOOD_MANAGER_DLL)
		#define BLOOD_MANAGER_API __declspec(dllexport)
	#else
		#define BLOOD_MANAGER_API __declspec(dllimport)
	#endif
#endif