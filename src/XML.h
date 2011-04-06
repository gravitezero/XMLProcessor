#ifndef XML_H
#define XML_H

#include "Element.hpp"
#include <list>


using namespace std;

class XML{
	public :
	XML();
	virtual ~XML();
	
	private:
        list<Element*> elements;
	
	
};

#endif
