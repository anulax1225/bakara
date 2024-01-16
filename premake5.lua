workspace "Bakara"
    architecture "x64"
    configurations { "Debug", "Release" }
    startproject "Sandbox"

    outputdir = "%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}"

project "Bakara"
    location "bakara"
    kind "StaticLib"
    language "C++"

    targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    {
        "%{prj.location}/src/**.hpp",
        "%{prj.location}/src/**.cpp",
    }

project "Sandbox"
    location "sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    systemversion "latest"

    targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    {
        "%{prj.location}/src/**.hpp",
        "%{prj.location}/src/**.cpp",
    }

    includedirs 
    {
        "%{wks.location}/bakara/src",
    }

    links 
    {
        "Bakara"
    }



