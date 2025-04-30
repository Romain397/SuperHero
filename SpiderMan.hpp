#include "SuperHero.hpp"

class SpiderMan : public SuperHero
{
public:
    SpiderMan(const std::string &name, int health, int attackPower);
    void useSpecialAbility(SuperHero &target);
    void attack(SuperHero &target);
};
