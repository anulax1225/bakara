project "bakara"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"

    targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    {
        "%{wks.location}/vendor/glm/glm/**.hpp",
        "%{wks.location}/vendor/glm/glm/**.inl",
        "src/bakara/**.h",
        "src/bakara/**.cpp",
        "src/platforms/**.h",
        "src/platforms/**.cpp",
        "src/*pch.*",
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "GLFW_INCLUDE_NONE",
        "BKMOD_ALL"
    }

    includedirs 
    {
        "%{IncludeDirs.bakara}",
        "%{IncludeDirs.glm}",
        "%{IncludeDirs.spdlog}",
        "%{IncludeDirs.glad}",
        "%{IncludeDirs.glfw}",
        "%{IncludeDirs.imgui}",
        "%{IncludeDirs.bakatools}"
    }

    links 
    {
        "bakatools",
        "GLFW",
        "GLAD",
        "ImGui"
    }

    filter "configurations:Debug"
        --buildoptions { "-Wall", "-Wextra" }
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
        buildoptions "/MT"
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
        staticruntime "on"
        buildoptions { "-fPIC" }
        files
        {
            "%{wks.location}/vendor/glm/glm/**.cpp"
        }

        defines 
        { 
            "BK_PLATFORM_LINUX" 
        }

        links 
        {
            "GL"
        }

