workspace "TheGameEngine"
	architecture "x64"

	configurations {"Debug", "Release", "Distribution"}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "TheGameEngine"
	location "TheGameEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files{ "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}
	
	includedirs {"%{prj.name}/3rdParty/spdlog/include;"}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {"PLATFORM_WINDOWS", "BUILD_DLL"}
		 
		postbuildcommands {("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")}

	filter "configurations:Debug"
		defines "DEBUG"
		symbols "On"	
		
	filter "configurations:Release"
		defines "RELEASE"
		symbols "On"	
		
	filter "configurations:Distribution"
		defines "DISTRIBUTION"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}
	
	includedirs {"TheGameEngine/3rdParty/spdlog/include;", "TheGameEngine/src"}

	links{ "TheGameEngine" }

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {"PLATFORM_WINDOWS"}
		 
	filter "configurations:Debug"
		defines "DEBUG"
		symbols "On"	
		
	filter "configurations:Release"
		defines "RELEASE"
		symbols "On"	
		
	filter "configurations:Distribution"
		defines "DISTRIBUTION"
		symbols "On"