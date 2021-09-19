#ifndef MODULE00_WARLOCK_HPP
#define MODULE00_WARLOCK_HPP

#include <iostream>
#include "ASpell.h"
#include "ATarget.h"

using std::string;
using std::cout;
using std::endl;

class Warlock {
private:
    string name;
    string title;

    Warlock();
    Warlock(Warlock const &warlock);
    Warlock& operator=(const Warlock &warlock);

    std::vector<ASpell *> arr;

public:
    ~Warlock();
    Warlock(string name, string title);

    void introduce() const;

    const string &getName() const;

    const string &getTitle() const;

    void setTitle(const string &title);

    void learnSpell(ASpell &aSpell);
};

#endif
