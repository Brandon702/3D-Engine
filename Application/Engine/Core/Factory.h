#pragma once
#include <map>
#include <functional>

namespace nc
{
	template<typename TBase>
	class CreatorBase
	{
	public:
		virtual TBase* Create() const = 0;
	};

	template<typename T, typename TBase>
	class Creator : public CreatorBase<TBase>
	{
	public:
		TBase* Create() const override
		{
			return new T;
		}
	};

	template<typename TBase>
	class Prototype : public CreatorBase<TBase>
	{
	public:
		Prototype(TBase* instance) : m_instance{ instance } {}
		TBase* Create() const override
		{
			return m_instance->Clone();
		}

	private:
		TBase* m_instance;
	};

	template<typename TBase, typename TKey>
	class Factory
	{
	public:
		template<typename T = TBase>
		T* Create(TKey key);
		void Register(TKey key, CreatorBase<TBase>* creator);

	protected:
		std::map<TKey, CreatorBase<TBase>*> m_registry;
	};


	template<typename TBase, typename TKey>
	template<typename T>
	inline T* Factory<TBase, TKey>::Create(TKey key)
	{
		T* object{ nullptr };

		auto iter = m_registry.find(key);
		if (iter != m_registry.end())
		{
			CreatorBase<TBase>* creator = iter->second;
			object = dynamic_cast<T*>(creator->Create());
		}

		return object;
	}

	template<typename TBase, typename TKey>
	inline void Factory<TBase, TKey>::Register(TKey key, CreatorBase<TBase>* creator)
	{
		m_registry[key] = creator;
	}

}