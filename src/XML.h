#ifndef XML_H
#define XML_H

#include "Element.hpp"
#include <list>


using namespace std;

class VisitorInterface;

class XML{
	public :
	XML();
	virtual ~XML();
        void addElement(Element*);
        void accept(VisitorInterface * visitor);

	private:
        list<Element*> elements;
	
	
};

#endif
