#include<list>

#include"Contenu.h"

using namespace std;

class ContenuSimple : public Contenu
{
	public:
	ContenuSimple(char * nom, DTD * dtd);
	virtual ~ContenuSimple(char * nom, DTD * dtd);
	
	protected:
	char * nom;
	DTD * dtd;

};
