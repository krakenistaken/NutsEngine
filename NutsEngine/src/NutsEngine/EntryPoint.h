#pragma once

#ifdef NUTSENGINE_PLATFORM_WINDOWS

extern NutsEngine::App* NutsEngine::CreateApp();

int main(int argc, char** argv) {
	NutsEngine::Log::Init(); //here for now 
	NE_CORE_WARN("logg");
	int a = 31;
	float b = 32;
	NE_INFO("alogg {1}, {0}", a, b);


	auto app = NutsEngine::CreateApp(); //create app by calling the function(in SandBoxApp.cpp atm)
	app->Run(); //will run while(true) loop 
	delete app;
}

#endif
