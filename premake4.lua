solution "bezGameEngine"
	platforms "x64"

	configurations {
		"Debug",
		"Release"
	}

	outputDir =_ACTION .. "/" 

	include "bezGameEngine/vendor/imgui"

	includeDir = {}
	includeDir["ImGui"] = "bezGameEngine/vendor/imgui"
	includeDir["bezGameEngine"] = "bezGameEngine/src"

	project "bezGameEngine"

		location "./bezGameEngine"
		kind "StaticLib"
		language "C++"
		buildoptions { "-std=c++17" }
		
		outputdir = outputDir

		pchheader ( project().name .. "/src/stdafx.hpp" )
		pchsource ( project().name .. "/src/stdafx.cpp" )

		objdir("obj/" .. outputDir .. project().name .. "/")

		includedirs { 
			".",
			project().name .. "/src",
			project().name .. "/Platform"
		}

		includedirs { 
			includeDir["ImGui"]
		}

		files {
			project().name .. "/src/**.hpp",
			project().name .. "/src/**.cpp",
		}

		-- Included premake files of vendor applications
--		include { } -- --


		links { "imgui" }

		if os.get() == "linux" then
			files{
				project().name .. "/Platform/linux/**"
			}
			links { "SDL2", "GL", "GLEW" }
		end
		
		configuration "Debug"
			targetdir("bin/" .. outputDir .. project().name .. "/debug")
			flags { "StaticRuntime", "Symbols", "ExtraWarnings" }

		configuration "Release"
			targetdir("bin/" .. outputDir .. project().name .. "/release")
			flags { "StaticRuntime", "OptimizeSpeed", "FatalWarnings" }

	project "sandbox"

		location "./sandbox"
		kind "ConsoleApp"
		language "C++"
		buildoptions { "-std=c++17" }
		
		outputdir = outputDir

		objdir("obj/" .. outputDir .. project().name .. "/")

		includedirs { 
			".",
			project().name .. "/include",
		}

		includedirs {
			includeDir["ImGui"],
			includeDir["bezGameEngine"],
		}

		files {
			project().name .. "/src/**.cpp",
			project().name .. "/include/**.h",
		}

		-- Included premake files of vendor applications
--		include { } -- --


		links { "bezGameEngine", "SDL2", "GLEW", "GL", "imgui" }

		configuration "gmake"
			files{
				project().name .. "/Platform/linux/**"
			}
		
		configuration "Debug"
			targetdir("bin/" .. outputDir .. project().name .. "/debug")
			flags { "StaticRuntime", "Symbols", "ExtraWarnings" }

		configuration "Release"
			targetdir("bin/" .. outputDir .. project().name .. "/release")
			flags { "StaticRuntime", "OptimizeSpeed", "FatalWarnings" }

