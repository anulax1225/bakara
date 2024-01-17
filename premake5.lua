workspace "Bakara"
    architecture "x64"
    configurations { "Debug", "Release" }
    startproject "sandbox"

    outputdir = "%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}"

group "Dependencies"
    include "bakara/vendor"
group ""

group "Core"
	include "bakara"
group ""

group "App"
	include "sandbox"
group ""




