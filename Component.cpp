#include "Component.h"

Component::Component()
	: mEnabled(true)
{
}

void Component::Enable()
{
	mEnabled = true;
}

void Component::Disable()
{
	mEnabled = false;
}
