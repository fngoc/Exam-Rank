#include "Warlock.hpp"

Warlock::~Warlock() { cout << name << ": " << "My job here is done!" << endl; }

Warlock::Warlock(string name, string title) : name(name), title(title) { cout << name << ": " << "This looks like another boring day." << endl; }

void Warlock::introduce() const { cout << this->name << ": " << "I am " << this->name << "," << this->title << "!" << endl; }

const string &Warlock::getName() const { return name; }

const string &Warlock::getTitle() const { return title; }

void Warlock::setTitle(const string &title) { Warlock::title = title; }

void Warlock::learnSpell(ASpell *aSpell) {
    std::vector<ASpell *>::iterator it_begin = this->arr.begin();
    std::vector<ASpell *>::iterator it_end = this->arr.end();

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

void Warlock::forgetSpell(string nameSpell) {
    std::vector<ASpell *>::iterator it_begin = this->arr.begin();
    std::vector<ASpell *>::iterator it_end = this->arr.end();

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

void Warlock::launchSpell(string nameSpell, ATarget &aTarget) {
    std::vector<ASpell *>::iterator it_begin = this->arr.begin();
    std::vector<ASpell *>::iterator it_end = this->arr.end();

    while (it_begin != it_end)
    {
        if ((*it_begin)->getName() == nameSpell)
        {
            (*it_begin)->launch(aTarget);
            return ;
        }
        ++it_begin;
    }
}
