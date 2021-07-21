workspace "scripttest"
	configurations { "debug", "release" }

	startproject "sandbox"

include "engine"
include "scripts"
include "sandbox"