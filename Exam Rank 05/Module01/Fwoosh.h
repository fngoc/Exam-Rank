#ifndef MODULE01_FWOOSH_H
#define MODULE01_FWOOSH_H

#include "ASpell.h"

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
