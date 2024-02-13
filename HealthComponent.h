#pragma once

#include "Component.h"

class HealthComponent : public Component
{
public:
	HealthComponent(float maxHealth);
	virtual ~HealthComponent() { }

	virtual void Update(float deltaTime) override;

	void ApplyDamage(float damage);
	const bool IsDead() const;
	const float GetCurrHealth() const { return mCurrHealth; }
	const float GetMaxHealth() const { return mMaxHealth; }

private:
	float mMaxHealth;
	float mCurrHealth;
};
