#include "SuperHero.hpp"

class DoctorStrange : public SuperHero
{
public: // constructeur
    DoctorStrange(const std::string &name, int health, int attackPower);
    void useSpecialAbility(SuperHero &target);
    void attack(SuperHero &target);
};
