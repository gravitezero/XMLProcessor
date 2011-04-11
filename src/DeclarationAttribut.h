#include<string>
#include<list>

using namespace std;

typedef pair<string,string> Attribut;

class VisitorInterface;

class DeclarationAttribut
{
	public:
	DeclarationAttribut();
        DeclarationAttribut(string elmt, list<Attribut*>  attributs);
	virtual ~DeclarationAttribut();
        void accept(VisitorInterface*);
        string getName();
        list<Attribut*> getAttributes();

	protected:
	string nomAttribut;
	list<Attribut*> attributs;


};
