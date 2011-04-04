#include<string>
#include<list>

using namespace std;

typedef pair<string,string> Attribut;


class DeclarationAttribut
{
	public:
	DeclarationAttribut();
	virtual ~DeclarationAttribut();


	protected:
	string nomAttribut;
	list<Attribut*> attributs;


};
