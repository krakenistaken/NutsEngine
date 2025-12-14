#include <nepch.h>
#include <NutsEngine.h>
#include <stdio.h>

class Sandbox : public NutsEngine::App {
public:
	Sandbox() 
	{
		
	}

	~Sandbox()
	{
	
	}

};



NutsEngine::App* NutsEngine::CreateApp() {
	return new Sandbox();//returns the app we are building
}