#include "HealthPotion.hpp"

void HealthPotion::applyEffect(SuperHero &hero)
{
    // Restaure 20 points de vie au super-héros ciblé
    hero.restoreHealth(20);
    std::cout << hero.getName() << " a utilisé une potion de soin et récupère 20 points de vie." << std::endl;
}