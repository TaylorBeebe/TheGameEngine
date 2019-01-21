#pragma once
#include <stdio.h>


#ifdef PLATFORM_WINDOWS

extern TheGameEngine::Application* TheGameEngine::CreateApplication();

int main(int argc, char **argv) 
{
	TheGameEngine::Log::Init();
	CORE_WARN("Initialized Logger");
	int a = 10;
	INFO("Test Var={0}", a); 

	printf("Welcome to TheGameEngine\n");
	auto app = TheGameEngine::CreateApplication();
	app->Run();
	delete app;

}

#endif