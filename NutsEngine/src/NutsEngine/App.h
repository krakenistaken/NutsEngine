#pragma once

#include"Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "Events/AppEvent.h"
#include "LayerStack.h"


namespace NutsEngine{


	class NUTSENGINE_API App
	{
	public:
		App();
		virtual ~App();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* Layer);
		void PushOverlay(Layer* Layer);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_runnning = true;
		LayerStack m_LayerStack;
	};


	//to be defined in client
	App* CreateApp();

}
