#include <iostream>
#include <arena.h>

Arena::Arena()
{
    this->psy = NULL;
    this->elc = NULL;
    this->terrain = "";
}

Arena::~Arena() {}

void Arena::addPokemon(char type, std::string name, int hp, int damage)
{
    if (type == 'e')
    {
        ElectricPokemon *elc = new ElectricPokemon(name, hp, damage);
        this->elc = elc;
        std::cout << "Electric Pokemon " << name << " has entered the arena." << std::endl
                  << "Class : Electric" << std::endl
                  << "Name : " << name << std::endl
                  << "HP : " << hp << std::endl
                  << "Damage : " << damage << std::endl
                  << "" << std::endl;
    }
    else if (type == 'p')
    {
        PsychicPokemon *psy = new PsychicPokemon(name, hp, damage);
        this->psy = psy;
        std::cout << "Psychic Pokemon " << name << " has entered the arena." << std::endl
                  << "Class : Psychic" << std::endl
                  << "Name : " << name << std::endl
                  << "HP : " << hp << std::endl
                  << "Damage : " << damage << std::endl
                  << "" << std::endl;
    }
}

void Arena::spawnTerrain()
{

    int terrainChance = rand() % 5;
    if (terrainChance == 0)
    {
        this->terrain = "electric";
        this->elc->updateTerrain(true);
        this->psy->updateTerrain(false);
    }
    else if (terrainChance == 1)
    {
        this->terrain = "psychic";
        this->psy->updateTerrain(true);
        this->elc->updateTerrain(false);
    }
    else
    {
        this->terrain = "none";
        this->psy->updateTerrain(false);
        this->elc->updateTerrain(false);
    }
}

void Arena::restartTerrain()
{
    spawnTerrain();
}

void Arena::simulateBattle()
{
    int round = 0;
    int elcPowerUpRound = 0;
    int psyPowerUpRound = 0;

    while (true)
    {
        int powerUp = 0;
        if (round == 0)
        {
            spawnTerrain();
        }

        // HEADS HANDLE
        int heads = rand() % 2;

        // POWERUP HANDLE
        int psyChance = 1 + (rand() % 100);
        int elcChance = 1 + (rand() % 100);

        // PSY POWER UP HANDLING
        if (psyChance <= this->psy->getPowerUpChance() && round - psyPowerUpRound > this->psy->getRecharge())
        {
            this->psy->updatePowerUp(true);
            psyPowerUpRound = round;
            powerUp = 1;
        }
        else if (!(psyChance <= this->psy->getPowerUpChance()) && round - psyPowerUpRound > this->psy->getRecharge())
        {
            this->psy->updatePowerUp(false);
        }

        // ELC POWER UP HANDLING
        if (elcChance <= this->elc->getPowerUpChance() && round - elcPowerUpRound > this->elc->getRecharge())
        {
            this->elc->updatePowerUp(true);
            elcPowerUpRound = round;
            powerUp = 2;
        }
        else if (!(elcChance <= this->elc->getPowerUpChance()) && round - elcPowerUpRound > this->elc->getRecharge())
        {
            this->elc->updatePowerUp(false);
        }

        if (this->elc->isInPowerUp() && this->psy->isInPowerUp())
        {
            powerUp = 3;
        }

        // TERRAIN HANDLE
        if (round % 5 == 0 || this->terrain == "none")
        {
            restartTerrain();
        }

        // FIGHT
        // if n = 0 attack psychic pokemon
        if (heads == 0)
        {
            this->psy->attack(this->elc);
            if (this->elc->isFainted())
            {
                this->printRoundStats(round + 1, heads, powerUp);
                this->printMatchResults(this->psy->getName());
                break;
            }
            this->elc->attack(this->psy);
            if (this->psy->isFainted())
            {
                this->printRoundStats(round + 1, heads, powerUp);
                this->printMatchResults(this->elc->getName());
                break;
            }
        }
        else
        {
            this->elc->attack(this->psy);
            if (this->psy->isFainted())
            {
                this->printRoundStats(round + 1, heads, powerUp);
                this->printMatchResults(this->elc->getName());
                break;
            }
            this->psy->attack(this->elc);
            if (this->elc->isFainted())
            {
                this->printRoundStats(round + 1, heads, powerUp);
                this->printMatchResults(this->psy->getName());
                break;
            }
        }

        this->elc->updatePowerUp(false);
        this->psy->updatePowerUp(false);

        // PRINT ROUND STATS
        this->printRoundStats(round + 1, heads, powerUp);
        round++;
    }
}

void Arena::printRoundStats(int round, int heads, int powerUp) const
{
    std::string output = "";

    // Head selection
    if (heads == 0)
    {
        output = this->psy->getName();
    }
    else
    {
        output = this->elc->getName();
    }

    std::cout << "Round: " << round << std::endl
              << "Current Terrain: " << this->terrain << std::endl
              << output << " goes first." << std::endl;
    if (powerUp == 1)
    {
        std::cout << this->psy->getName() << " has initiated a power up." << std::endl;
    }
    else if (powerUp == 2)
    {
        std::cout << this->elc->getName() << " has initiated a power up." << std::endl;
    }
    else if (powerUp == 3)
    {
        std::cout << this->psy->getName() << " has initiated a power up." << std::endl;
        std::cout << this->elc->getName() << " has initiated a power up." << std::endl;
    }

    std::cout << this->elc->getName() << " HP : " << this->elc->getHp() << std::endl
              << this->psy->getName() << " HP : " << this->psy->getHp() << std::endl;

    // Leader selection
    if (this->elc->getHp() > this->psy->getHp())
    {
        std::cout << this->elc->getName() << " is in the lead!" << std::endl;
    }
    else if (this->elc->getHp() < this->psy->getHp())
    {
        std::cout << this->psy->getName() << " is in the lead!" << std::endl;
    }
    else
    {
        std::cout << "Pokemons are on equal HP" << std::endl;
    }
    std::cout << std::endl
              << std::endl;
}

void Arena::printMatchResults(std::string name) const
{
    std::cout << "Match Results:" << std::endl
              << name << " has won the match! " << std::endl
              << std::endl;
}