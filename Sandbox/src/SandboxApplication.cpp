#include "TheGameEngine.h"

class Sandbox : public TheGameEngine::Application
{
public:
	Sandbox() {}
	~Sandbox() {}
};

TheGameEngine::Application* TheGameEngine::CreateApplication() {
	
	return new Sandbox();

}