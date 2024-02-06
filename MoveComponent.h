#pragma once

#include "Component.h"

class MoveComponent : public Component
{
public:
	MoveComponent(bool hasGravity);
	virtual ~MoveComponent() { }

private:
	bool mHasGravity;
};
