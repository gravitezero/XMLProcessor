#ifndef ELEMENT_TEXTUEL_H
#define ELEMENT_TEXTUEL_H

#include <list>
#include <string.h>
#include "Element.hpp"

using namespace std;

class ElementTextuel : public Element{
	public:
        ElementTextuel(string);
	virtual ~ ElementTextuel();

        string getValue();
        void accept(VisitorInterface*);
        string build(VisitorInterface*);

	protected:
	string value;
	
};

#endif
