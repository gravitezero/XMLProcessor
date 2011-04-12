#include "ElementComplexe.h"
#include "VisitorInterface.hpp"




ElementComplexe::ElementComplexe(ElementName *name)

{
	elementName = new ElementName(name->first,name->second);	
/*	elementName.first = name.first;
        elementName.second = name.second;*/
}

ElementComplexe::ElementComplexe(ElementName *n, AttList *a, list<Element *> *e)
{
	//TODO
}

ElementComplexe::~ElementComplexe()
{
	delete elementName;
}
	
/*Retourne le nom de l'élément
sous forme de pair<string, string>
ex : pour un élément tel que <"ns":"name" > elle retourne <ns,name>
   ou
  pour un élément <"":"name" > elle retourne <,name>
*/
ElementName *ElementComplexe::getElementName()
{
    return elementName;
}

AttList *ElementComplexe::getAttList()
{
    return attlist;
}

//Retourne les éléments fils
list<Element*> *ElementComplexe::getElements()
{
    return elementsList;
}


void ElementComplexe::accept(VisitorInterface * visitor)
{
    visitor->visit(this);
}

void ElementComplexe::addElement(Element* e)
{
    elementsList->push_back(e);
}

void ElementComplexe::addAttribute(Attribut *a)
{
    attlist->push_back(a);
}
