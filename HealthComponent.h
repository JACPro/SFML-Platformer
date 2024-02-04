#pragma once

#include "Component.h"

class HealthComponent : public Component
{
public:
	HealthComponent(float maxHealth);

	void ApplyDamage(float damage);
	bool IsDead();
	float GetCurrHealth() { return mCurrHealth; }
	float GetMaxHealth() { return mMaxHealth; }

private:
	float mMaxHealth;
	float mCurrHealth;
};
