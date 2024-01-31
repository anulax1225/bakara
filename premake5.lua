workspace "Bakara"
    architecture "x64"
    configurations { "Debug", "Release" }
    startproject "sandbox"

    flags
	{
		"MultiProcessorCompile"
	}

    linkgroups "On"

outputdir = "%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}"

IncludeDirs = {}
IncludeDirs["bakara"] = "%{wks.location}/bakara/src"
IncludeDirs["vendor"] = "%{wks.location}/bakara/vendor"
IncludeDirs["spdlog"] = "%{wks.location}/bakara/vendor/spdloglib/include"
IncludeDirs["glm"] = "%{wks.location}/bakara/vendor/glm"
IncludeDirs["glfw"] = "%{wks.location}/bakara/vendor/glfw/include"
IncludeDirs["glad"] = "%{wks.location}/bakara/vendor/glad/include"


group "Dependencies"
    include "bakara/vendor"
group ""

group "Core"
	include "bakara"
group ""

group "App"
	include "sandbox"
group ""




