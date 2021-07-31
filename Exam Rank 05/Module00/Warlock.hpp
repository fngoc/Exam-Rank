#ifndef MODULE00_WARLOCK_HPP
#define MODULE00_WARLOCK_HPP

#include <iostream>

using  std::string;
using  std::cout;
using  std::endl;

class Warlock {
private:
	string name;
	string title;

	Warlock();
	Warlock(Warlock& warlock);
	Warlock& operator=(Warlock& warlock);

public:
	virtual ~Warlock();
	Warlock(const string &name, const string &title);

	const string &getName() const;
	const string &getTitle() const;
	void setTitle(const string &title);

	void introduce() const;

};


#endif
