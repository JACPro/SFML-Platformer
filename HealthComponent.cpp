#include "HealthComponent.h"
#include <cfloat>

HealthComponent::HealthComponent(float maxHealth)
	: mMaxHealth(maxHealth), mCurrHealth(maxHealth)
{
}

void HealthComponent::Update(float deltaTime)
{
}

void HealthComponent::ApplyDamage(float damage)
{
	mCurrHealth -= damage;
	if (mCurrHealth < 0.0f)
	{
		mCurrHealth = 0.0f;
	}
}

const bool HealthComponent::IsDead() const
{
	return mCurrHealth < FLT_EPSILON;
}
