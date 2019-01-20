#pragma once
#include "Core.h"


namespace TheGameEngine {

	class ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();
	
	};

	//define in client
	Application* CreateApplication();
}
