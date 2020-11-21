#pragma once
#include "Singleton.h"
#include <string>
#include <list>
#include <map>
#include <functional>

namespace nc
{
	class Object;

	struct Event
	{
		std::string type;
		Object* sender{ nullptr };
		Object* reciever{ nullptr };
		void* data;
	};

	class EventManager : public Singleton<EventManager>
	{
	public:
		using function_t = std::function<void(const Event&)>;

		struct Observer
		{
			function_t function;
			Object* owner{ nullptr };
		};
	public:
		void Subscribe(const std::string& type, function_t function, Object* owner = nullptr);
		void Notify(const Event& event);

	private:
		std::map<std::string, std::list<Observer>> m_observers;
	};
}