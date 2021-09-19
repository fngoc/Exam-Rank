#ifndef MODULE01_ATARGET_H
#define MODULE01_ATARGET_H

#include <iostream>

class ASpell;

using std::string;
using std::cout;
using std::endl;

class ATarget {
private:
    string type;
public:
    const string &getType() const;

public:
    ATarget();
    virtual ~ATarget();
    ATarget(ATarget const &aTarget);
    ATarget& operator=(const ATarget &aTarget);

    ATarget(string &type);

    void getHitBySpell(const ASpell& aSpell) const;

    virtual ATarget *clone() const = 0;
};


#endif
