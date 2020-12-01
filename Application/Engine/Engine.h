#pragma once

#include <glad/glad.h>

#include "Core/Timer.h"
#include "Core/File.h"
#include "Core/Assert.h"

#include "Engine/Math/Math.h"

#include "Graphics/Renderer.h"
#include "Graphics/Program.h"
#include "Graphics/Texture.h"
#include "Graphics/VertexArray.h"
#include "Graphics/VertexIndexArray.h"

#include "Resources/ResourceManager.h"
#include "Input/InputSystem.h"

#include <vector>

namespace nc
{
	class System;

	class Engine
	{
	public:
		bool Startup();
		void Shutdown();

		void Update();

		template<typename T>
		T* GetSystem();

		FrameTimer& GetTimer() { return m_timer; }
	protected:
		std::vector<System*> m_systems;
		FrameTimer m_timer;
	};

	template<typename T>
	T* Engine::GetSystem()
	{
		T* result{ nullptr };

		for (auto system : m_systems)
		{
			result = dynamic_cast<T*>(system);
			if (result) break;
		}

		return result;
	}
}
