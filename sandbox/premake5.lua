project "sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"
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
        "%{wks.location}/bakara/vendor",
        "%{wks.location}/bakara/src"
    }

    links 
    {
        "bakara"
    }
