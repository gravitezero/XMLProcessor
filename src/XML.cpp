#include "XML.h"
#include "VisitorInterface.hpp"




XML::XML()
{
	//TODO
}

XML::~XML()
{
	//TODO
}
	

void XML::addElement(Element* e)
{
    elements.push_back(e);
}

void XML::accept(VisitorInterface * visitor)
{
    for(list<Element*> ::iterator it = elements.begin(); it != elements.end(); ++it)
    {
        (*it)->accept(visitor);
    }

}
