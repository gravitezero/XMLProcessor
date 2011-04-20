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
        virtual std::string build(ElementTextuel* elementTextuel) ;
        virtual std::string build(ElementComplexe* elementComplexe) ;
        std::string build(DeclarationElement* declarationElement);
        std::string build(DeclarationAttribut* declarationAttribut);
        std::string build(ContenuSimple*);
        std::string build(ContenuChoix*);
        std::string build(ContenuSequence*);


	
};

#endif
