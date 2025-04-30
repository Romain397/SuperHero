#include "Hulk.hpp"

// Constructeur
Hulk::Hulk(const std::string &name, int health, int attackPower)
    : SuperHero(name, health, attackPower), rageMode(0) {}

// Capacité spécial de hulk
void Hulk::useSpecialAbility(SuperHero &target)
{
    if (rageMode == 0) // Si Hulk n'est pas encore en mode rage
    {
        rageMode = 2; // Active le mode rage pour 2 tours
        std::cout << getName() << " entre en rage!" << std::endl;
    }
    else
    {
        // Si Hulk est déjà en rage
        std::cout << getName() << " ne peut pas utiliser sa capacité spéciale, mode rage restant : " << rageMode << std::endl;
    }
}

// Attaque de Hulk
void Hulk::attack(SuperHero &target)
{
    int damage = getAttack(); // Récupère la puissance d'attaque de Hulk
    if (rageMode > 0)
    {
        damage *= 2; // Double les dégâts
        rageMode--;  // Réduction de la durée du mode rage
    }
    takeDamage(getHealth() * 0.05); // Perte de points de vie de Hulk après l'attaque (5% de sa santé)
    target.takeDamage(damage);
    std::cout << getName() << " attaque " << target.getName() << " pour " << damage << " points de dégâts." << std::endl;
}
