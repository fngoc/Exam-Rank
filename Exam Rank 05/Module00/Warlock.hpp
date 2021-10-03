#ifndef MODULE00_WARLOCK_HPP
#define MODULE00_WARLOCK_HPP

#include <iostream>

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

public:
    ~Warlock();
    Warlock(string name, string title);

    void introduce() const;

    const string &getName() const;
    const string &getTitle() const;
    void setTitle(const string &title);
};

#endif
