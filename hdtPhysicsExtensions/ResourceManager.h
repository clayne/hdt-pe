#pragma once

#include <functional>
#include <unordered_map>

#include "Thread.h"
#include "ppapi_helper.h"
#include "netimmerse_helper.h"

class ResourceManager
{
public:

	struct NiObjectProxy
	{
		MEMBER_FN_PREFIX(NiObjectProxy);
		DEFINE_MEMBER_FN_HOOK(release, void, 0x00ab5360);

		void myRelease();
	};

	static ResourceManager* get();

	bool RegisterCallback(NiObject* object, std::function<void(NiObject*)> callback);
	void UnregisterCallback(NiObject* object);

private:

	ResourceManager(void);
	~ResourceManager(void);

	friend struct NiObjectProxy;

	std::unordered_map<NiObject*, std::function<void(NiObject*)>> m_callbacks;
	Lockable m_lock;
};
