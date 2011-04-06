#include<list>

#include"Contenu.h"

using namespace std;

class ContenuSequence : public Contenu
{
	public:
	ContenuSequence(list<Contenu> * contents);
	virtual ~ContenuSequence(list<Contenu> * contents);
	
	protected:
	list<Contenu> * contenus; 

};
