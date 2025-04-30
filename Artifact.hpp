#pragma once
#include "SuperHero.hpp"

class Artifact
{
public:
    virtual void applyEffect(SuperHero &hero) = 0;
    virtual ~Artifact() {} // Destructeur virtuel pour l'héritage
};
