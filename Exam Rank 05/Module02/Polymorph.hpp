#ifndef MODULE02_POLYMORPH_HPP
#define MODULE02_POLYMORPH_HPP

#include "ASpell.hpp"

class Polymorph : public ASpell {
private:
    string name;
    string effects;

public:
    Polymorph();
    ~Polymorph();

    virtual ASpell * clone() const;
};

#endif
