#pragma once
#include "Artifact.hpp"

class CursedStone : public Artifact
{
public:
    void applyEffect(SuperHero &hero);
};
