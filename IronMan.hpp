#include "SuperHero.hpp"

class IronMan : public SuperHero
{
private:
    int cooldown;

public:
    IronMan(const std::string &name, int health, int attackPower);
    void useSpecialAbility(SuperHero &target);
    void attack(SuperHero &target);
};