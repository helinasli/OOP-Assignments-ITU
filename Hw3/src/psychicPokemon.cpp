#include <psychicPokemon.h>

PsychicPokemon::PsychicPokemon(std::string name, int hp, int damage) : Pokemon(name, hp, damage)
{
    this->setPowerUpChange(30);
    this->setRecharge(5);
    this->setConfusion(false);
}

PsychicPokemon::~PsychicPokemon() {}

void PsychicPokemon::attack(Pokemon *pokemon)
{
    int dmg = this->getDamage();

    // TERRAIN BUFF CHECK
    if (this->isInOwnTerrain())
    {
        dmg = dmg * 2;
    }
    // POWER UP CHECK
    if (this->isInPowerUp())
    {
        // ENEMY TERRAIN BUFF CHECK
        if (pokemon->isInOwnTerrain()) // ELECTRIC IMMUNE TO CONFUSION
        {
            pokemon->setConfusion(false);
        }
        else
        {
            pokemon->setConfusion(true);
        }
    }

    // DAMAGE DEALING
    pokemon->setHp(dmg);
}