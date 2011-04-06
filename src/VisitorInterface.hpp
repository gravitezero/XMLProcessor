#ifndef VISITOR_INTERFACE
#define VISITOR_INTERFACE
//#include "ElementTextuel.h"
//#include "ElementComplexe.h"

class ElementTextuel;
class ElementComplexe;

class VisitorInterface{
	
	public:

        virtual void visit(ElementTextuel* elementTextuel) = 0;
        virtual void visit(ElementComplexe* elementComplexe) = 0;
	
	
};

#endif
