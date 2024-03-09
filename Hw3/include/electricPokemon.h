#include <pokemon.h>

class ElectricPokemon : public Pokemon
{
public:
    ElectricPokemon(std::string, int, int);
    ~ElectricPokemon();
    void attack(Pokemon *);
};
