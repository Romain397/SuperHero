#include "PowerAmulet.hpp"

void PowerAmulet::applyEffect(SuperHero &hero)
{
    hero.setAttack(hero.getAttack() + 5);
    std::cout << hero.getName() << " a utilisé une amulette de puissance et son attaque augmente de 5." << std::endl;
}