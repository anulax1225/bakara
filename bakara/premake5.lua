project "bakara"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs 
    {
        "%{IncludeDirs.bakara}",
        "%{IncludeDirs.glm}",
        "%{IncludeDirs.spdlog}"
    }

    links 
    {
        "glm"
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