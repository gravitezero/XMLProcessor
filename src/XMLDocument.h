#ifndef XMLDOCUMENT_H
#define XMLDOCUMENT_H

#include "Element.hpp"
#include "Declaration.h"
#include <list>



using namespace std;

class VisitorInterface;

class XMLDocument{
public :
	XMLDocument();
	virtual ~XMLDocument();
        void setElement(Element *);
	void setHeader(list<Declaration *> *l);
        void accept(VisitorInterface * visitor);
private:
        Element *element;
	list<Declaration *> *header;
	
	
};

#endif
