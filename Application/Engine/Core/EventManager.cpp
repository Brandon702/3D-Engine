#include "pch.h"
#include "EventManager.h"

void nc::EventManager::Subscribe(const std::string& type, function_t function, Object* owner)
{
	Observer observer;
	observer.function = function;
	observer.owner = owner;

	m_observers[type].push_back(observer);
}

void nc::EventManager::Notify(const Event& event)
{
	auto observers = m_observers[event.type];
	for (auto& observer : observers)
	{
		if (event.reciever == nullptr || event.reciever == observer.owner)
		{
		observer.function(event);
		}
	}
}
