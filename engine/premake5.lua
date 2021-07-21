project "engine"
	kind "SharedLib"
	language "C++"
	cppdialect "C++11"

	architecture "x64"
	
	targetdir "../bin"
	objdir "obj"

	files {
		"include/**.hpp",
		"src/**.hpp",
		"src/**.cpp"
	}

	includedirs {
		"include"
	}

	defines {
		"ENGINE_EXPORT_SYMBOLS"
	}

	filter "configurations:debug"
		runtime "debug"
		symbols "on"
	
	filter "configurations:release"
		runtime "release"
		optimize "on"
