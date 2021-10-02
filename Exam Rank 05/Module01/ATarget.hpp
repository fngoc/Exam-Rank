#ifndef MODULE01_ATARGET_HPP
#define MODULE01_ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class ASpell;

using std::string;
using std::cout;
using std::endl;

class ATarget {
private:
    string type;

public:
    ATarget();
    virtual ~ATarget();
    ATarget(ATarget const &aTarget);
    ATarget& operator=(const ATarget &aTarget);

    ATarget(string type);

    void getHitBySpell(const ASpell& aSpell) const;

    virtual ATarget *clone() const = 0;

    const string &getType() const;
};

#endif
