#ifndef MODULE01_ASPELL_HPP
#define MODULE01_ASPELL_HPP

#include <iostream>
#include "ATarget.hpp"

class ATarget;

using std::string;
using std::cout;
using std::endl;

class ASpell {
private:
    string name;
    string effects;

public:
    ASpell();
    virtual ~ASpell();
    ASpell(ASpell const &aSpell);
    ASpell& operator=(const ASpell &aSpell);

    ASpell(string name, string effects);

    virtual ASpell *clone() const = 0;

    const string &getName() const;

    const string &getEffects() const;

    void launch(ATarget& aTarget) const;
};

#endif
