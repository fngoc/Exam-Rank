#ifndef MODULE00_WARLOCK_HPP
#define MODULE00_WARLOCK_HPP

#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

using std::string;
using std::cout;
using std::endl;
using std::vector;

class Warlock {
private:
    string name;
    string title;
    SpellBook spellBook;

    Warlock();
    Warlock(const Warlock &warlock);
    Warlock& operator=(const Warlock &warlock);

public:
    ~Warlock();
    Warlock(string name, string title);

    void introduce() const;

    const string &getName() const;
    const string &getTitle() const;
    void setTitle(const string &title);

    void learnSpell(ASpell *aSpell);
    void forgetSpell(string nameSpell);
    void launchSpell(string nameSpell, ATarget &aTarget);
};

#endif
