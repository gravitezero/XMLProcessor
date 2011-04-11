#include<string>
#include<list>

#include"Contenu.h"

using namespace std;


class DeclarationElt 
{
	public:
	DeclarationElt(char* nomElt, list<Contenu> * contents);
	virtual ~DeclarationElt(char* nomElt, list<Contenu> * contents);

	protected:
	list<Contenu> * contenus;
	string nomElement; 
	
};
