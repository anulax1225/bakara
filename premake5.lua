project "bakara"
    language "C++"
    cppdialect "C++17"

    targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")


    files 
    {
        "%{wks.location}/vendor/glm/glm/**.hpp",
        "%{wks.location}/vendor/glm/glm/**.inl",
        "%{wks.location}/vendor/imgui/misc/cpp/imgui_stdlib.cpp",
        "%{wks.location}/vendor/imgui/backends/imgui_impl_opengl3.cpp",
        "%{wks.location}/vendor/imgui/backends/imgui_impl_glfw.cpp",
        "src/**.h",
        "src/**.cpp",
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "GLFW_INCLUDE_NONE",
        "IMGUI_IMPL_OPENGL_LOADER_GLAD"
    }

    includedirs 
    {
        "%{IncludeDirs.bakara}",
        "%{IncludeDirs.glm}",
        "%{IncludeDirs.spdlog}",
        "%{IncludeDirs.glad}",
        "%{IncludeDirs.glfw}",
        "%{IncludeDirs.imgui}"

    }

    links 
    {
        "GLFW",
        "GLAD",
        "ImGui"
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

