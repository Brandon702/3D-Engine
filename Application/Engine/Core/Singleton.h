#pragma once

namespace nc
{
	template<typename T>
	class Singleton
	{
	public:
		Singleton(const Singleton&) = delete; //Copy
		Singleton& operator = (const Singleton&) = delete; //Assign

		static T& Instance()
		{
			static T instance;
			return instance;
		}

	protected:
		Singleton() {}
	};
}