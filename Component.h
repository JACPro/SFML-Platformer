#pragma once

#include "Entity.h"

class Component
{
public:
	Component();
	virtual ~Component() { }

	bool IsEnabled() { return mEnabled; }
	void Enable();
	void Disable();

private:
	bool mEnabled;
};
