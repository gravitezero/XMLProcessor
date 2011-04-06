#ifndef VISITOR_DISPLAY_H
#define VISITOR_DISPLAY_H



#include "VisitorInterface.hpp"

using namespace std;

class VisitorDisplay : public VisitorInterface{
	public:
	VisitorDisplay();
	virtual ~ VisitorDisplay();
	void visit(ElementTextuel* elementTextuel);
	void visit(ElementComplexe* elementComplexe);
	


	
};

#endif
