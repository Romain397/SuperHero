#include "CursedStone.hpp"

void CursedStone::applyEffect(SuperHero &hero)
{
    hero.takeDamage(10);
    std::cout << hero.getName() << " a été affecté par la pierre maudite et perd 10 points de vie." << std::endl;
}