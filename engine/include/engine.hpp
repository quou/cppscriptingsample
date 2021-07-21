#pragma once

#if defined(ENGINE_EXPORT_SYMBOLS)
	#undef ENGINE_EXPORT_SYMBOLS

	#if defined(ENGINE_API)
		#undef ENGINE_API
	#endif

	#define ENGINE_API __declspec(dllexport)
#elif defined(ENGINE_IMPORT_SYMBOLS)
	#undef ENGINE_IMPORT_SYMBOLS

	#if defined(ENGINE_API)
		#undef ENGINE_API
	#endif
	#define ENGINE_API __declspec(dllimport)
#endif

#define ENGINE_CALL __cdecl

#include <string>

namespace engine {
	ENGINE_API void do_the_scripts(const std::string& dll_name, const std::string& class_name);
	ENGINE_API void some_useful_function();

	ENGINE_API class ScriptBase {
	public:
		virtual void on_update(double timestep) {}
	};
}
