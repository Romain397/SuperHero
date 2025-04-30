#include "SuperHero.hpp"

class Hulk : public SuperHero
{
private:
    int rageMode;

public:
    Hulk(const std::string &name, int health, int attackPower);
    void useSpecialAbility(SuperHero &target);
    void attack(SuperHero &target);
};