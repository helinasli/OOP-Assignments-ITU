#include <string>
#pragma once

class Pokemon
{
public:
    Pokemon(std::string, int, int);
    ~Pokemon();

    std::string getName() const;
    int getHp() const;
    int getDamage() const;
    int getPowerUpChance() const;
    int getRecharge() const;
    bool isFainted() const;
    bool isInPowerUp() const;
    bool isInOwnTerrain() const;
    bool getConfusion() const;

    void setHp(int);
    void setConfusion(bool);
    void setPowerUpChange(int);
    void setRecharge(int);
    void updateFaint(bool);
    void updatePowerUp(bool);
    void updateTerrain(bool);

private:
    std::string name;
    int hp;
    int damage;
    int powerUpChance;
    int recharge;

    bool faintState;
    bool powerUpState;
    bool terrainState;
    bool isConfused;
};
