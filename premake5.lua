project "bakara"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"

    targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    buildoptions { "-fPIC" }
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
        "IMGUI_IMPL_OPENGL_LOADER_GLAD",
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
        "GLFW",
        "GLAD",
        "ImGui",
        "bakatools"
    }

    filter "configurations:Debug"
        buildoptions { "-Wall", "-Wextra" }
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

        links
        {
            "opengl32.lib"
        }

    filter "system:linux"
        staticruntime "on"

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

