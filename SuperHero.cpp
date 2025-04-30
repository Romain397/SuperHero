#include "SuperHero.hpp"

// Constructeur de la classe SuperHero
SuperHero::SuperHero(const std::string &name, int hp, int baseAttack)
    : name(name), health(hp), attackPower(baseAttack), specialAvailable(false) {} // Initialisation des membres avec les valeurs fournies

// Destructeur virtuel de la classe SuperHero
SuperHero::~SuperHero() {}

// Getter
std::string SuperHero::getName() const { return name; }
int SuperHero::getHealth() const { return health; }
int SuperHero::getAttack() const { return attackPower; }
bool SuperHero::isSpecialAvailable() const { return specialAvailable; }

// Affiche les infos du héros
void SuperHero::displayInfo() const
{
    std::cout << "Nom: " << name << ", PV: " << health << ", Capacité spéciale disponible: " << (specialAvailable ? "Oui" : "Non") << std::endl;
}

// Vérification si le héros est en vie
bool SuperHero::isAlive() const { return health > 0; }

// Réduit les points de vie du super-héros
void SuperHero::takeDamage(int amount)
{
    health -= amount; // Réduit les points de vie par le montant spécifié
    if (health < 0)
    {
        health = 0;
    }
}

// Restaure les points de vie du super-héros
void SuperHero::restoreHealth(int amount)
{
    health += amount; // Augmente les points de vie par le montant spécifié amount
    if (health > 100)
    {
        health = 100; // Les points de vie ne peuvent pas dépasser 100
    }
}

// Setter
void SuperHero::setName(const std::string &newName) { name = newName; }
void SuperHero::setHealth(int newHealth) { health = newHealth; }
void SuperHero::setAttack(int newAttack) { attackPower = newAttack; }
void SuperHero::setSpecialAvailable(bool available) { specialAvailable = available; }