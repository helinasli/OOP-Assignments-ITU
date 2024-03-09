#include <pokemon.h>

class PsychicPokemon : public Pokemon
{
public:
    PsychicPokemon(std::string, int, int);
    ~PsychicPokemon();
    void attack(Pokemon *);
};
