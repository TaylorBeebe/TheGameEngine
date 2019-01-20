#pragma once
#include <stdio.h>
#ifdef PLATFORM_WINDOWS

extern TheGameEngine::Application* TheGameEngine::CreateApplication();

int main(int argc, char **argv) 
{
	printf("Welcome to TheGameEngine\n");
	auto app = TheGameEngine::CreateApplication();
	app->Run();
	delete app;

}

#endif