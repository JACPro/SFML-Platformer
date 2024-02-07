#pragma once

#include "Component.h"

class HealthComponent : public Component
{
public:
	HealthComponent(float maxHealth);
	virtual ~HealthComponent() { }

	virtual void Update(float deltaTime) override;

	void ApplyDamage(float damage);
	bool IsDead();
	float GetCurrHealth() { return mCurrHealth; }
	float GetMaxHealth() { return mMaxHealth; }

private:
	float mMaxHealth;
	float mCurrHealth;
};
