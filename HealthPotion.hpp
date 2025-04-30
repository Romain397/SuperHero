#pragma once
#include "Artifact.hpp"

class HealthPotion : public Artifact
{
public:
    void applyEffect(SuperHero &hero);
};
