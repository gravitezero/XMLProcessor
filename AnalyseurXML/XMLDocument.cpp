#include "XMLDocument.h"


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

void XMLDocument::setHeader(list<Declaration *> *l)
{
	header = l;
}
