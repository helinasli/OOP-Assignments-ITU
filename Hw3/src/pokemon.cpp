#include <pokemon.h>

Pokemon::Pokemon(std::string name, int hp, int damage)
{
    this->name = name;
    this->hp = hp;
    this->damage = damage;
    this->faintState = false;
    this->powerUpState = false;
    this->terrainState = false;
}

Pokemon::~Pokemon(){};

std::string Pokemon::getName() const
{
    return this->name;
}

int Pokemon::getHp() const
{
    return this->hp;
}

int Pokemon::getDamage() const
{
    return this->damage;
}

int Pokemon::getPowerUpChance() const
{
    return this->powerUpChance;
}

int Pokemon::getRecharge() const
{
    return this->recharge;
}

bool Pokemon::isFainted() const
{
    return this->faintState;
}
bool Pokemon::isInPowerUp() const
{
    return this->powerUpState;
}
bool Pokemon::isInOwnTerrain() const
{
    return this->terrainState;
}

void Pokemon::setHp(int damaged)
{
    if (this->hp - damaged <= 0)
    {
        this->hp = 0;
        this->faintState = true;
    }
    else
    {
        this->hp = this->hp - damaged;
    }
}

void Pokemon::setPowerUpChange(int powerUpChance)
{
    this->powerUpChance = powerUpChance;
}

void Pokemon::setRecharge(int recharge)
{
    this->recharge = recharge;
}

void Pokemon::updateFaint(bool b)
{
    this->faintState = b;
}

void Pokemon::updatePowerUp(bool b)
{
    this->powerUpState = b;
}

void Pokemon::updateTerrain(bool b)
{
    this->terrainState = b;
}

void Pokemon::setConfusion(bool b)
{
    this->isConfused = b;
}
bool Pokemon::getConfusion() const
{
    return this->isConfused;
}
