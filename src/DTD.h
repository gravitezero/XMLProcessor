// include Système
#include<list>

// include perso
#include"DeclarationElement.h"
#include"DeclarationAttribut.h"

using namespace std;

typedef list<DeclarationElement*> Elements;
typedef list<DeclarationAttribut*> Attributs;
class VisitorInterface;

class DTD 
{
	public:
	DTD();
        DTD(Elements declarationElements, Attributs declarationAttributs);
	virtual ~DTD();
        void addDeclarationElement(DeclarationElement*);
        void addDeclarationAttributs(DeclarationAttribut*);
        void accept(VisitorInterface * visitor);


	protected:
	Elements declarationElements;
	Attributs declarationAttributs;
};
