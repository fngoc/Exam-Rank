#include "Warlock.hpp"

Warlock::~Warlock() { cout << name << ": " << "My job here is done!" << endl; }

Warlock::Warlock(string name, string title) : name(name), title(title) { cout << name << ": " << "This looks like another boring day." << endl; }

void Warlock::introduce() const { cout << this->name << ": " << "I am " << this->name << "," << this->title << "!" << endl; }

const string &Warlock::getName() const { return name; }

const string &Warlock::getTitle() const { return title; }

void Warlock::setTitle(const string &title) { Warlock::title = title; }
