#ifndef MODULE01_FWOOSH_HPP
#define MODULE01_FWOOSH_HPP

#include "ASpell.hpp"

class Fwoosh : public ASpell {
private:
    string name;
    string effects;

public:
    Fwoosh();
    ~Fwoosh();

    virtual ASpell * clone() const;

};


#endif
