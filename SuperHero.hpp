#pragma once
#include <string>
#include <iostream>

// Classe abstraite SuperHero, base pour tous les super-héros
class SuperHero
{
protected:
    std::string name;      // Nom du super-héros
    int health;            // Points de vie du super-héros
    int attackPower;       // Puissance d'attaque de base du super-héros
    bool specialAvailable; // Indique si la capacité spéciale est disponible

public:
    // Constructeur : initialise le nom, les points de vie et la puissance d'attaque
    SuperHero(const std::string &name, int hp, int baseAttack);

    // Destructeur virtuel : permet une destruction correcte lors de l'héritage
    virtual ~SuperHero();

    // Getters
    std::string getName() const;
    int getHealth() const;
    int getAttack() const;
    bool isSpecialAvailable() const;

    virtual void displayInfo() const;
    virtual void attack(SuperHero &target) = 0;
    virtual void useSpecialAbility(SuperHero &target) = 0;
    bool isAlive() const;
    void takeDamage(int amount);
    void restoreHealth(int amount);

    // Setters
    void setName(const std::string &newName);
    void setHealth(int newHealth);
    void setAttack(int newAttack);
    void setSpecialAvailable(bool available);
};