#include "XMLDocument.h"
#include "VisitorInterface.hpp"
#include <cstdio>



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

void XMLDocument::setHeader(list<Declaration *> *l)
{
	header = l;
}
