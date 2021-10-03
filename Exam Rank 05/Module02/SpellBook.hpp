#ifndef MODULE02_SPELLBOOK_HPP
#define MODULE02_SPELLBOOK_HPP

#include <vector>
#include "ASpell.hpp"

using std::vector;

class SpellBook {
private:
    vector<ASpell *> arr;

    SpellBook(const SpellBook &spellBook);
    SpellBook& operator=(const SpellBook &newSpellBook);

public:
    SpellBook();
    ~SpellBook();

    void learnSpell(ASpell*);
    void forgetSpell(string const &);
    ASpell* createSpell(string const &);
};

#endif
