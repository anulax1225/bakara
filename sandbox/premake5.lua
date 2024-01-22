project "sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    systemversion "latest"

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
        "%{IncludeDirs.spdlog}",
        "%{IncludeDirs.glm}",
    }

    links 
    {
        "bakara",
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
    staticruntime "on"
    defines 
    { 
        "BK_PLATFORM_WINDOWS" 
    }

filter "system:linux"
    staticruntime "off"
    defines 
    { 
        "BK_PLATFORM_LINUX" 
    }
