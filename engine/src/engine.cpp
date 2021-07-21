#include <stdio.h>
#include <windows.h>

#include "engine.hpp"

namespace engine {
	typedef ScriptBase* (*GetInstanceProc)();

	void do_the_scripts(const std::string& dll_name, const std::string& class_name) {
		HMODULE handle = LoadLibraryA(dll_name.c_str());
		if (!handle) {
			fprintf(stderr, "Failed to load library \"%s\"", dll_name.c_str());
			return;
		}

		/* This weird looking function name was taken
		 * from Dependency Walker - open your dynamic library
		 * there and check the name of functions. */
		GetInstanceProc get_instance =
			(GetInstanceProc)GetProcAddress(handle, ("?get_instance@" + class_name + "@@SAPEAVScriptBase@engine@@XZ").c_str());
		if (!get_instance) {
			fprintf(stderr, "Failed to get get_instance function on %s", class_name.c_str());
			return;
		}

		ScriptBase* script = get_instance();

		for (int i = 0; i < 100; i++) {
			script->on_update(i);
		}

		delete script;
	}

	void some_useful_function() {
		printf("Hello, from engine::some_useful_function\n");
	}
}
