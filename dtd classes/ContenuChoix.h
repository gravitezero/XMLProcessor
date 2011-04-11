#include<list>

#include"Contenu.h"

using namespace std;

class ContenuChoix: public Contenu
{
	public:
	ContenuChoix(list<Contenu> * contents);
	virtual ~ContenuChoix(list<Contenu> * contents);
	
	protected:
	list<Contenu> * contenus; 

};
