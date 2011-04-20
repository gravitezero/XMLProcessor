#include "XMLDocument.h"
#include "VisitorInterface.hpp"




XMLDocument::XMLDocument()
{
	//TODO
}

XMLDocument::~XMLDocument()
{
	//TODO
}
	

void XMLDocument::setElement(Element *e)
{
    element = e;
}

void XMLDocument::accept(VisitorInterface * visitor)
{
	element->accept(visitor);
}

std::string XMLDocument::build(VisitorInterface * visitor)
{
        return element->build(visitor);
}

void XMLDocument::setHeader(list<Declaration *> *l)
{
	header = l;
}
