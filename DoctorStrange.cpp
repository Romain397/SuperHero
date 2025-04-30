#include "DoctorStrange.hpp"
#include <cstdlib> // Pour la fonction rand()

// Constructeur
DoctorStrange::DoctorStrange(const std::string &name, int health, int attackPower)
    : SuperHero(name, health, attackPower) {}

// Capacité spécial de DoctorStrange
void DoctorStrange::useSpecialAbility(SuperHero &target)
{
    int healAmount = rand() % 16 + 15; // Génère un nombre entre 15 et 30
    restoreHealth(healAmount);         // Restaure les points de vie
    std::cout << getName() << " utilise 'Bouclier Mystique' et se soigne de " << healAmount << " points de vie." << std::endl;
}

// Attaque de base
void DoctorStrange::attack(SuperHero &target)
{
    int damage = rand() % 16 + 10; // Génère un nombre entre 10 et 25
    target.takeDamage(damage);     // Applique les dégâts à la cible
    std::cout << getName() << " attaque " << target.getName() << " pour " << damage << " points de dégâts." << std::endl;
}
