#include "nepch.h"
#include "App.h"
#include "Window.h"

#include "Log.h"
#include "GLFW/glfw3.h"
#include "glad/glad.h"


namespace NutsEngine {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)


	App::App() {
		// any init code
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(App::OnEvent));
	}


	void App::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void App::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}

	void App::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(App::OnWindowClose));
		NE_CORE_TRACE("EVENT: {}", e.ToString());


		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); ++it)
		{
			(*it)->OnEvent(e);
			if (e.m_Handled)
				break;
			
		}
	}





	void App::Run() { //getting called at entrypoint
		while (m_runnning)
		{
			glClearColor(1,0,1,1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
		
	}


	bool App::OnWindowClose(WindowCloseEvent& e) {
		m_runnning = false;
		return true;
	}




	App::~App() {
		// optional cleanup
	}
}