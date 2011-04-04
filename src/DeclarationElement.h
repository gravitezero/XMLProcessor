#include<string>
#include<list>

#include"Contenu.h"

using namespace std;


class DeclarationElement 
{
	public:
	DeclarationElement();
	virtual ~DeclarationElement();

	protected:
	list<Contenu*> contenus;
	string nomElement; 
	
};
