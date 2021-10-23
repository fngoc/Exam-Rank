#include "SpellBook.hpp"

SpellBook::SpellBook() { }

SpellBook::~SpellBook() { }

void SpellBook::learnSpell(ASpell* aSpell) {
    vector<ASpell *>::iterator it_begin = this->arr.begin();
    vector<ASpell *>::iterator it_end = this->arr.end();

    if (aSpell)
    {
        while (it_begin != it_end)
        {
            if ((*it_begin)->getName() == aSpell->getName())
                return ;
            ++it_begin;
        }
        this->arr.push_back(aSpell->clone());
    }
}

void SpellBook::forgetSpell(const string &nameSpell) {
    vector<ASpell *>::iterator it_begin = this->arr.begin();
    vector<ASpell *>::iterator it_end = this->arr.end();

    while (it_begin != it_end)
    {
        if ((*it_begin)->getName() == nameSpell)
        {
            delete *it_begin;
            this->arr.erase(it_begin);
            return ;
        }
        ++it_begin;
    }
}

ASpell *SpellBook::createSpell(const string &nameSpell) {
    vector<ASpell *>::iterator it_begin = this->arr.begin();
    vector<ASpell *>::iterator it_end = this->arr.end();

    while (it_begin != it_end)
    {
        if ((*it_begin)->getName() == nameSpell)
            return (*it_begin);
        ++it_begin;
    }
    return (NULL);
}
