#include <electricPokemon.h>

ElectricPokemon::ElectricPokemon(std::string name, int hp, int damage) : Pokemon(name, hp, damage)
{
    this->setPowerUpChange(20);
    this->setRecharge(3);
    this->setConfusion(false);
}

void ElectricPokemon::attack(Pokemon *pokemon)
{
    int dmg = this->getDamage();

    // POWER UP CHECK
    if (this->isInPowerUp())
    {
        dmg = dmg * 3;
    }

    // CONFUSION CHECK
    if (this->getConfusion())
    {
        dmg = 0;
    }
    // DAMAGE DEALING
    pokemon->setHp(dmg);
}

ElectricPokemon::~ElectricPokemon() {}