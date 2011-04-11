#include<string>
#include<list>

//#include"Contenu.h"

using namespace std;

class Contenu;
class VisitorInterface;

class DeclarationElement 
{
	public:
	DeclarationElement();
        DeclarationElement(string nomElt, list<Contenu*>  contents);
	virtual ~DeclarationElement();
        void accept(VisitorInterface*);
        string getElementName();
        list<Contenu*> getContents();

	protected:
	list<Contenu*> contenus;
	string nomElement; 
	
};
