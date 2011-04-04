#ifndef ELEMENT_COMPLEXE_H
#define ELEMENT_COMPLEXE_H

#include <list>
#include "Element.h"

using namespace std;

class ElementComplexe : public Element
{
	public:
	ElementComplexe();
	virtual ~ ElementComplexe();
	
	protected:
	list<Element*> elementsList;
	
};

#endif
