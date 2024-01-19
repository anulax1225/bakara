project "bakara"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

    files 
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs 
    {
        "%{IncludeDirs.bakara}",
        "%{IncludeDirs.glm}",
        "%{IncludeDirs.spdlog}",
        "%{IncludeDirs.glfw}"
    }

    links 
    {
        "glm",
        "glfw"
    }

    filter "configurations:Debug"
        defines 
        { 
            "BK_DEBUG",
            "DEBUG"
        }
        runtime "Debug"
        symbols "on"


    filter "configurations:Release"
        defines 
        { 
            "BK_RELEASE",
            "NDEBUG"
        }
        runtime "Release"
        optimize "on"

    filter "system:windows"
        defines 
        { 
            "BK_PLATFORM_WINDOWS" 
        }

    filter "system:linux"
        defines 
        { 
            "BK_PLATFORM_LINUX" 
        }