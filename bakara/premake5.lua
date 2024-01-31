project "bakara"
    language "C++"
    cppdialect "C++17"

    targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")


    files 
    {
        "vendor/glm/glm/**.hpp",
        "vendor/glm/glm/**.inl",
        "src/**.h",
        "src/**.cpp",
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "GLFW_INCLUDE_NONE"
    }

    includedirs 
    {
        "%{IncludeDirs.bakara}",
        "%{IncludeDirs.glm}",
        "%{IncludeDirs.spdlog}",
        "%{IncludeDirs.glad}",
        "%{IncludeDirs.glfw}"
    }

    links 
    {
        "GLFW",
        "GLAD"
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
        kind "StaticLib"
        staticruntime "on"
        defines 
        { 
            "BK_PLATFORM_WINDOWS" 
        }

        links
        {
            "opengl32.lib"
        }

    filter "system:linux"
        kind "SharedLib"
        staticruntime "off"

        files
        {
            "vendor/glm/glm/**.cpp"
        }

        defines 
        { 
            "BK_PLATFORM_LINUX" 
        }

        links 
        {
            "GL"
        }

