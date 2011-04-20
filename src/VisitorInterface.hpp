#ifndef VISITOR_INTERFACE
#define VISITOR_INTERFACE

#include <string>

class ElementTextuel;
class ElementComplexe;
class DeclarationElement;
class DeclarationAttribut;
class ContenuSimple;
class ContenuChoix;
class ContenuSequence;

class VisitorInterface{
	
	public:

        virtual void visit(ElementTextuel* elementTextuel) = 0;
        virtual void visit(ElementComplexe* elementComplexe) = 0;
        virtual std::string build(DeclarationElement* ) = 0;
        virtual std::string build(DeclarationAttribut* ) = 0;
        virtual std::string build(ContenuSimple*) = 0;
        virtual std::string build(ContenuChoix*) = 0;
        virtual std::string build(ContenuSequence*) = 0;
        virtual std::string build(ElementTextuel* elementTextuel) = 0;
        virtual std::string build(ElementComplexe* elementComplexe) = 0;

	
	
};

#endif
