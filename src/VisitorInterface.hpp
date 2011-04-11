#ifndef VISITOR_INTERFACE
#define VISITOR_INTERFACE


class ElementTextuel;
class ElementComplexe;
class DeclarationElement;
class DeclarationAttribut;

class VisitorInterface{
	
	public:

        virtual void visit(ElementTextuel* elementTextuel) = 0;
        virtual void visit(ElementComplexe* elementComplexe) = 0;
        virtual void visit(DeclarationElement* declarationElement) = 0;
        virtual void visit(DeclarationAttribut* declarationAttribut) = 0;
	
	
};

#endif
