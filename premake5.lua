workspace "bezGameEngine"
  architecture "x86"

  configurations {
    "Debug",
    "Release"
  }

  outputDir ="/%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}/" 

  include "bezGameEngine/vendor/imgui"

  includeDir = {}
  includeDir["bezGameEngine"] = "bezGameEngine/src"
  includeDir["ImGui"] = "bezGameEngine/vendor/imgui"
  includeDir["glm"] = "bezGameEngine/vendor/glm"
  includeDir["sdl"] = "bezGameEngine/vendor/sdl"
  includeDir["glew"] = "bezGameEngine/vendor/glew"

  project "bezGameEngine"

    location "./bezGameEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    --staticruntime "on"
    

    pchheader ( "stdafx.hpp" )
    pchsource ( "bezGameEngine/src/stdafx.cpp" )

    objdir("obj/%{prj.name}" .. outputDir)

    includedirs { 
      ".",
      "%{prj.name}/src",
      "%{prj.name}/Platform"
    }

    targetdir("bin/%{prj.name}" .. outputDir)

    includedirs { 
      includeDir["ImGui"],
      includeDir["glm"],
      includeDir["glew"],
      includeDir["sdl"]
    }

    files {
      "%{prj.name}/src/bez/**.hpp",
      "%{prj.name}/src/bez/**.cpp",
      "%{prj.name}/src/*.hpp",
      "%{prj.name}/src/*.cpp",
      "%{prj.name}/src/Platform/OpenGL/**",
    }

    -- Included premake files of vendor applications
--    include { } -- --


    links { "imgui", "SDL2"}

    filter "system:linux"
      system "linux"
      files{
        "%{prj.name}/src/Platform/linux/**"
      }
      links { "GL", "GLEW" } 

    filter "system:windows"
      system "windows"
      systemversion "latest"
      files{
        "%{prj.name}/src/Platform/windows/**"
      }
      links { "opengl32", "glew32" }
    
    filter "configurations:Debug"
      runtime "Debug"
      symbols "on"


    filter "configurations:Release"
      runtime "Release"
      optimize "on"



  project "sandbox"

    location "./sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    
    objdir("obj/%{prj.name}" .. outputDir)
    targetdir("bin/%{prj.name}" .. outputDir)

    includedirs { 
      ".",
      "%{prj.name}/include",
    }

    includedirs {
      includeDir["ImGui"],
      includeDir["glm"],
      includeDir["glew"],
      includeDir["bezGameEngine"],
      includeDir["sdl"],
    }

    files {
      "%{prj.name}/src/**.cpp",
      "%{prj.name}/include/**.h",
    }

    -- Included premake files of vendor applications
--    include { } -- --


    links { "bezGameEngine", "SDL2", "imgui" }

    filter "system:linux"
      system "linux"
      links { "GL" }

    filter "system:windows"
      system "windows"
      systemversion "latest"
      links { "opengl32", "glew32" }
    
    filter "configurations:Debug"
      symbols "on"

    filter "configurations:Release"
      optimize "on"

