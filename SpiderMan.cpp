#include "SpiderMan.hpp"
#include <cstdlib>

// Constructeur
SpiderMan::SpiderMan(const std::string &name, int health, int attackPower)
    : SuperHero(name, health, attackPower) {}

// Capacité spécial de SpiderMan
void SpiderMan::useSpecialAbility(SuperHero &target)
{
    target.takeDamage(25); // Inflige 25 points de dégâts à la cible
    std::cout << getName() << " utilise 'Toile d'araignée' sur " << target.getName() << " pour 25 points de dégâts." << std::endl;
}

// Attaque de SpiderMan
void SpiderMan::attack(SuperHero &target)
{
    target.takeDamage(getAttack()); // Inflige des dégâts à la cible en fonction de la puissance d'attaque
    if (rand() % 10 < 3)            // 30% de chance d'immobiliser la cible
    {
        std::cout << getName() << " immobilise " << target.getName() << "!" << std::endl;
    }
}
