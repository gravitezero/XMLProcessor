// include Système
#include<list>

// include perso
#include"DeclarationElement.h"
#include"DeclarationAttribut.h"

using namespace std;

typedef list<DeclarationElement*> Elements;
typedef list<DeclarationAttribut*> Attributs;

class DTD 
{
	public:
	DTD();
	virtual ~DTD();
	
	protected:
	Elements declarationElements;
	Attributs declarationAttributs;
};
