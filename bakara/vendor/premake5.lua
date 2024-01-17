project "glm"
    location "glm"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    {
        "glm/**.hpp",
        "glm/**.inl",
        "glm/**.cpp"
    }

    includedirs 
    {
        "%{wks.location}/bakara/vendor"
    }
