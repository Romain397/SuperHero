#include "IronMan.hpp"

// Constructeur et initialisation du cooldown d'attaque spécial
IronMan::IronMan(const std::string &name, int health, int attackPower)
    : SuperHero(name, health, attackPower), cooldown(0) {}

// Attaque spécial de IronMan
void IronMan::useSpecialAbility(SuperHero &target)
{
    if (cooldown == 0) // Si cooldwon = 0 IronMan peut utiliser son attaque spécial
    {
        target.takeDamage(15); // Inflige 15 points de dégâts à la cible
        cooldown = 2;          // Active le cooldown pour 2 tours
        std::cout << getName() << " déclenche une salve de missiles sur " << target.getName() << "!" << std::endl;
    }
    else
    {
        // Si cooldown != 0 le message s'affiche
        std::cout << getName() << " ne peut pas utiliser sa capacité spéciale, cooldown restant : " << cooldown << std::endl;
    }
}

// Attaque Ironman
void IronMan::attack(SuperHero &target)
{
    target.takeDamage(getAttack()); // Inflige des dégâts à la cible basés sur l'attaque d'Iron Man
    if (cooldown > 0)
    {
        cooldown--; // Réduit le cooldown de 1 à chaque attaque
    }
}
