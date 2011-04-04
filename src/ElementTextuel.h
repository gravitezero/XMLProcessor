#ifndef ELEMENT_TEXTUEL_H
#define ELEMENT_TEXTUEL_H

#include <list>
#include <string.h>
#include "Element.h"

using namespace std;

class ElementTextuel : public Element{
	public:
	ElementTextuel();
	virtual ~ ElementTextuel();
	
	protected:
	string value;
	
};

#endif
