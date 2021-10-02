#ifndef MODULE02_FIREBALL_HPP
#define MODULE02_FIREBALL_HPP

#include "ASpell.hpp"

class Fireball : public ASpell {
private:
    string name;
    string effects;

public:
    Fireball();
    ~Fireball();

    virtual ASpell * clone() const;
};

#endif
