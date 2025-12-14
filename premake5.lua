workspace "NutsEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    IncludeDir = {}
    IncludeDir["GLFW"] = "NutsEngine/vendor/GLFW/include"
    IncludeDir["Glad"] = "NutsEngine/vendor/Glad/include"
    IncludeDir["imgui"] = "NutsEngine/vendor/imgui/include"

    include "NutsEngine/vendor/GLFW"
    include "NutsEngine/vendor/Glad"
    include "NutsEngine/vendor/imgui"

project "NutsEngine"
    location "NutsEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader"nepch.h"
    pchsource "NutsEngine/src/nepch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
    }

    links{
        "GLFW",
        "Glad",
        "imgui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "on"
        systemversion "latest"

        defines
        {
            "NUTSENGINE_PLATFORM_WINDOWS",
            "NUTSENGINE_BUILD_DLL",
            "_MBCS",
            "GLFW_INCLUDE_NONE"
        }

        -- 🔹 UTF-8 DERLEME SEÇENEĞİ
        buildoptions { "/utf-8" }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
        }

    filter "configurations:Debug"
        defines "NE_DEBUG"
        buildoptions "/MDd"
        symbols "on"

    filter "configurations:Release"
        defines "NE_RELEASE"
        buildoptions "/MD"
        optimize "on"

    filter "configurations:Dist"
        defines "NE_DIST"
        buildoptions "/MD"
        optimize "on"

project "SandBox"
    location "SandBox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "NutsEngine/vendor/spdlog/include",
        "NutsEngine/src"
    }

    links
    {
        "NutsEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "on"
        systemversion "latest"

        defines
        {
            "NUTSENGINE_PLATFORM_WINDOWS",
            "_MBCS"
        }

        -- 🔹 UTF-8 DERLEME SEÇENEĞİ
        buildoptions { "/utf-8" }

    filter "configurations:Debug"
        defines "NE_DEBUG"
        symbols "on"

    filter "configurations:Release"
        defines "NE_RELEASE"
        optimize "on"

    filter "configurations:Dist"
        defines "NE_DIST"
        optimize "on"
