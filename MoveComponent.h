#pragma once

#include "Component.h"

class MoveComponent : public Component
{
public:
	MoveComponent(bool hasGravity);

private:
	bool mHasGravity;
};
