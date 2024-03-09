#include <string>
#include <electricPokemon.h>
#include <psychicPokemon.h>

class Arena
{
public:
    Arena();
    ~Arena();

    void addPokemon(char, std::string, int, int);
    void simulateBattle();
    void spawnTerrain();
    void restartTerrain();
    void printRoundStats(int, int, int) const;
    void printMatchResults(std::string) const;

private:
    PsychicPokemon *psy;
    ElectricPokemon *elc;
    std::string terrain;
};
