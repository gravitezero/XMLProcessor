#ifndef XML_H
#define XML_H

#include "Element.h"
#include "Declaration.h"
#include <list>


using namespace std;

class XMLDocument
{
public :
	XMLDocument();
	virtual ~XMLDocument();
	void setElement(Element *e);
	void setHeader(list<Declaration *> *l);
private:
        Element *element;
	list<Declaration *> *header;
	
};

#endif
