#include<string>
#include<list>

using namespace std;

typedef pair<string,string> Attribut;


class DeclarationAtt
{
	public:
	DeclarationAtt(char * elmt, list<Attribut> * attributs);
	virtual ~DeclarationAtt();


	protected:
	string nomElement;
	list<Attribut> * attributs;


};
