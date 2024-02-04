#include "HealthComponent.h"
#include <cfloat>

HealthComponent::HealthComponent(float maxHealth)
	: mMaxHealth(maxHealth), mCurrHealth(maxHealth)
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

bool HealthComponent::IsDead()
{
	return mCurrHealth < FLT_EPSILON;
}
