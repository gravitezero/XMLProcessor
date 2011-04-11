#ifndef ELEMENT_COMPLEXE_H
#define ELEMENT_COMPLEXE_H

#include <list>
#include "Element.hpp"
#include "commun.h"

using namespace std;

class ElementComplexe : public Element
{
	public:
        ElementComplexe(ElementName);
	ElementComplexe(std::string n, AttList a, list<Element *> *e);
	virtual ~ ElementComplexe();

        ElementName getElementName();
        AttList getAttList();
        list<Element*> getElements();
        void addAttribute(Attribut);
        void accept(VisitorInterface*);
        void addElement(Element*);
	protected:
        AttList attlist;
        ElementName elementName;
	list<Element*> elementsList;



	
};

#endif
